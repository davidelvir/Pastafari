#ifndef BESTIAS_H
#define BESTIAS_H
#include "Item.h"
#include<string>
#include <vector>

using namespace std;
class Bestia
{
	protected:
		vector<Item*> items;
		string nombre;
	public:
		Bestia();
		Bestia(string);

		Item* getItem(int);
		
		void setItem(Item* item,int);
		
		string getNombre();
		void setNombre(string nombre);				

};
#endif
