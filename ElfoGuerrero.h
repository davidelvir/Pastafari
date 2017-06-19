#include "Elfo.h"
#ifndef ELFOGUERRERO_H
#define ELFOGUERRERO_H
#include <iostream>
using namespace std;

class ElfoGuerrero : public Elfo{
public: 

	ElfoGuerrero();

  virtual void Atacar(Personaje*);//enemigo
  virtual void Habilidad2(Personaje*);
  virtual void Habilidad1(Personaje*);
  virtual void Comprar(double);
  
  virtual void CortarPelo(double);
  virtual void ArmaEspecial(Personaje*,Personaje*);

  virtual string Provocar();
};

#endif
