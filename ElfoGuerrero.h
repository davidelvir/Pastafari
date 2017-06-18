#include "Elfo.h"
#ifndef ELFOGUERRERO_H
#define ELFOGUERRERO_H

class ElfoGuerrero : public Elfo{
public: 

	ElfoGuerrero();

  virtual void Atacar(Personaje*);//enemigo
  virtual void Habilidad2(Personaje*);
  virtual void Habilidad1(Personaje*);
  /*virtual void Comprar(double)=0;
  .
  virtual void CortarPelo(double)=0;
  virtual void ArmaEspecial(Personaje*,Personaje*)=0;*/
};

#endif
