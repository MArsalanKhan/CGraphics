
#ifndef CCoordinate_H	
#define CCoordinate_H

#include <iostream>
using namespace std;

enum t_representation{CARTESIAN, POLAR};

enum t_quadrant{Q1, Q2, Q3, Q4};

class CCoordinate
{
	//Some binary operators
	//Implemented as C like function, therefore friend needed
	//+ with 2 CCoordinate objects
	friend CCoordinate operator+(const CCoordinate& c1, const CCoordinate& c2);

	//+ with CCoordinat and float
	friend CCoordinate operator+(const CCoordinate& c1, float c2);

	//the << operator to support cout << CCoordinate
	friend ostream& operator<<(ostream& out, const CCoordinate& c);

public:
	// Some unary operators - implemented as member, no friend needed
	CCoordinate& operator++();       // Prefix increment operator.
    CCoordinate operator++(int);     // Postfix increment operator.

private:
    float m_x;
    float m_y;

	static int m_counter;

public:

    /**
     * Constructor with default values 
     */
    CCoordinate(float x = 0, float y = 0);


	/**
     * Constructor with constant values 
     */
    CCoordinate(t_quadrant quadrant);


    /**
     * Set the Cartesian values 
     */
    void setCartesian(float x, float y);

    /**
     * Set the Coordinate using polar values 
     */
    void setPolar(float r, float phi);

    /**
     * Get the values of the coordiante either in polar or cartesian representation 
     */
    void get(t_representation format, float & val1, float & val2);

    /**
     * Pront the coordiante either in polar or cartesian representation 
     */
    void print(t_representation format);

    /**
     * Resize the coordinate: r = r * factor, phi remains unchanged 
     */
    void resize(float factor);

    /**
     * Rotate the coordiante. phi = phi + angle, r remains unchanged 
     */
    void rotate(float angle);

    /**
     * Move the coordinate: m_x = m_x + x, m_y = m_y + y 
     */
    void move(float , float y);

private:

    /**
     * Calculate Y based on a given r and phi 
     */
    float calcY(float r, float phi);

    /**
     * Calculate X based on a given r and phi 
     */
    float calcX(float r, float phi);

    /**
     * Calculate Phi based on a given x and y 
     */
    float calcPhi();

    /**
     * Calculate r based on a given x and y 
     */
    float calcR();


};

	
#endif
