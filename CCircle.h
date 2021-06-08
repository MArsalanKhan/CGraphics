/*
 * CCircle.h
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */

#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <string>
using namespace std;

//#include "CGraphicElement.h"
#include "CTriangle.h"

namespace GraSys{
template<class N>
class CCircle : public CGraphicElement<N> {
private:
    double m_radius;

protected:
    string getTypeName();

public:
    CCircle(std::string color);
    CCircle(string color, GraSys::CCoordinate<N>& center,double rad);
    void setCenter();
    void setRadius();
    double getRadius();
   // void print();
    ~CCircle();
};
}
#endif

/*
 * CCircle.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */

//#include <iostream>
//using namespace std;
//#include "CCircle.h"
template<class N>
GraSys::CCircle<N>::CCircle(string color) :
		CGraphicElement<N>("Circle", color), m_radius(0)
{
	setCenter();
	setRadius();
}

//the function which overrides the function of CGraphicElement
template<class N>
string GraSys::CCircle<N>::getTypeName()
{
	return "Circle";
}

//the center set by the method if the circle has been initialized without the arguments
template<class N>
void GraSys::CCircle<N>::setCenter()
{
	N centx, centy;
	cout << "Give the coordinate of Center" << endl;
	cout << "X : ";
	cin >> centx;
	cout << endl;
	cout << "Y : ";
	cin >> centy;
	cout << endl;
	GraSys::CCoordinate<N> cc(centx, centy);
	this->setCordinates(cc);
}


//the radius set by the method if the circle has been initialized without the arguments
template<class N>
void GraSys::CCircle<N>::setRadius()
{
	double radius;
	cout << "Give the Radius of Center" << endl;
	cout << "Radius : ";
	cin >> radius;
	m_radius = radius;
}


//the overloaded constructor which set all the attributes at the time of construction
template<class N>
GraSys::CCircle<N>::CCircle(string color, GraSys::CCoordinate<N>& center, double rad) :
		CGraphicElement<N>("Circle", color)
{
	this->setCordinates(center);
	cout << "set rad " << rad << endl;
	m_radius = rad;
}

// the method which overrides the virtual method of get radius of CGraphic Element
template<class N>
double GraSys::CCircle<N>::getRadius()
{
	double rus;
	rus = m_radius;
	cout << "rus = " << rus << endl;
	return rus;
}
template<class N>
GraSys::CCircle<N>::~CCircle()
{
}
