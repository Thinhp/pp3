/*
 * Class:   Target
 * Author:  Perry Barile
 *
 * See header file for details.
 *
 */

using namespace std;
#include "MaskMaker.h"

#include <cstring>


MaskMaker::MaskMaker(const char* sourceFile, const char* outputFile,
                     unsigned T, unsigned N):
    source(NULL), output(NULL), threshold(T), numConvolutions(N)
{
  read_image(sourceFile, (color_t**)&source, &width, &height);
  numPixels = width * height;
  const unsigned size = numPixels;
    
  strcpy(outputPath, outputFile);
    
  output = new RGB[size];
  RGB rgb = {255, 255, 255};
    
  for (unsigned i = 0; i < size; i++)
    output[i] = rgb;
}

MaskMaker::~MaskMaker()
{
  if (source != NULL)
    delete source;
    
  if (output != NULL)
    delete output;
}

void MaskMaker::makeDefaultMask()
{
  for (unsigned i = 0; i < numConvolutions; i++)
    convolve();
    
  reduce();
    
  write_image(outputPath, (color_t*)output, width, height);
}

/*
   Applies a convolution matrix to the entire pixel array. The matrix operates
   on the local Von Neumann neighbourhood, radius 1: i.e. the central pixel and
   the 4 pixels immediately north, south, east and west. Each R, G and B channel
   is treated separately. The value for the central pixel is multiplied by fpur
   and then the values for the neigbouring pixels are subtracted. The resultant
   values are then normalised to ensure that they fall within the valied 0-255
   region.
 */
void MaskMaker::convolve()
{
  for (unsigned y = 0; y < height; y++)
  {
    for (unsigned x = 0; x < width; x++)
    {
      RGB central = source[y * width + x];
      RGB north = getRGB(x, y - 1);
      RGB south = getRGB(x, y + 1);
      RGB east = getRGB(x + 1, y);
      RGB west = getRGB(x - 1, y);
            
      int r = 4 * central.r - north.r - south.r - east.r - west.r;
      int g = 4 * central.g - north.g - south.g - east.g - west.g;
      int b = 4 * central.b - north.b - south.b - east.b - west.b;
            
      char red = validChar(r);
      char green = validChar(g);
      char blue = validChar(b);
            
      RGB rgb = {red, green, blue};
            
      output[y * width + x] = rgb;
    }
  }
}

RGB MaskMaker::getRGB(unsigned x, unsigned y)
{
  if (x < 0 || y < 0 || x >= width || y >= height)
  {
    RGB ret = {255, 255, 255};
    return ret;
  }    
  return source[y * width + x];
}

char MaskMaker::validChar(int n)
{
  return (n < 0 ? 0 : (n > 255 ? 255 : (char)n));
}

/*
   Converts RGB data to binary (monochromatic data). Each RGB channel value is
   compared to a threshold. If any of those values are below the threshold, then
   the pixel is set to black. Otherwise it is set to white. The exact algorithm
   used here is not quite as efficient as this explanation might suggest, but
   it is left as is in order to allow experimentation. 
 */
void MaskMaker::reduce()
{
  for (unsigned y = 0; y < height; y++)
  {
    for (unsigned x = 0; x < width; x++)
    {
      RGB rgb = output[y * width + x];
      RGB out = {0, 0, 0};
            
      int sum = 0;
      sum += rgb.r < threshold ? 0 : 1;
      sum += rgb.g < threshold ? 0 : 1;
      sum += rgb.b < threshold ? 0 : 1;
        
      if (sum > 0)
      {
        out.r = 0;
        out.g = 0;
        out.b = 0;
      }
      else
      {
        out.r = 255;
        out.g = 255;
        out.b = 255;
      }
            
      output[y * width + x] = out;
    }
  }
}

