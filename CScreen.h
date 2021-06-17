/////////////////////////////////////////////////////////////////////////////
// SGSE1-Labor
// CScreen.h
//
// Das h-File kann auch leer bleiben, wenn es die Aufgabe nicht erfordert,
// ein h-File zu schreiben
//
// h-Files werden im Allgemeinen für die Modularisierung von Software benötigt
// durch h-Files ist es nämlich möglich, Prototypen von Funktionen oder 
// Klassendefinitionen auch in cpp-Files zu verwenden, in denen die Funktionen 
// oder Klassen nicht implementiert sind
//

// das folgende Kontrukt verhindert, dass der Inhalt von 
// h-Files mehrfach includiert wird
//
#ifndef CScreen_H	
#define CScreen_H
#include "CSquare.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CGraphicElement.h"

enum t_graphType{SQUARE, CIRCLE, TRIANGLE, TEXT};

class CScreen
{

private:
    int m_numberElements;
    int m_maxElements;
    /**@link aggregation
     * @clientCardinality 1
     * @supplierCardinality 1..**/
    CGraphicElement** m_Element;
public:

	CScreen(int maxElements=5);
	~CScreen();

    void print();

    void addElement(t_graphType element);

  
};

	// TODO: Fügen Sie hier Funktionsprototypen oder Klassendefinitionen ein 
	
#endif
