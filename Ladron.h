#include "Humano.h"
#ifndef LADRON_H
#define LADRON_H

class Ladron : public Humano{
  public:
    Ladron();

    virtual void Ataque(Personaje*);//enemigo
    virtual void Habilidad2(Personaje*);
    virtual void Habilidad1(Personaje*);
    
};

#endif
