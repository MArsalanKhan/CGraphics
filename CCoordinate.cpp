#include <iostream>				
#include <stdlib.h>
#include <math.h>

using namespace std;			

#include "CCoordinate.h"		

#define PI 3.14159265


int CCoordinate::m_counter = 0;

CCoordinate::CCoordinate(float x, float y)
{
	m_x = x;
	m_y = y;
	m_counter++;
	//cout << "Generated "<< m_counter <<". Coordinate object at adress " << this <<" with the values: " << m_x << " , " << m_y << endl;
}

CCoordinate::CCoordinate(t_quadrant quadrant)
{
	m_counter++;

	switch (quadrant)
	{
	case Q1: m_x = 1; m_y = 1; break;
	case Q2: m_x = -1; m_y = 1; break;
	case Q3: m_x = -1; m_y = -1; break;
	case Q4: m_x = 1; m_y = -1; break;
	}
	//cout << "Generated " << m_counter <<". CCoordinate object at adress " << this <<" with the values: " << m_x << " , " << m_y << endl;
}
 


void CCoordinate::setCartesian(float x, float y)
{
	//cout << "Setting to cartesian : " << x << ", " << y << endl;

	m_x = x;
	m_y = y;
}


void CCoordinate::setPolar(float r, float phi)
{
	//cout << "Setting to polar : " << r << ", " << phi << endl;
	phi = phi/180*PI;
	m_x = calcX(r,phi);
	m_y = calcY(r,phi);
}

void CCoordinate::get(t_representation format, float & val1, float & val2)
{
	switch(format)
	{
	case POLAR : val1 = calcR();
				 val2 = calcPhi();
				 break;
	case CARTESIAN: val1 = m_x;
					val2 = m_y;
					break;
	default: break;

	}
}

void CCoordinate::print(t_representation format)
{
	switch(format)
	{
	case POLAR : cout << "Polar representation (r,phi) = (" << calcR() << ", " << calcPhi()*180/PI << "deg)" << endl;
				 break;
	case CARTESIAN: cout << "Cartesian representation (x,y) = (" << m_x << ", " << m_y << ")" << endl;
					break;
	default: break;

	}
	
}
void CCoordinate::move(float x , float y)
{
	//cout << "Moving by : " << x << ", " << y << endl;
	m_x += x;
	m_y += y;
}

void CCoordinate::rotate(float angle)
{
	//cout << "Rotating by : " << angle << endl;
	float phi = calcPhi();
	float r = calcR();
	phi += angle*PI/180;
	m_x = calcX(r,phi);
	m_y = calcY(r,phi);
}

void CCoordinate::resize(float factor)
{
	//cout << "Rezising by : " << factor << endl;
	float phi = calcPhi();
	float r = calcR();
	r *= factor;
	m_x = calcX(r,phi);
	m_y = calcY(r,phi);

}

float CCoordinate::calcR()
{
	return sqrt(m_x*m_x + m_y*m_y);
}

float CCoordinate::calcPhi()
{
	return atan2(m_y,m_x);
}

float CCoordinate::calcX(float r, float phi)
{
	return r * cos(phi);
}

float CCoordinate::calcY(float r, float phi)
{
	return r * sin(phi);
}

/*******************************************************************************************
** Overloaded operators
*******************************************************************************************/

CCoordinate operator+(const CCoordinate& c1, const CCoordinate& c2)
{
	CCoordinate result;
	result.m_x = c1.m_x + c2.m_x;
	result.m_y = c1.m_y + c2.m_y;
	return result;
}

CCoordinate operator+(const CCoordinate& c1, float c2)
{
	return CCoordinate(c1+CCoordinate(c2));
}

ostream& operator<<(ostream& out, const CCoordinate& c)
{
	out << "(x,y) = (" << c.m_x << ", " << c.m_y << ")";
	return out;
}

// Define prefix increment operator.
CCoordinate& CCoordinate::operator++()
{
   ++m_x;
   m_y++;			//Here, the order makes no difference
   return *this;	// Return value of current object (=dereferenced this pointer). 
   					// Due to call by reference (&complex) the original object is overwritten
}

// Define postfix increment operator.
CCoordinate CCoordinate::operator++(int)
{
   CCoordinate temp = *this;	// Content of the current object value
   ++*this;					// Object is incremented
   return temp;				// Old value is returned
}