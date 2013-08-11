/*
 * Class:  Triangle
 * Author: Ashkan Izadi
 * last mified: 25 Feb 2010
 *
 * See header file for details.
 *
 */

using namespace std;

#define GetMin(a,b) ((a) < (b) ? (a) : (b))
#define GetMax(a,b) ((a) > (b) ? (a) : (b))

#include "Triangle.h"
#include "ConfigReader.h"
#include <cstring>

#include <math.h>
#include <vector>


//to implement Gray scale
Triangle::Triangle(Target* t, color_t bg, BestCanvas* bc, ConfigReader* reader)
: Canvas(t, bg, bc), reader(reader)
{
  const int size = getSize();
  triangle = new RGB[size];
	flagDraw = true;
	
}

//to implement Colourful scale
Triangle::Triangle(Target* t, color_t bg_Red, color_t bg_Green, color_t bg_Blue, BestCanvas* bc, ConfigReader* reader)
: Canvas(t, bg_Red, bg_Green, bg_Blue, bc), reader(reader)
{
  const int size = getSize();
  triangle = new RGB[size];
	
  rgbFitnessR=0.0f;
  rgbFitnessG=0.0f;
  rgbFitnessB=0.0f;
	
  //setNumberCircule(0);
  //setNumberGrayFitness(0);
	  
/*
  string createTxt = reader->getShroudLogName();
  setNumberCircule(getNumberCircule());
  std::string circuleTxt;
  std::stringstream out;
  out << getNumberCircule();
  circuleTxt=out.str();
  createTxt.append(circuleTxt);
  createTxt.append(".txt");
	
  char txtPath[150];
  strcpy(txtPath, createTxt.c_str());
	
  //shroudlogFile.open(reader->getShroudLogName());
  shroudlogFile.open(txtPath);
  if (shroudlogFile.bad())
  {
    reader->setErrorLogBad(true);
  }
*/
	
}

Triangle::~Triangle()
{
/*
int newnumber=getNumberCircule()+1;
	setNumberCircule(newnumber);
	shroudlogFile <<"====END======\n\n"<<endl;		
	//shroudlogFile <<"**********\n\n" 
		//<< "hue: " << <<endl;
		//	<< " how many pixels are in this range:" << cal << endl
	//<<"The Total Fitness IS --> " << selectedFitness << endl;
	shroudlogFile.close();
*/
  delete triangle;
}

// Apply some paint to the canvas by drawing some lines
void Triangle::paintCanvas(vector<float> v)
{
	if(reader->getColourMode())
	{
		const unsigned ARGS = 8;
		assert(v.size() == ARGS);

		// Set up the line color
		int red = (int)(v.at(3) * 256);
		int green = (int)(v.at(6) * 256);
		int blue = (int)(v.at(7) * 256);
		lineColor.r = red;
		lineColor.g = green;
		lineColor.b = blue;
	}
	else
	{
		const unsigned ARGS = 6;
		assert(v.size() == ARGS);
	     
		// Set up the line color
		int gray = (int)(v.at(3) * 256);
		lineColor.r = gray;
		lineColor.g = gray;
		lineColor.b = gray;
	}
		
	// Increment the node count
	newNode();
		    
	// Set up the start point
	int pixelIndex = (int)(v.at(0) * getSize());
	startPoint.x = (float)(pixelIndex % getWidth());
	startPoint.y = (float)(pixelIndex / getWidth());
	    
	// Set up the angle of first line
    theta1 = v.at(1) * TWO_PI;
		
	// Set up the angle of second line
    theta2 = v.at(4) * TWO_PI;
			
	// Set up the line length
	int w = getWidth();
	int h = getHeight();
		
	//if the Line length is equal to zero, as a default pass the noraml linelength
	if(reader->getFirstLineLength() == 0)
		lineLength1 = (v.at(2) * sqrt( (float)(w*w + h*h) ));
						
	//if it is not equal to zero, it will pass the variable from painter.txt file
	else
	{
		float templine1 = reader->getFirstLineLength();
		lineLength1 = (v.at(2) * templine1);
	}
			
	//For second line
	if(reader->getSecondLineLength() == 0)
		lineLength2 = (v.at(5) * sqrt( (float)(w*w + h*h) ));		
	else
	{
		float templine2 = reader->getSecondLineLength();
		lineLength2 = (v.at(5) * templine2);		
	}
    applyPaint();
}
void Triangle::fastColourTechnique3(RGB targetPixel,RGB canvasPixel,RGB lineColor, Coord c)
{
	int RedNewlineToTargetDiff = abs(targetPixel.r - lineColor.r);
	int RedCanvasToTargetDiff = abs(targetPixel.r - canvasPixel.r);
	if (RedNewlineToTargetDiff> RedCanvasToTargetDiff)
		lineColor.r=canvasPixel.r;
		
	int GreenNewlineToTargetDiff = abs(targetPixel.g - lineColor.g);
	int GreenCanvasToTargetDiff = abs(targetPixel.g - canvasPixel.g);
	if (GreenNewlineToTargetDiff  > GreenCanvasToTargetDiff )
		lineColor.g=canvasPixel.g;
	
	int BlueNewlineToTargetDiff = abs(targetPixel.b - lineColor.b);
	int BlueCanvasToTargetDiff = abs(targetPixel.b - canvasPixel.b);
	if (BlueNewlineToTargetDiff> BlueCanvasToTargetDiff )
		lineColor.b=canvasPixel.b;
	
	if ((RedNewlineToTargetDiff < RedCanvasToTargetDiff ) || (GreenNewlineToTargetDiff < GreenCanvasToTargetDiff)	|| (BlueNewlineToTargetDiff < BlueCanvasToTargetDiff ))
		writePixel(c, lineColor);
}

void Triangle::fastColourTechnique2(RGB targetPixel,RGB canvasPixel,RGB lineColor,Coord c)
{
	int RedNewlineToTargetDiff = abs(targetPixel.r - lineColor.r);
	int RedCanvasToTargetDiff = abs(targetPixel.r - canvasPixel.r);
						
	int GreenNewlineToTargetDiff = abs(targetPixel.g - lineColor.g);
	int GreenCanvasToTargetDiff = abs(targetPixel.g - canvasPixel.g);
						
	int BlueNewlineToTargetDiff = abs(targetPixel.b - lineColor.b);
	int BlueCanvasToTargetDiff = abs(targetPixel.b - canvasPixel.b);
						
	int TotalNewLineToTargetDiff= RedNewlineToTargetDiff + GreenNewlineToTargetDiff + BlueNewlineToTargetDiff;
	int TotalCanvasToTargetDiff= RedCanvasToTargetDiff+ GreenCanvasToTargetDiff+ BlueCanvasToTargetDiff ;
						
	if (TotalNewLineToTargetDiff< TotalCanvasToTargetDiff)
		writePixel(c, lineColor);
}

void Triangle::fastGrayTechnique(RGB targetPixel,RGB canvasPixel,RGB lineColor,Coord c)
{
	int brushToTargetDiff = abs(targetPixel.r - lineColor.r);
	int brushToCanvasDiff = abs(canvasPixel.r - lineColor.r);

	if (brushToTargetDiff < brushToCanvasDiff)
		writePixel(c, lineColor);
}
// Apply paint
void Triangle::applyPaint()
{
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
        case NO_PIXEL:
            applyNoPixel();
            break;
        case NO_STROKE:
            applyNoStroke();
            break;
        case STOP_STROKE:
            applyStopStroke();
    }
}
void Triangle::applyFastShroud(Coord c, RGB lineColor)
{
	RGB targetPixel = getTarget()->getRGB(c);
	RGB canvasPixel = getRGBData(getDataOffset(c));
				
	if(reader->getColourMode())
	{
		if(reader->getColourUpdater())//To choose the best channel or whole pixels
			fastColourTechnique3(targetPixel,canvasPixel,lineColor,c);						
		else
			fastColourTechnique2(targetPixel,canvasPixel,lineColor,c);
	}
	else
		fastGrayTechnique(targetPixel,canvasPixel,lineColor,c);
}

bool Triangle::applyTriangle()
{
	line1 = (int)lineLength1;
	line2 = (int)lineLength2;
	
	for (int i = 0; i < line1; i++)
	{
		crossPoint = rotate2D(startPoint, 0, i, theta1);
	}
	
	for (int i = 0; i < line2; i++)
	{
		endPointSecondLine = rotate2D(startPoint, 0, i, theta2);
	}
	
	float deltaTheta = 0.0f;
	float alphaLine2 = 0.0f;
	
	// Difference between two different angles of two lines
	deltaTheta = fabs(theta1 - theta2);
	if(line1 == 0 || line2 == 0)
		return false;
	else if (deltaTheta != PI && deltaTheta != 0.0f)
	{
		if(deltaTheta > PI)
		{
			deltaTheta = TWO_PI - deltaTheta;
		}
	
		//calculate to get lineLength3
		float powerLine1 = pow(lineLength1,2.0f);
		float powerLine2 = pow(lineLength2,2.0f);
		float cosDelta =  cos(deltaTheta);
		float crossLines = 2 * (lineLength2 * lineLength1);
	
		float coefficient = crossLines * cosDelta;
		float powerLine3 = powerLine1 + powerLine2 - coefficient;

		lineLength3 = (sqrt(powerLine3));
		line3 = (int)lineLength3;
				
		double parameter2 = (double)(lineLength1 * sin(deltaTheta)) / lineLength3;
		double alphaLine1 = asin(parameter2);

		if(lineLength2 < lineLength1)
		{
			double parameter = (double)(lineLength2 * sin(deltaTheta)) / lineLength3;
			alphaLine2 = asin(parameter);
		}
		else
		{
			alphaLine2 = PI - ( alphaLine1 + deltaTheta);
		}
		
		//Calculate Theta3
		float add = theta1 + PI;
		if(add > TWO_PI)
		{
			add = fabs(add - TWO_PI);
		}
		//To check whether theta1 is greater than theta2!
		float diffTheta = fabs(theta1 - theta2);
		if(theta1 > theta2)
		{
			if(diffTheta > PI)
			{
				theta3 = add - alphaLine2;
			}
			else
			{
				theta3 = add + alphaLine2;
			}
		}
		if(theta2 > theta1)
		{
			if(diffTheta > PI)
				theta3 = add + alphaLine2;
			else
				theta3 = add - alphaLine2;
		}
		//To check the theta3 is in suitable range.
		if(theta3 > TWO_PI)
			theta3 = fabs(theta3 - TWO_PI);
		if(theta3 < 0.0f)
			theta3 = TWO_PI + theta3;
	
		return true;
	}
	else
		return false;
}
void Triangle::applyBlend()
{
	if(applyTriangle())// To check whether is theta3 and lines are the correct ones or not.
	{
		int mode = reader->getTypeTriangle();
		if(mode == 0)//Empty Triangle
		{
			for (int i = 0; i < line1; i++)
			{
				Coord c1 = rotate2D(startPoint, 0, i, theta1);
			
				if (insideCanvas(c1))
				{
					if (reader->getFastShroud())//Fast convergence: fastShroud is on
						applyFastShroud(c1, lineColor);
					else //Slow Convergence
						writePixel(c1, lineColor);
				}
			}
			for (int i = 0; i < line2; i++)
			{
				Coord c2 = rotate2D(startPoint, 0, i, theta2);
			
				if (insideCanvas(c2))
				{
					if (reader->getFastShroud())//Fast convergence: fastShroud is on
						applyFastShroud(c2, lineColor);
					else//Slow Convergence
						writePixel(c2, lineColor);
				}
			}
			for (int i = 0; i < line3; i++)
			{
				Coord c3 = rotate2D(crossPoint, 0, i, theta3);
				if (insideCanvas(c3))
				{
					if (reader->getFastShroud())//Fast convergence: fastShroud is on
						applyFastShroud(c3, lineColor);
					else//Slow Convergence
						writePixel(c3, lineColor);
				}
			}
		}
		else//Fill Triangle
		{				
			//To find the max and min of rectangular, you can move this piece of code inside a function and each time call that function
			// but ***DO NOT ** do that, because after 7 thousand generation causes memory leak.
			float arrayX[] = {startPoint.x, endPointSecondLine.x, crossPoint.x};
			float arrayY[] = {startPoint.y, endPointSecondLine.y,crossPoint.y};

			float minX = arrayX[0];
			float minY = arrayY[0]; 
			float maxX = arrayX[0];
			float maxY = arrayY[0];

			for(int i = 0; i < 3; i++)
			{
				minX = GetMin(minX, arrayX[i]);
				minY = GetMin(minY, arrayY[i]);
				maxX = GetMax(maxX, arrayX[i]);
				maxY = GetMax(maxY, arrayY[i]);
			}
			fillUpTriangle(minY,maxY,minX,maxX);
		}
	}
}
void Triangle::fillUpTriangle(float minY,float maxY,float minX,float maxX){
	for (float y = minY; y < maxY; y++)
	{
		for (float x = minX; x < maxX ; x++)
		{	
			Coord c = {x,y};
			if (insideCanvas(c))
			{	
				if(barycentric(c))
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
bool Triangle::barycentric(Coord c)//To check the fixel whether is inside of the triangle or not
{
	float x = c.x;
	float y = c.y;

					//if(triangle->baryCentric(c, startPoint, endPointSecondLine, crossPoint))
					//--------------------
					//to find more about the Barycentric Equation please visit the following web site:
					// http://en.wikipedia.org/wiki/Barycentric_coordinates_%28mathematics%29
				

					float landa1,landa2,landa3;
					
					float first = (( endPointSecondLine.y - crossPoint.y) * ( x - crossPoint.x)) - (( endPointSecondLine.x - crossPoint.x) * (y - crossPoint.y));
					float second = ((  startPoint.x  - crossPoint.x) * (y- crossPoint.y)) - (( startPoint.y - crossPoint.y) * ( x - crossPoint.x));
					float detMatrix = (( startPoint.x  - crossPoint.x) * (endPointSecondLine.y - crossPoint.y)) -((endPointSecondLine.x - crossPoint.x) * (startPoint.y - crossPoint.y));

					landa1 = first / detMatrix;
					landa2 = second / detMatrix;
					landa3 = 1.0f - landa1 - landa2;

					if( landa1 <= 1.0f && landa1 >= 0.0f)//Point lies in the triangle and its edge or its corner.
						if(landa2 <= 1.0f && landa2 >=0.0f)
							if(landa3 <= 1.0f && landa3 >=0.0f)
								return true;//writePixel(c, lineColor);		
								
					//-------------------------------
					//writePixel(c, lineColor);		
			
	return false;
}
void Triangle::applyNoPixel()//It says if the stroke has got same color with a canvas do NOT draw the specific pixel
{
	//Not implemented for Triangles,yet.
	/**
		
		
		//Draw the triangle
		if(applyTriangle())
		{
			int mode = reader->getTypeTriangle();
			if(mode == 0) //Empty triangle
			{
				vector<Coord> vCoord = triangle->drawEmptyTriangle(startPoint,crossPoint, theta1, theta2, theta3, line1, line2, line3);
				if (reader->getFastShroud())
				{
					for (unsigned int i = 0; i < vCoord.size() ; i++)
					{
						if (!pixelIsDirty(vCoord.at(i))) // Don't draw the pixel
							applyFastShroud(vCoord.at(i),lineColor);
					}
				}
				else//Slow Convergence
				{
					for (unsigned int i = 0; i < vCoord.size() ; i++)
					{
						if (!pixelIsDirty(vCoord.at(i))) // Don't draw the pixel
							writePixel(vCoord.at(i), lineColor);
					}
				}
			}
			else // Fill triangle
			{
				vector<float> vMaxMin = triangle->findMinMaxOfTriangle(startPoint, endPointSecondLine, crossPoint);
				if (reader->getFastShroud())
				{
					for (float y = vMaxMin.at(1); y < vMaxMin.at(3); y++)
					{
						for (float x = vMaxMin.at(0); x < vMaxMin.at(2) ; x++)
						{	
							Coord c = {x,y};
							if (insideCanvas(c))
								if(triangle->baryCentric(c, startPoint, endPointSecondLine, crossPoint))
									if (!pixelIsDirty(c)) // Don't draw the pixel
										applyFastShroud(c,lineColor);
						}	
					}
				}
				else
				{
					for (float y = vMaxMin.at(1); y < vMaxMin.at(3); y++)
					{
						for (float x = vMaxMin.at(0); x < vMaxMin.at(2) ; x++)
						{	
							Coord c = {x,y};
							if (insideCanvas(c))
								if(triangle->baryCentric(c, startPoint, endPointSecondLine, crossPoint))
									if (!pixelIsDirty(c)) // Don't draw the pixel
										writePixel(c, lineColor);		
						}	
					}
				}
			}
		}
	}
*/

}

void Triangle::applyNoStroke() //if even one pixel is same on the canvas, Do not write that image(line or triangle) at all
{
	if(applyTriangle())// To check whether is theta3 and lines are the correct ones or not.
	{
				
				float arrayX[] = {startPoint.x, endPointSecondLine.x, crossPoint.x};
				float arrayY[] = {startPoint.y, endPointSecondLine.y,crossPoint.y};

				float minX = arrayX[0];
				float minY = arrayY[0]; 
				float maxX = arrayX[0];
				float maxY = arrayY[0];
				for(int i = 0; i < 3; i++)
				{
					minX = GetMin(minX, arrayX[i]);
					minY = GetMin(minY, arrayY[i]);
					maxX = GetMax(maxX, arrayX[i]);
					maxY = GetMax(maxY, arrayY[i]);
				}
					
				for (float y = minY; y < maxY; y++)
				{
					for (float x = minX; x < maxX ; x++)
					{	
	
						Coord c = {x,y};
						if (insideCanvas(c))
							if(barycentric(c))
								if (pixelIsWhite(c))//if (pixelIsDirty(c)) // Don't draw the pixel
									return;
					}	
				}
		fillUpTriangle(minY,maxY,minX,maxX);
	}
}

void Triangle::applyStopStroke() //if any pixel of image reached to the another image on the canvas, stop to draw rest of the image.
{
	if(applyTriangle())// To check whether is theta3 and lines are the correct ones or not.
	{	
				
				float arrayX[] = {startPoint.x, endPointSecondLine.x, crossPoint.x};
				float arrayY[] = {startPoint.y, endPointSecondLine.y,crossPoint.y};

				float minX = arrayX[0];
				float minY = arrayY[0]; 
				float maxX = arrayX[0];
				float maxY = arrayY[0];
				for(int i = 0; i < 3; i++)
				{
					minX = GetMin(minX, arrayX[i]);
					minY = GetMin(minY, arrayY[i]);
					maxX = GetMax(maxX, arrayX[i]);
					maxY = GetMax(maxY, arrayY[i]);
				}
				for (float y = minY; y < maxY; y++)
				{
					for (float x = minX; x < maxX ; x++)
					{	
							Coord c = {x,y};
							if (insideCanvas(c))
							{	
								if(barycentric(c))
								{
									if (pixelIsWhite(c))//if (pixelIsDirty(c)) // Don't draw the pixel
										return;
									else
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
	}
}
void Triangle::swipResetConvas(RGB rgb)
{
	 const int size = getSize();
	for (int i = 0; i < size; i++)
        {
           setRGBData(i, rgb);
        }
}

// Reset the canvas
void Triangle::resetCanvas()
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
    	if(reader->getColourMode())
		{
			const color_t bg_Red = getbgColor_Red();
			const color_t bg_Green = getbgColor_Green();
			const color_t bg_Blue = getbgColor_Blue();
			
			RGB rgb= {bg_Red, bg_Green, bg_Blue};
			swipResetConvas(rgb);
		}
		else
		{
			const color_t bg = getBGColor();
			RGB rgb = {bg, bg, bg};
			swipResetConvas(rgb);
		}
	}
    resetNumDrawNodes();
}

/*
 * Write a pixel in RGB color space
 */
void Triangle::writePixel(Coord c, RGB color)
{
    if (!insideCanvas(c))
        return;
    
    setRGBData(getDataOffset(c), mixPixels(c, color, 0.5f));
}

RGB Triangle::mixPixels(Coord coord, RGB strokeRGB, float alpha)
{
    RGB canvasRGB = getRGBData(getDataOffset(coord));
    RGB newRGB;
    
    newRGB.r = (int)(strokeRGB.r * alpha + canvasRGB.r * (1 - alpha));
    newRGB.g = (int)(strokeRGB.g * alpha + canvasRGB.g * (1 - alpha));
    newRGB.b = (int)(strokeRGB.b * alpha + canvasRGB.b * (1 - alpha));

    return newRGB;
}

void Triangle::printCoord(Coord c)
{
    cout << " {" << c.x << "," << c.y << "}";
}

void Triangle::computeSelectedFitness()
{
	if(reader->getColourMode())
	{
		computeColourFitness();
	}
	else
		computeGrayFitness();
}
void Triangle::computeColourFitness()
{

   
    int width = getWidth();
    int height = getHeight();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            
			Coord c = {x, y};
            RGB targetPixel = getTarget()->getRGB(c);
            RGB canvasPixel = getRGBData(getDataOffset(c));
			
			rgbFitnessR += abs(targetPixel.r - canvasPixel.r);
			rgbFitnessG += abs(targetPixel.g - canvasPixel.g);
			rgbFitnessB += abs(targetPixel.b - canvasPixel.b);
		}
    }
	int theSize= getSize();
	rgbFitnessR /= theSize;
	rgbFitnessG /= theSize;
	rgbFitnessB /= theSize;
	   
	rgbFitnessR /= 256.0f;
	rgbFitnessG /= 256.0f;
	rgbFitnessB /= 256.0f;

	selectedFitness = ( (rgbFitnessR + rgbFitnessG + rgbFitnessB) / 3);
}

void Triangle::computeGrayFitness()
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

