#include "Elfo.h"
#ifndef ELFOGUERRERO_H
#define ELFOGUERRERO_H

class ElfoGuerrero : public Elfo{
  public: 

  ElfoGuerrero();

  virtual void Atacar(Personaje*);//enemigo
  virtual void Habilidad2(Personaje*);
  virtual void Habilidad1(Personaje*);
};

#endif
