// SGSE1-Labor
// CScreen.cpp

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>				// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
	// TODO: Fügen Sie hier weitere benötigte Header-Dateien ein


using namespace std;			// erspart, den scope vor Objekte der C++-Standard-Bibliothek zu schreiben
								// z.B. statt "std::cout" kann man "cout" schreiben

// Ihr eigenes h-File wird includiert 
#include "CScreen.h"		

////////////////////////////////////////////////////////////////////////////////
// Funktionen oder Klassen

// TODO: Implementieren Sie hier die Funktionen der Klassen

CScreen::CScreen(int maxElements)
{

	m_maxElements = maxElements;
	m_numberElements = 0;

	//Allocate memory for pointers to graphical objects
	m_Element = new CGraphicElement*[m_maxElements];

}

CScreen::~CScreen()
{
	//Delete the individual elements
	for (int i = 0; i < m_numberElements; i++)
	{
		delete m_Element[i];
	}
	delete[] m_Element;
}

void CScreen::addElement(t_graphType element)
{
	if (m_numberElements < m_maxElements)
	{
		cout << "Adding element number " << m_numberElements << " of type ";
		
		switch (element)
		{
		case SQUARE : m_Element[m_numberElements] = new CSquare;
			cout << "Square"<<endl;
			break;
		case CIRCLE : m_Element[m_numberElements] = new CCircle;
			cout << "Circle" << endl;
			break;
		case TRIANGLE : m_Element[m_numberElements] = new CTriangle;
			cout << "TRIANGLE" << endl;
			break;
		default : cout << "WARNING - type not implemented yet" << endl;
			m_numberElements--;
		}

		//Use RTTI to detect the type of object
		CCircle* p = dynamic_cast <CCircle *> (m_Element[m_numberElements]);
		if (p!=0)
		{
			cout << "Object is a circle - specialised variant of setCorner() will be used" << endl;
		}

		//Add the coordinates
		m_Element[m_numberElements]->setCorner();

		//Increment the counter
		m_numberElements++;
	}
}

void CScreen::print()
{
	for (int i=0; i<m_numberElements; i++)
	{
		m_Element[i]->print();
	}
}