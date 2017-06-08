#include "Noble.h"
#include "Humano.h"


Noble::Noble(){
  this->Vida=200;
  this->Defensa=100;
  this->Ataque=180;
  this->Stamina = true;
  this->Dinero=5000;
  this->Nivel=1;
  this->Experiencia=0;
  this->Bolas=0;
}

void Noble::Ataque(Personaje* enemigo){

  double damage = (Ataque * 0.5)-(enemigo->getDefensa()*0.1);
  void saludActual = enemigo->getVida();
  enemigo->setVida(saludActual - damage);
  Vida += 20;
}

void Noble::Habilidad1(Personaje* aliado){
  aliado += aliado->getVida()*0.3;
}

void Noble::Habilidad2(Personaje* aliado){
  Vida += Vida*0.8;
}
