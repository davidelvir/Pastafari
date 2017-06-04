#include "Personaje.h"
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

Personaje::Personaje(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello,double Dinero){

	  this->Nombre=Nombre;
    this->Vida=Vida;
    this->Defensa=Defensa;
    this->Ataque=Ataque;
    this->Reputacion=Reputacion;
	  this->Nivel=Nivel;
    this->Experiencia=Experiencia;
    this->Bolas=Bolas;
    this->estiloCabello=estiloCabello;
    this->Stamina=true;
    this->Dinero=Dinero;
}

Personaje::Personaje(){
	
}

double Personaje::getDinero(){
  return Dinero;
}
void Personaje::setDinero(double pDinero){
  Dinero = pDinero;
}

string Personaje::getNombre(){
	return Nombre;
}
void Personaje::setNombre(string pNombre){
	Nombre = pNombre;
}

double Personaje::getVida(){
	return Vida;
}
void Personaje::setVida(double pVida){
	Vida = pVida;
}

double Personaje::getDefensa(){
	return Defensa;
}
void Personaje::setDefensa(double pDefensa){
	Defensa = pDefensa;
}

double Personaje::getAtaque(){
	return Ataque;
}
void Personaje::setAtaque(double pAtaque){
	Ataque = pAtaque;
}

string Personaje::getReputacion(){
	return Reputacion;
}
void Personaje::setReputacion(string pReputacion){
	Reputacion = pReputacion;
}

int Personaje::getNivel(){
	return Nivel;
}
void Personaje::setNivel(int pNivel){
	Nivel = pNivel;
}
