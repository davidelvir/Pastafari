#include "Humano.h"
#ifndef LADRON_H
#define LADRON_H

class Ladron : public Humano{
  public:
    Ladron();

    virtual void Ataque(Personaje*)=0;//enemigo
    virtual void Habilidad2(Personaje*)=0;
    virtual void Habilidad1(Personaje*)=0;
    
};

#endif
