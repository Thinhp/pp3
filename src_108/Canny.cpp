/*
 * Class:  Canny
 * Author: Pasquale Barile
 *
 * See header file for details
 */

#include "Canny.h"

Canny::Canny(RGB* src, int width, int height, int t1, int t2, bool fuzzyEdges)
   : width(width), height(height), T1(t1), T2(t2)
{
  const int size = width * height;
   
  gradients = new RGB[size];
  tempBuffer = new RGB[size];
  directions = new float[size];
   
  for (int i = 0; i < size; i++)
  {
    gradients[i].r = src[i].r;
    gradients[i].g = src[i].r;
    gradients[i].b = src[i].r;
    /*
    gradients[i].r = 0;
    gradients[i].g = 0;
    gradients[i].b = 0;
    */
    tempBuffer[i].r = 0;
    tempBuffer[i].g = 0;
    tempBuffer[i].b = 0;
    directions[i] = 0.0f;
  }

  source = src;
   
	smooth();
	sobel();

	if (!fuzzyEdges)
	{
    suppress();
    hysteresis();
	}
}

Canny::~Canny()
{
  delete [] gradients;
  delete [] tempBuffer;
  delete [] directions;
}

/* Apply a 5x5 Gaussian mask with a sigma of 1.0
 * The entire image is filtered. If array indexes fall outside image boundaries,
 * they are succesively incremented/decremented until they fall inside the
 * boundaries.
 */
void Canny::smooth()
{
  int weights[] = {
    1,  4,  7,  4, 1,
    4, 16, 26, 16, 4,
    7, 26, 41, 26, 7,
    4, 16, 26, 16, 4,
    1,  4,  7,  4, 1
  };
  const int divisor = 273;

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      int sum = 0;
      int index = 0;
         
      for (int dy = -2; dy <= 2; dy++)
      {
        for (int dx = -2; dx <= 2; dx++)
        {
          int yy = y + dy;
               
          while (yy < 0)
            yy++;

          while (yy >= height)
            yy--;

          int xx = x + dx;
          
          while (xx < 0)
            xx++;

          while (xx >= width)
            xx--;

          color_t color = source[yy * width + xx].r;
          int colorInt = (int)color;
          colorInt *= weights[index++];
          sum += colorInt;
        }
      }
      sum /= divisor;
      if (sum > 255)
        sum = 255;

      gradients[y * width + x].r = (color_t)sum;
      gradients[y * width + x].g = (color_t)sum;
      gradients[y * width + x].b = (color_t)sum;
    }
  }
}

// Apply a Sobel edge detection filter
void Canny::sobel()
{
  // Copy the gradient data into a temporary buffer
  const int size = width * height;
  for (int i = 0; i < size; i++)
    tempBuffer[i] = gradients[i];

  int xWeights[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
  int yWeights[] = {1, 2, 1, 0, 0, 0, -1, -2, -1};

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      int index = 0;
      int gx = 0;
      int gy = 0;

      for (int dy = -1; dy <= 1; dy++)
      {
        for (int dx = -1; dx <= 1; dx++)
        {
          int yy = y + dy;
          if (yy < 0) { yy = 0; }
          if (yy == height) { yy--; }

          int xx = x + dx;
          if (xx < 0) { xx = 0; }
          if (xx == width) { xx--; }

          color_t color = tempBuffer[yy * width + xx].r;
          int colorInt = (int)color;
          int xInt = colorInt * xWeights[index];
          int yInt = colorInt * yWeights[index];
          index++;
          gx += xInt;
          gy += yInt;
        }
      }

      float gxx = (float)gx * (float)gx;
      float gyy = (float)gy * (float)gy;
      int gxy = (int)sqrt(gxx + gyy);
      gxy = std::min(gxy, 255);

      gradients[y * width + x].r = (color_t)gxy;
      gradients[y * width + x].g = (color_t)gxy;
      gradients[y * width + x].b = (color_t)gxy;

      // Compute angle of the gradient (in radians)
      float theta = 0.0f;

      if (gx == 0)
      {
        if (gy == 0)
          theta = 0.0f;
        else
          theta = M_PI / 2;
      }
      else
        theta = atan((float)gy / (float)gx);

      directions[y * width + x] = theta;
    }
  }
}

// Apply non-maximum suppression
// Suppress points perpendicular to edges
void Canny::suppress()
{
  // Copy the gradient data into a temporary buffer
  const int size = width * height;
  for (int i = 0; i < size; i++)
    tempBuffer[i] = gradients[i];

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      int offset = y * width + x;

      if (gradients[offset].r == 0) // Definitely not an edge
        continue;

      float T1 = M_PI * 0.125;
      float T2 = M_PI * 0.375;
      float T3 = M_PI * 0.625;
      float T4 = M_PI * 0.875;

      /*
       *    p3    p2    p1
       *    p4          p0
       *    p5    p6    p7
       */

      int p0 = offset + 1;
      int p1 = offset + 1 - width;
      int p2 = offset - width;
      int p3 = offset - 1 - width;
      int p4 = offset - 1;
      int p5 = offset - 1 + width;
      int p6 = offset + width;
      int p7 = offset + 1 + width;

      float theta = directions[offset];
      if (theta < 0) { theta *= -1; }

      int localMax = 0;

      if (theta <= T1)
        localMax = getMax(p0, p4);
      else if (theta <= T2)
        localMax = getMax(p1, p5);
      else if (theta <= T3)
        localMax = getMax(p2, p6);
      else if (theta <= T4)
        localMax = getMax(p3, p7);
      else
        localMax = getMax(p0, p4);

      if (tempBuffer[offset].r < localMax)
      {
        gradients[offset].r = 0;
        gradients[offset].g = 0;
        gradients[offset].b = 0;
      }
    }
  }
}

// Return a local maximum from a group of points
int Canny::getMax(int d0, int d1)
{
  int index[] = {d0, d1};

  int max = 0;
  const int size = width * height;

  for (int i = 0; i <= 1; i++)
  {
    // Don't exceed array bounds
    if (index[i] < 0 || index[i] >= size)
      continue;

    color_t local = tempBuffer[index[i]].r;
    if (local > max)
      max = local;
  }

  return max;
}

// Apply hysteresis
void Canny::hysteresis()
{
  const int size = width * height;

  for (int i = 0; i < size; i++)
  {
    tempBuffer[i] = gradients[i];
  }

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      color_t value = tempBuffer[y * width + x].r;
      if (value == 0)
        continue;
      else if (value < T1)
        tempBuffer[y * width + x].r = 0;
      else if (value >= T2)
      {
        tempBuffer[y * width + x].r = 255;
        connect(x, y);
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    if (tempBuffer[i].r == 255)
    {
      gradients[i].r = 255;
      gradients[i].g = 255;
      gradients[i].b = 255;
    }
    else
    {
      gradients[i].r = 0;
      gradients[i].g = 0;
      gradients[i].b = 0;
    }
  }
}

// Connect mid-range hysteresis values to high range values
void Canny::connect(int xx, int yy)
{
  for (int x = xx - 1; x <= xx + 1; x++)
  {
    for (int y = yy - 1; y <= yy + 1; y++)
    {
      if (x < width && y < height && x >= 0 && y >= 0 && x != xx && y != yy)
      {
        color_t value = tempBuffer[y * width + x].r;
        if (value != 255)
        {
          if (value >= T1)
          {
            tempBuffer[y * width + x].r = 255;
            connect(x, y);
          }
          else
          {
            tempBuffer[y * width + x].r = 0;
          }
        }
      }
    }
  }
}

// Save this object to a file
bool Canny::saveImage(std::string filename)
{
  assert(gradients);
  write_image(filename.c_str(), (color_t*)gradients, width, height);
  return true;
}

// Return the gradient value for a pixel
color_t Canny::gradient(Coord c)
{
  int offset = (int)c.y * width + (int)c.x;
  return gradients[offset].r;
}

// Return the direction value for a pixel
float Canny::angle(Coord c)
{
  int offset = (int)c.y * width + (int)c.x;
  return directions[offset];
}

