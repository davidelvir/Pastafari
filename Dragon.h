#ifndef DRAGON_H
#define DRAGON_H
#include "Bestia.h"
using namespace std;

class Dragon : public Bestia{
	private:
		string color;
	public:
		Dragon(string, string);
		Dragon();
		
		string getColor();
		void setColor(string);

};
#endif
