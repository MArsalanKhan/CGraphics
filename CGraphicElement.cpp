// SGSE1-Labor
// CGraphicElement.cpp

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>				// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
	

using namespace std;			// erspart, den scope vor Objekte der C++-Standard-Bibliothek zu schreiben
								// z.B. statt "std::cout" kann man "cout" schreiben

// Ihr eigenes h-File wird includiert 
#include "CGraphicElement.h"		
#include "CCoordinate.h"

////////////////////////////////////////////////////////////////////////////////
// Funktionen oder Klassen

// TODO: Implementieren Sie hier die Funktionen der Klassen

CGraphicElement::CGraphicElement(int numberCorners, string color, string type)
{
	//Without range checking, only straight forward code
	m_numberCorners = numberCorners;
	m_color = color;
	m_type = type;
	m_coordinate = new CCoordinate[m_numberCorners];

	//Generate some output
	//print();
}

CGraphicElement::~CGraphicElement()
{
delete[] m_coordinate;
}

void CGraphicElement::move(float x , float y)
{
	for (int i = 0; i<m_numberCorners; i++)
	{
		m_coordinate[i].move(x, y);
	}
}


void CGraphicElement::print()
{
	cout << "GENERAL: Printing Graphic Element '" << m_type << "' with " << m_numberCorners << " corners at " << endl;

	for (int i = 0; i<m_numberCorners; i++)
	{
		cout << m_coordinate[i] << endl;
	}

}

void CGraphicElement::setCorner(int corner, float x, float y)
{
	if (corner < m_numberCorners)
	{
		m_coordinate[corner].setCartesian(x,y);
	}
	else
	{
		cout << "WARNING in CGraphicElement::setCorner - invalid Corner" << endl;
	}
}
void CGraphicElement::setCorner()
{
	int x, y;
	cout << "General CGraphicElement::setCorner()" << endl;
	for (int i=0; i<this->m_numberCorners; i++)
	{
		cout << "Enter corner: " << i << " (x,y) = ";
		cin >> x >> y;
		cout << endl;

		setCorner(i,x,y);
	}
}
