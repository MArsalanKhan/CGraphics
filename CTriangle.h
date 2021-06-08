/*
 * CTriangle.h
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */

#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <string>
using namespace std;

//#include "CGraphicElement.h"
#include "CRectangle.h"

namespace GraSys
{
template<class N>
class CTriangle : public CGraphicElement<N>
{

public:
	CTriangle(string color);
	CTriangle(string color, GraSys::CCoordinate<N>& corner1,
			GraSys::CCoordinate<N>& corner2, GraSys::CCoordinate<N>& corner3);
	void settingPoints();
	~CTriangle();
protected:
	string getTypeName();

};
}
#endif/* CTRIANGLE_H_ */

/*
 * CTriangle.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */

//#include <iostream>
//using namespace std;
//#include "CTriangle.h"
//#include "CCoordinate.h"

// the triangle constructor uses the self implemented method of setting point for the complete initialization of triangle
template<class N>
GraSys::CTriangle<N>::CTriangle(string color) :
		CGraphicElement<N>("Triangle", color)
{
	settingPoints();
}

// the method ask from user to provide the missing elements of the object
template<class N>
void GraSys::CTriangle<N>::settingPoints()
{
	N x, y;
	GraSys::CCoordinate<N> temp;
	cout << "Give First set of Coordinate e.g(X then enter Y then enter)"
			<< endl;
	cout << "X = ";
	cin >> x;
	cout << endl;
	cout << "Y = ";
	cin >> y;
	cout << endl;
	temp.setCartesian(x, y);
	this->setCordinates(temp);

	cout << "Give Second set of Coordinate e.g(X then enter Y then enter)"
			<< endl;
	cout << "X = ";
	cin >> x;
	cout << endl;
	cout << "Y = ";
	cin >> y;
	cout << endl;
	temp.setCartesian(x, y);
	this->setCordinates(temp);

	cout << "Give Third set of Coordinate e.g(X then enter Y then enter)"
			<< endl;
	cout << "X = ";
	cin >> x;
	cout << endl;
	cout << "Y = ";
	cin >> y;
	cout << endl;
	temp.setCartesian(x, y);
	this->setCordinates(temp);

}

//the overloaded constructor of the triangle which holds all the required values for the initialization of the triangle
template<class N>
GraSys::CTriangle<N>::CTriangle(string color, GraSys::CCoordinate<N>& corner1,
		GraSys::CCoordinate<N>& corner2, GraSys::CCoordinate<N>& corner3) :
		CGraphicElement<N>("Triangle", color)
{
	this->setCordinates(corner1);
	this->setCordinates(corner2);
	this->setCordinates(corner3);
}

//returns the name of type on demand
template<class N>
string GraSys::CTriangle<N>::getTypeName()
{
	return "Triangle";
}

template<class N>
GraSys::CTriangle<N>::~CTriangle()
{

}

