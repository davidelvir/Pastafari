#include "Burro.h"
#include "Bestia.h"
Burro::Burro(){
}
Burro::Burro(string color, double tamanoOreja,string nombre): Bestia(nombre){
	this->color=color;
	this->tamanoOreja=tamanoOreja;
}
string Burro::getColor(){
	return color;
}
void Burro::setColor(string color){
	this->color=color;
}
double Burro::getTamanoOreja(){
	return tamanoOreja;
}
void Burro::setTamanoOreja(double tamanoOreja){
	this->tamanoOreja=tamanoOreja;
}	
