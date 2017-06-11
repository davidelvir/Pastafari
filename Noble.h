#include "Humano.h"
#ifndef NOBLE_H
#define NOBLE_H

class Noble : public Humano{
  public: 
    Noble();
    virtual void Atacar(Personaje*);
    virtual void Habilidad1(Personaje*);
    virtual void Habilidad2(Personaje*);

};

#endif
