#include "Dragon.h"
#include "Bestia.h"
Dragon::Dragon(){
}

Dragon::Dragon(string color,string nombre): Bestia(nombre){
	this->color=color;	
}
string Dragon::getColor(){
	return color;	
}
void Dragon::setColor(string color){
	this->color=color;
}
