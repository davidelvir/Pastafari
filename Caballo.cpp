#include "Bestia.h"
#include "Caballo.h"

Caballo::Caballo(){

}

Caballo::Caballo(string color, string nombre): Bestia(nombre){
	this->color=color;
}
string Caballo::getColor(){
	return color;
}
void Caballo::setColor(string color){
	this->color=color;
}

