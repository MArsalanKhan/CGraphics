/*
 * CGraphicElement.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
 */

#ifndef CGRAPHICELEMENT_H_
#define CGRAPHICELEMENT_H_

#include <string>
#include "CCoordinate.h"
#include "vector"

namespace GraSys{
template <class N>
class CGraphicElement
{
private:
	string m_type;
	string m_color;

protected:

	vector<GraSys::CCoordinate<N> > m_coordinates;

public:
	CGraphicElement();                                  //the default n unloaded constructor
	CGraphicElement(string type, string color);         //the overloaded constructor
	void movet (N xoffset, N yoffset);           //to move the coordinate by the given offset
	string getType();                                   //self implemented functions for getting the type
	string getColor();                                  //self implemented functions for getting the color
	virtual double getRadius();                         // virtual function
	void print();                                       //the main print which is used by all the other geometric shapes
	void setCordinates(CCoordinate<N>& cordi);             //used by the classes to store their coordinate in the vector coordinate
	const CCoordinate<N> getCoordinate(unsigned int index);//Method to get coordinate from the vector with using index
	virtual ~CGraphicElement();

};
}

#endif /* CGRAPHICELEMENT_H_ */

/*
 * CGraphicElement.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
 */


template<class N>
GraSys::CGraphicElement<N>::CGraphicElement(string type, string color)
{
	m_type = type;        //initialization of attribute
	m_color = color;      //initialization of attribute

}



//below method is used to move the coordinate by given offset

template<class N>
void GraSys:: CGraphicElement<N>::movet(N xoffset, N yoffset)
{
	for (unsigned int i = 0; i < m_coordinates.size(); i++)
	{
		N x, y;
		m_coordinates[i].getCartesian(x, y);
		x += xoffset;
		y += yoffset;
		m_coordinates[i].setCartesian(x, y);
	}
}


//the basic method of printing that is used by other shapes as well
template<class N>
void GraSys:: CGraphicElement<N>::print() {
	cout << m_type << "(color: " << m_color << ") with coordinates: ";
	for (unsigned int i = 0; i < m_coordinates.size(); i++) {
		cout << "[" << m_coordinates[i].getX()
				<< ", " << m_coordinates[i].getY() << "]";
		if (i < m_coordinates.size() - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}
template<class N>
GraSys::CGraphicElement<N>::CGraphicElement()
{
}


//it stores the coordinates to the vector in CGraphic Element
template<class N>
void GraSys:: CGraphicElement<N>::setCordinates(CCoordinate<N>& cordi)
{
	m_coordinates.push_back(cordi);
}


// the Method returns the type stored in private attribute
template<class N>
string GraSys::CGraphicElement<N>::getType()
{string type;
type=m_type;
	return type;
}

// the Method returns the Color stored in private attribute
template<class N>
string GraSys::CGraphicElement<N>::getColor()
{
	string colour;
    colour=m_color;
	return colour;
}


// implementation of the virtual function which is never utilized
template<class N>
double GraSys::CGraphicElement<N>::getRadius()
{
	return 0;
}


// the method return with the set of coordinate present at the given index in the vector of coordinates
template<class N>
const GraSys::CCoordinate<N> GraSys::CGraphicElement<N>::getCoordinate(unsigned int index)
{
	N corx,cory;
	m_coordinates[index].getCartesian(corx,cory);
	GraSys:: CCoordinate<N> obj(corx,cory);
	return obj;
}

template<class N>
GraSys::CGraphicElement<N>::~CGraphicElement()
{
}
