/*
 * CRectangle.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
 */

#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "CGraphicElement.h"

namespace GraSys{
template <class N>
class CRectangle : public CGraphicElement<N> {

protected:
    string getTypeName();

public:
    CRectangle();
	CRectangle(string color);
	void settingPointsR();
	CRectangle(string color, GraSys::CCoordinate<N>& corner1, GraSys::CCoordinate<N>& corner2);
	~CRectangle();
};
}
#endif/* CRECTANGLE_H_ */

/*
 * CRectangle.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
 */

//constructor that uses the self implemented method of setting point R for the complete initialization of Rectangle
template<class N>
GraSys::CRectangle<N>::CRectangle(string color) :
		CGraphicElement<N>("Rectangle", color)
{
	settingPointsR();
}

//returns the name of type on request
template<class N>
string GraSys::CRectangle<N>::getTypeName()
{
	return "Rectangle";
}

//the method ask from the user to enter the points which at the time of initialization were not given
template<class N>
void GraSys::CRectangle<N>::settingPointsR()
{
	N cordix1, cordix2, cordiy1, cordiy2;
	cout << "Give the coordinate of a Diagnol Corner" << endl;
	cout << "X1 = ";
	cin >> cordix1;
	cout << endl;

	cout << "Y1 = ";
	cin >> cordiy1;
	cout << endl;

	cout << "X2 = ";
	cin >> cordix2;
	cout << endl;

	cout << "Y2 = ";
	cin >> cordiy2;
	cout << endl;
	GraSys::CCoordinate<N> rect1(cordix1, cordiy1);
	GraSys::CCoordinate <N>rect2(cordix1, cordiy2);
	GraSys::CCoordinate<N> rect3(cordix2, cordiy1);
	GraSys::CCoordinate<N> rect4(cordix2, cordiy2);
	setCordinates(rect1);
	setCordinates(rect2);
	setCordinates(rect3);
	setCordinates(rect4);

}



//the overloaded constructor that holds all the required values at the time of initialization
template<class N>
GraSys::CRectangle<N>::CRectangle(string color, GraSys::CCoordinate<N>& corner1,
		GraSys::CCoordinate<N>& corner2) :
		CGraphicElement<N>("Rectangle", color)
{
	N x1, x2, y1, y2;
	x1 = corner1.getX();
	x2 = corner2.getX();
	y1 = corner1.getY();
	y2 = corner2.getY();
	GraSys::CCoordinate<N> corner3(x1, y2);
	GraSys::CCoordinate <N>corner4(x2, y1);
//	setCartesian(corner1);
//	setCoordinates(corner2);
//	setCoordinates(corner3);
//	setCoordinates(corner4);
}


//default constructor
template<class N>
GraSys::CRectangle<N>::CRectangle()
{
}
template<class N>
GraSys::CRectangle<N>::~CRectangle()
{
}
