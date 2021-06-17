

#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <string>
#include "CGraphicElement.h"


class CCircle : public CGraphicElement {
private:
    float m_r;
public:

    void setCorner();

    void print(); //without the own print, the radius would not be printed




    CCircle(float x=0, float y=0, float r=0, string color="DefaultColorCircle");
};
/********************
**  CLASS END
*********************/
#endif /* CCIRCLE_H */
