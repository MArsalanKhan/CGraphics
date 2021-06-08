/*
 * CPlane.h
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */

#ifndef CPLANE_H_
#define CPLANE_H_

#include "iostream"
#include <string>
//#include "CGraphicElement.h"
//#include "CRectangle.h"
//#include "CTriangle.h"
#include "CCircle.h"
#include "vector"
namespace GraSys
{
template <class N>
class CPlane
{
private:
	vector<CGraphicElement<N>*> m_shapes;           //using the vector of pointers so as to use the functionality of virtual functions

public:
	CPlane();
	bool addElement(CGraphicElement<N>& element);                                   //the elements are added in the m_shapes
	~CPlane();
	CRectangle<N> boundingBox(string type = "", string color = "");                 //
	void minMax(GraSys::CCoordinate<N> &chk, N &maxX, N &maxY, N &minX,
			N &minY);
	void printScreen();
};
}
#endif /* CPLANE_H_ */

/*
 * CPlane.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: Admin
 */
//#include "iostream"
//#include "CPlane.h"
//#include "CRectangle.h"
//using namespace GraSys;
template<class N>
GraSys::CPlane<N>::CPlane()
{


}
template<class N>
bool GraSys::CPlane<N>::addElement(GraSys::CGraphicElement<N>& element)
{
	m_shapes.push_back(&element);
	return false;
}
template<class N>
GraSys::CPlane<N>::~CPlane()
{

}

template<class N>
GraSys::CRectangle<N> GraSys::CPlane<N>::boundingBox(string type, string color)
{
	unsigned int a = 0;
	//unsigned int b = 0;
	N maxx = -99999, maxy = -99999, minx = 99999, miny = 99999;

	if (type == "")
	{
		while (a < m_shapes.size())
		{

			if( (m_shapes[a]->getType() == "Triangle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				unsigned int c = 0;
				while (c < 3)
				{
					GraSys::CCoordinate<N> mycord = m_shapes[a]->getCoordinate(c);
					minMax(mycord, maxx, maxy, minx, miny);
					c++;
				}
			}

			else if( (m_shapes[a]->getType() == "Rectangle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				unsigned int d = 0;
				while (d < 4)
				{
					GraSys::CCoordinate<N> mycord1 = m_shapes[a]->getCoordinate(d);
					minMax(mycord1, maxx, maxy, minx, miny);
					d++;
				}
			}
			else if ((m_shapes[a]->getType() == "Circle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				GraSys::CCoordinate<N> mycord2 = m_shapes[a]->getCoordinate(0);
				double rad = m_shapes[a]->getRadius();
				N mix, max, miy, may;
				mycord2.getCartesian(mix, miy);
				mycord2.getCartesian(max, may);
				mix = mix - rad;
				miy = miy - rad;
				max = max + rad;
				may = may + rad;
				if (mix < minx)
					minx = mix;
				if (miy < miny)
					miny = miy;
				if (max > maxx)
					maxx = max;
				if (may > maxy)
					maxy = may;
			};

			a++;
		}
	}
	else if (type == "Triangle")
	{
		a = 0;
		while (a < m_shapes.size())
		{

			if ((m_shapes[a]->getType() == "Triangle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				unsigned int c = 0;
				while (c < 3)
				{
					GraSys::CCoordinate<N> mycord = m_shapes[a]->getCoordinate(c);
					minMax(mycord, maxx, maxy, minx, miny);
					c++;
				}
				a++;
			}
			else
				a++;

		}

	}

	else if (type == "Rectangle")
	{
		a = 0;

		while (a < m_shapes.size())
		{
			if ((m_shapes[a]->getType() == "Rectangle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				unsigned int d = 0;
				while (d < 4)
				{
					GraSys::CCoordinate<N> mycord1 = m_shapes[a]->getCoordinate(d);
					minMax(mycord1, maxx, maxy, minx, miny);
					d++;
				}
				a++;
			}

			else
				a++;
		}
	}

	else if (type == "Circle")
	{
		a = 0;
		while (a < m_shapes.size())
		{

			if ((m_shapes[a]->getType() == "Circle")&&((color=="")||(color==m_shapes[a]->getColor())))
			{
				GraSys::CCoordinate <N>mycord2 = m_shapes[a]->getCoordinate(0);
				double rad = m_shapes[a]->getRadius();
				N mix, max, miy, may;
				mycord2.getCartesian(mix, miy);
				mycord2.getCartesian(max, may);
				mix = mix - rad;
				miy = miy - rad;
				max = max + rad;
				may = may + rad;
				if (mix < minx)
					minx = mix;
				if (miy < miny)
					miny = miy;
				if (max > maxx)
					maxx = max;
				if (may > maxy)
					maxy = may;
				a++;
			}

			else
				a++;

		}

	};
	if ((maxx != -99999) && (maxy != -99999) && (minx != 99999)
			&& (miny != 99999))

	{
		GraSys::CCoordinate<N> bbe1(maxx, maxy);
		GraSys::CCoordinate<N> bbe2(minx, miny);
		GraSys::CRectangle<N> result("dark",bbe1, bbe2);
		return result;
	}
	else
	{
		GraSys::CCoordinate<N> b00(0,0);
		GraSys::CCoordinate<N> b000(0,0);
		GraSys::CRectangle<N> rl("dark",b00,b000);
		cerr << "Desired Object not Found" << endl;
		return rl;
	}

}


//the self implemented method used to reduce complexity of the bounding box method so it just compares the
//minimum and maximum values out from the given coordinate
template<class N>
void GraSys::CPlane<N>::minMax(GraSys::CCoordinate<N>& chk, N& maxX, N& maxY,
		N& minX, N& minY)
{
	N cx, cy;
	chk.getCartesian(cx, cy);
	if (cx < minX)
		minX = cx;
	if (cx > maxX)
		maxX = cx;
	if (cy < minY)
		minY = cy;
	if (cy > maxY)
		maxY = cy;
}
template<class N>
void GraSys::CPlane<N>::printScreen()
{
	unsigned int c=0;
if(m_shapes.size()!=0){
	for(c=0;c<m_shapes.size();c++)
	{
		m_shapes[c]->print();
	}
}
else cerr<<"Nothing in Pool to Print"<<endl;

}
