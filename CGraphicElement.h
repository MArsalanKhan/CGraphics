/////////////////////////////////////////////////////////////////////////////
// SGSE1-Labor
// CGraphicElement.h
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
#ifndef CGraphicElement_H	
#define CGraphicElement_H

#include <string>
#include "CCoordinate.h"

class CGraphicElement
{
private:
    string m_type;
	string m_color;
    int m_numberCorners;
protected:
    /**
     * @link aggregationByValue
     * @supplierCardinality 1..*
     * @clientCardinality 1 
     */
    CCoordinate* m_coordinate;
public:

    CGraphicElement(int numberCorners = 1, string color = "white", string type = "BasicElement");

    ~CGraphicElement();
    virtual void print();  //Without virtual, the general function will be called always
    virtual void setCorner();
    void setCorner(int corner, float x, float y);
    virtual void move(float x , float y);
};

	// TODO: Fügen Sie hier Funktionsprototypen oder Klassendefinitionen ein 
	
#endif
