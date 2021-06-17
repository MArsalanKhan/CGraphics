/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/

// System Headers

#include <iostream>  
#include <string>

using namespace std;

#include "CTriangle.h"

CTriangle::CTriangle(float x1, float y1, 
					 float x2, float y2, 
					 float x3, float y3, 
					 string color) : CGraphicElement(3,color,"Triangle")
{
	setCorner(0,x1,y1);
	setCorner(1,x2,y2);
	setCorner(2,x3,y3);
}



