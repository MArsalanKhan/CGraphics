

// System Headers

#include <iostream>  
#include "CCircle.h"


using namespace std;


// Own Headers


// Implementation
CCircle::CCircle(float x, float y, 
				 float r, string color) : CGraphicElement(1,color,"Circle")
{
	//Calling a member of the derived class for initialisation
	CGraphicElement::setCorner(0,x,y);
	
	//Setting own attribute
	m_r = r;
}

void CCircle::print()
{
		//This one requires protected scope
	cout << "SPECIALISED: Printing circle with radius " << m_r << " at " << m_coordinate[0] << endl;

}
void CCircle::setCorner()
{
	int x,y;
	float r;
	cout << "Enter middle point and radius: (x,y,r) = ";
	cin >> x >> y >> r;
	cout << endl;
	CGraphicElement::setCorner(0,x,y);
	m_r = r;
}
