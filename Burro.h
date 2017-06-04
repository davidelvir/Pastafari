#ifndef BESTIA_H
#define BESTIA_H
#include "Bestia.h"
#include "Item.h"
using namespace std;

class Burro:public Bestia{
	private:
		string color;
		double tamanoOreja;
	public:
		Burro();
		Burro(string,double,string);

		string getColor();
		void setColor(string);
		
		double getTamanoOreja();
		void setTamanoOreja(double);	
		

};
#endif
