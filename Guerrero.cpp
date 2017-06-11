#include "Humano.h"
#include "Guerrero.h"	

Guerrero::Guerrero(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello, string Color, double Dinero){
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
    this->Color=Color;
    this->Dinero=Dinero;
}

Guerrero::Guerrero(){

	this->Vida=300;
	this->Defensa=150;
	this->Ataque=200;
	this->Stamina=true;
	this->Dinero=0;
	this->Nivel=1;
	this->Experiencia=0;
	this->Bolas=0;

}

void Guerrero::Atacar(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.5);
  double saludActual = enemigo->getVida();
  enemigo->setVida(saludActual - damage);
}

void Guerrero::Habilidad1(Personaje* enemigo){
  double saludActual = enemigo->getVida();
  double damage = Ataque * 0.2;
  enemigo->setVida(saludActual - damage);
}

void Guerrero::Habilidad2(Personaje* enemigo){
  enemigo->setStamina(false);
}
