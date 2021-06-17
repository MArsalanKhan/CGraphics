/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        :
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <string>
#include "CGraphicElement.h"

class CTriangle : public CGraphicElement {
public:

    CTriangle(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0, float x3 = 0, float y3 = 0, string color = "DefaultColorTriangle");
};
/********************
**  CLASS END
*********************/
#endif /* CTRIANGLE_H */
