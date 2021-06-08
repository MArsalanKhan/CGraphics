/*
 * CCoordinate.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
 */

#ifndef CCOORDINATE_H_
#define CCOORDINATE_H_

#include <ostream>
using namespace std;
namespace GraSys{
template<class N>
class CCoordinate;
template<class N>
bool operator!= (const CCoordinate<N>& c1, const CCoordinate<N>& c2);
template<class N>
bool operator== (const CCoordinate<N>& c1,const CCoordinate<N>& c2);
template<class N>
CCoordinate<N> operator+ (const CCoordinate<N>& c1, const CCoordinate<N>& c2);
template<class N>
ostream& operator<< (ostream& out, const CCoordinate<N>& c);
template <class N>
class CCoordinate
{
	friend bool operator!=<> (const CCoordinate<N>& c1, const CCoordinate<N>& c2);
	friend bool operator== <>(const CCoordinate<N>& c1,const CCoordinate<N>& c2);
	friend CCoordinate<N> operator+ <>(const CCoordinate<N>& c1, const CCoordinate<N>& c2);
	friend ostream& operator<<<> (ostream& out, const CCoordinate<N>& c);

private:
	N m_x;
	N m_y;

public:
	enum t_quadrant { Q1, Q2, Q3, Q4 };

	CCoordinate(N initialX = 0, N initialY = 0);
	CCoordinate(t_quadrant quadrant);
	CCoordinate(const CCoordinate<N>& orig);
	~CCoordinate();

	void setCartesian(N x, N y);
	void getCartesian(N& x, N& y);
void prr();
	void move (N xoffset, N yoffset);
	N getX();
	N getY();
};

}
#endif /* CCOORDINATE_H_ */

/*
 * CCoordinate.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: Arsalan
*/


template<class N>
void GraSys:: CCoordinate<N>::move(N xoffset, N yoffset)
{
	m_x=m_x+xoffset;
	m_y=m_y+yoffset;

}

template<class N>
void GraSys:: CCoordinate<N>::prr()
{
	cout<<m_x<<endl;
	cout<<m_y<<endl;
}


template<class N>
GraSys::CCoordinate<N>::CCoordinate(N initialX, N initialY) {
//	cout << "Initializing object at " << this << endl;
	m_x = initialX;
	m_y = initialY;
}
template<class N>
GraSys::CCoordinate<N>::CCoordinate(t_quadrant quadrant)
{
	switch(quadrant) {
	case Q1:
		m_x = 1;
		m_y = 1;
		break;
	case Q2:
		m_x = -1;
		m_y = 1;
		break;
	case Q3:
		m_x = -1;
		m_y = -1;
		break;
	case Q4:
		m_x = 1;
		m_y = -1;
		break;
	}
}
template<class N>
GraSys::CCoordinate<N>::CCoordinate(const CCoordinate<N>& orig)
{
//	cout << "Initializing object (copy) at " << this << endl;
	m_x = orig.m_x;
	m_y = orig.m_y;
}
template<class N>
GraSys::CCoordinate<N>::~CCoordinate()
{
//	cout << "Destructing object at " << this << endl;
}
template<class N>
void GraSys:: CCoordinate<N>::setCartesian(N x, N y)
{
	m_x = x;
	m_y = y;
}
template<class N>
N GraSys:: CCoordinate<N>::getX() {
	return m_x;
}

template<class N>
N GraSys::CCoordinate<N>::getY()
{
	return m_y;
}
template<class N>
void GraSys:: CCoordinate<N>::getCartesian(N& x, N& y) {
	//cout << "Address of parameter x: " << &x << endl;
	x = m_x;
	y = m_y;
}
template<class N>
GraSys::CCoordinate<N> GraSys:: operator+(const GraSys::CCoordinate<N>& c1, const GraSys::CCoordinate<N>& c2) {
	GraSys::CCoordinate<N> result (c1.m_x + c2.m_x, c1.m_y + c2.m_y);
	return result;
}
template<class N>
ostream& GraSys:: operator<< (ostream& out, const GraSys::CCoordinate<N>& c) {
	out << c.m_x << " " << c.m_y;
	return out;
}
template<class N>
bool GraSys:: operator== ( const GraSys::CCoordinate<N>& c1, const GraSys::CCoordinate<N>& c2) {
	//out << c.m_x << " " << c.m_y;
	//GraSys::CCoordinate out;
	bool out;
	N a1=c1.m_x;
		N a2=c2.m_x;
		N b1=c1.m_y;
		N b2=c2.m_y;
	if((a1==a2)&&(b1==b2))out=1;
	else out=0;
	return out;
}


template<class N>
bool GraSys:: operator!= (const GraSys::CCoordinate<N>& c1, const GraSys::CCoordinate<N>& c2) {
	//out << c.m_x << " " << c.m_y;
	//GraSys::CCoordinate out;
	bool out1;
	N aa1=c1.m_x;
	N aa2=c2.m_x;
	N bb1=c1.m_y;
	N bb2=c2.m_y;
	if((aa1==aa2)&&(bb1==bb2))out1=0;
	else out1=1;
	return out1;
}
