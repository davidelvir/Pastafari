#include "Humano.h"
#include "Witcher.h"	

Witcher::Witcher(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello, string Color, double Dinero){
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

Witcher::Witcher(){

	this->Vida=300;
	this->Defensa=300;
	this->Ataque=350;
	this->Stamina=true;
	this->Dinero=0;
	this->Nivel=1;
	this->Experiencia=0;
	this->Bolas=0;

}

void Witcher::Atacar(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.25);
  double vidaActual = enemigo->getVida();

  enemigo->setVida(vidaActual-damage);
}

void Witcher::Habilidad1(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.6);
  double vidaActual = enemigo->getVida();

  enemigo->setVida(vidaActual-damage);
}

void Witcher::Habilidad2(Personaje* enemigo){
  Ataque+=Ataque*0.05;
  Defensa+=Defensa*0.05;
}
