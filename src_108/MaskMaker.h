/*
 * Class:   MaskMaker
 * Author:  Perry Barile
 *
 * The MaskMaker takes an input image and applies a simple convolution mask to
 * it in order to generate a simple black and white image that identifies
 * "interesting" regions.
 *
 */

#ifndef MASKMAKER_H
#define MASKMAKER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

#include "Utility.h"
#include "png.h"
#include "util.h"

class MaskMaker
{
private:
  RGB* source; // Source image file data
  RGB* output; // Output image data to be generated

  unsigned width, height, numPixels; // Dimensions
  unsigned threshold; // Applied to create a monochromatic image
  unsigned numConvolutions; // The number of convolutions to apply
    
  char outputPath[80]; // The path and name of the output file
    
  void convolve();
  RGB getRGB(unsigned x, unsigned y);
  char validChar(int n);
  void reduce();

public:
  MaskMaker(const char* sourceFile, const char* outputFile,
              unsigned T, unsigned N);
  ~MaskMaker();

  void makeDefaultMask();
};

#endif // MASKMAKER_H
