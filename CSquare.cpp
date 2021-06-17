/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************/

// System Headers

#include <iostream>  
using namespace std;

// Own Headers
#include "CSquare.h"



// Implementation

CSquare::CSquare(float x1, float y1, 
				 float x2, float y2, 
				 string color) : CGraphicElement(2,color,"Square")
{
	setCorner(0,x1,y1);
	setCorner(1,x2,y2);
}



