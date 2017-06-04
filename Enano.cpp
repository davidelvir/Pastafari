#include "Personaje.h"
#include "Enano.h"
#include <string>

using namespace std;

Enano::Enano(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello,double Dinero,string ColorBarba, double TamanoBarba){

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
    this->ColorBarba=ColorBarba;
    this->TamanoBarba=TamanoBarba;
}

Enano::Enano(){
	
}

double Enano::getTamanoBarba(){
  return TamanoBarba;
}

void Enano::setTamanoBarba(double TamanoBarba){
  this->TamanoBarba = TamanoBarba;
}

string Enano::getColorBarba(){
	return ColorBarba;
}
void Enano::setColorBarba(string ColorBarba){
	this->ColorBarba = ColorBarba;
}
