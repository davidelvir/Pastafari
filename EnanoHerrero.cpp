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

bool EnanoHerrero::getTanque(){
  return tanque;
}

void EnanoHerrero::setTanque(bool atanque){
  tanque = atanque;
}

void EnanoHerrero::Atacar(Personaje* enemigo){
    //Ataque normal del Enano

        double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.60);
        nuevaSalud= saludEnemiga-impacto;
        enemigo->setVida(nuevaSalud);


}

void EnanoHerrero::Habilidad1(Personaje* enemigo){// Se hace tanque
    //Habilidad 1 
    tanque=true;

}

void EnanoHerrero::Habilidad2(Personaje* aliado){//Da habilidad de ataque +30 a un aliado!
    //Habilidad 2 
	double aux;
    	aux=aliado->getAtaque()+30;
 	aliado->setAtaque(aux);

}
