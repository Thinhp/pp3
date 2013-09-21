/*
 * Class:  Ellipse
 * Author: TanThinh
 * Date created: 16/9/2013
 *
 * See header file for details.
 *
 */

using namespace std;

#define GetMin(a,b) ((a) < (b) ? (a) : (b))
#define GetMax(a,b) ((a) > (b) ? (a) : (b))

#include "Ellipse.h"
#include "ConfigReader.h"
#include <cstring>

#include <math.h>
#include <vector>

//to implement Gray scale
Ellipse::Ellipse(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader)
: Canvas(t, bg, bc), reader(reader)
{
  const int size = getSize(); // Getsize() will return numPixels var
  ellipse = new RGB[size];
	flagDraw = true;
	horizontalLength = reader->getEllipseHorizontal();
	verticalLength = reader->getEllipseVertical();
}


//to implement Colorful scale - NOT YET
Ellipse::~Ellipse(){
	delete ellipse;
}

//apply paint
void Ellipse::paintCanvas(vector<float> v)
{

	if(reader->getColourMode())
	{
		//TODO - Implement some code here
	}
	else
	{
		const unsigned ARGS = 5;
		assert(v.size() == ARGS);

		// Set up the line color
		int gray = (int)(v.at(3) * 256);
		lineColor.r = gray;
		lineColor.g = gray;
		lineColor.b = gray;
	}

	// Increment the node count
	newNode();

	//Set up the start point
	int pixelIndex = (int)(v.at(0) * getSize());
	origin.x = (float)(pixelIndex % getWidth());
	origin.y = (float)(pixelIndex / getWidth());

	//Set up radius
	pi = v.at(1) *  PI;

	//Set default to have horizontal = 5
	horizontal = v.at(2) * horizontalLength;

	//Set default to have vertical = 5
	vertical = v.at(4) * verticalLength;

	//Set origin
	applyPaint();

}

//fastGrayTechnique
void Ellipse::fastGrayTechnique(RGB targetPixel,RGB canvasPixel,RGB lineColor,Coord c)
{
	int brushToTargetDiff = abs(targetPixel.r - lineColor.r);
	int brushToCanvasDiff = abs(canvasPixel.r - lineColor.r);

	if (brushToTargetDiff < brushToCanvasDiff)
		writePixel(c, lineColor);
}

/*
 * Other techniques haven't implemented
 * such as fastcolourtechnique ( 2 3) 
 */

 //Apply paint - copy from triangle
 void Ellipse::applyPaint()
 {
 	//There's no colour yet mostly use BLEND
 	const int BLEND = 0;
    const int NO_PIXEL = 1;
    const int NO_STROKE = 2;
    const int STOP_STROKE = 3;

    const int STRATEGY = reader->getShroudPixelStrategy();

    switch (STRATEGY)
    {
        case BLEND:
            applyBlend();
            break;
        // case NO_PIXEL:
        //     applyNoPixel();
        //     break;
        // case NO_STROKE:
        //     applyNoStroke();
        //     break;
        // case STOP_STROKE:
        //     applyStopStroke();
    }
 }

 void Ellipse::applyFastShroud(Coord c, RGB lineColor)
 {
 	RGB targetPixel = getTarget()->getRGB(c);
	RGB canvasPixel = getRGBData(getDataOffset(c));

	//No colour yet so just gray
	fastGrayTechnique(targetPixel,canvasPixel,lineColor,c);
 }

 bool Ellipse::applyEllipse()
 {
 	int ho = (int)horizontal; // horizontal
 	int ve = (int)vertical; // vertical

 	if(ho == 0 || ve == 0){
 		return false;
 	}
 	else
 	{
 		return true;
 	}
 }

void Ellipse::applyBlend()
{
	if(applyEllipse())
	{
		// In this case I only do fill Ellipse first
		std::vector<float> vectorX;
		std::vector<float> vectorY;

		for(int y=-vertical; y<=vertical; y++) {
			for(int x=-horizontal; x<=horizontal; x++) {
				if(x*x*vertical*vertical+y*y*horizontal*horizontal <= vertical*vertical*horizontal*horizontal){
					vectorX.push_back(origin.x+x);
					vectorY.push_back(origin.y+y);
				}
			}
		}

		float minX = vectorX.at(0);
		float minY = vectorY.at(0);
		float maxX = vectorX.at(0);
		float maxY = vectorY.at(0);

		for(int i = 0; i < vectorX.size() ; i++){
			minX = GetMin(minX, vectorX[i]);
			minY = GetMin(minY, vectorY[i]);
			maxX = GetMax(maxX, vectorX[i]);
			maxY = GetMax(maxY, vectorY[i]);
		}
		fillUpEllipse(minY,maxY,minX,maxX, vectorX, vectorY);
	}
}

void Ellipse::fillUpEllipse(float minY,float maxY,float minX,float maxX, 
	std::vector<float> allX, std::vector<float> allY){
	for (float y = minY; y < maxY; y++)
	{
		for (float x = minX; x < maxX ; x++)
		{	
			Coord c = {x,y};
			if (insideCanvas(c))
			{	
				if(barycentric(c,allX,allY))
				{
					if (reader->getFastShroud())//Fast convergence: fastShroud is on
						applyFastShroud(c, lineColor);
					else//Slow Convergence
						writePixel(c, lineColor);	
				}
			}
		}
	}
}

bool Ellipse::barycentric(Coord c, std::vector<float> allX, std::vector<float> allY)//To check the fixel whether is inside of the ellipse or not
{
	float x = c.x;
	float y = c.y;
	bool checked = false;

	// cout << "***************** THE SIZE " << allX.size() << "********";

	/* **** THIS ONE NEED TO MODIFY TO IMPROVE PERFORMANCE
	 * Because I didn't have time so I just check every single element
	 */
	for(int i = 0; i < allX.size() ; i++){
		if(x == allX.at(i) && y == allY.at(i)){
			checked = true;
			break;
		}
	}		
			
	if(checked){
		return true;
	}
	return false;
}

void Ellipse::writePixel(Coord c, RGB color){
    if (!insideCanvas(c))
        return;
    
    setRGBData(getDataOffset(c), mixPixels(c, color, 0.5f));
}

RGB Ellipse::mixPixels(Coord coord, RGB strokeRGB, float alpha)
{
    RGB canvasRGB = getRGBData(getDataOffset(coord));
    RGB newRGB;
    
    newRGB.r = (int)(strokeRGB.r * alpha + canvasRGB.r * (1 - alpha));
    newRGB.g = (int)(strokeRGB.g * alpha + canvasRGB.g * (1 - alpha));
    newRGB.b = (int)(strokeRGB.b * alpha + canvasRGB.b * (1 - alpha));

    return newRGB;
}

void Ellipse::swipResetConvas(RGB rgb)
{
	 const int size = getSize();
	for (int i = 0; i < size; i++)
        {
           setRGBData(i, rgb);
        }
}

void Ellipse::printCoord(Coord c)
{
    cout << " {" << c.x << "," << c.y << "}";
}

//Reset the canvas
void Ellipse::resetCanvas()
{
	if (reader->getUsingAdaptiveCanvas())
    {
        for (int y = 0; y < getHeight(); y++)
        {
            for (int x = 0; x < getWidth(); x++)
            {
                Coord c = {x, y};
                RGB rgb = bestCanvas->getRGBPixel(c);
                setRGBData(y * getWidth() + x, rgb);
            }
        }
    }
    else
    {
  //   	if(reader->getColourMode())
		// {
		// 	const color_t bg_Red = getbgColor_Red();
		// 	const color_t bg_Green = getbgColor_Green();
		// 	const color_t bg_Blue = getbgColor_Blue();
			
		// 	RGB rgb= {bg_Red, bg_Green, bg_Blue};
		// 	swipResetConvas(rgb);
		// }
		// else
		// {
			const color_t bg = getBGColor();
			RGB rgb = {bg, bg, bg};
			swipResetConvas(rgb);
		// }
	}
    resetNumDrawNodes();
}

void Ellipse::computeSelectedFitness()
{
	// if(reader->getColourMode())
	// {
	// 	computeColourFitness();
	// }
	// else
		computeGrayFitness();
}

void Ellipse::computeGrayFitness()
{
    float ret = 0.0f;
    int width = getWidth();
    int height = getHeight();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Coord c = {x, y};
            RGB targetPixel = getTarget()->getRGB(c);
            RGB canvasPixel = getRGBData(getDataOffset(c));

            int diff = abs(targetPixel.r - canvasPixel.r);
            ret += diff;
        }
    }

    ret /= getSize();
    ret /= 256.0f;
	selectedFitness = ret; 
}
