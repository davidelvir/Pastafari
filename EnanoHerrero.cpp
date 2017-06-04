#include "Personaje.h"
#include "EnanoHerrero.h"
#include <string>

using namespace std;

EnanoHerrero::EnanoHerrero(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello,double Dinero,string ColorBarba, double TamanoBarba){

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

EnanoHerrero::EnanoHerrero(){
	
}
