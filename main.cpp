// Header-Dateien
#include <iostream>				
#include <stdlib.h>


using namespace std;			

// Da generierte headerfile wird includiert 
#include "CScreen.h"	


int main (void)
{

	CScreen myScreen(5);

	myScreen.addElement(SQUARE);
	myScreen.addElement(CIRCLE);
	myScreen.addElement(SQUARE);

	myScreen.print();

	return EXIT_SUCCESS;		
}
