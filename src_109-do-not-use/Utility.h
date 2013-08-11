/*
 * Author:  Pasquale Barile
 *
 * This header file contains convenience typedefs and constants
 */

#ifndef UTILITY_H
#define UTILITY_H

#define DEBUG(x) cout << #x " = " << x << endl
#define TRACE(s) cerr << #s << endl, s

typedef struct {
  unsigned char r,g,b;
} RGB;

typedef struct {
  int h, s, v;
} HSV;

typedef struct {
  float x, y;
} Coord; // Used when we're interested in the coordinate of Pixel

enum HSV_CHANNEL { HUE, SAT, VAL };

// The number of grayscale colours
const int NUM_COLOURS = 256;

typedef unsigned char color_t;

const float PI = 3.14159265358;
const float TWO_PI = 6.28318530716;
const float ROOT2 = 1.41421356237;

#endif // UTILITY_H
