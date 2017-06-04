#ifndef CABALLO_H
#define CABALLO_H
#include "Bestia.h"

class Caballo:public Bestia{
	private:
		string color;	
	public:
		Caballo();
		Caballo(string,string);

		string getColor();
		void setColor(string);
};
#endif
