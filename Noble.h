#include "Humano.h"
#ifndef NOBLE_H
#define NOBLE_H

class Noble : public Humano{
  public: 
    Noble();
    virtual void Ataque(Personaje*);
    virtual void Habilidad1(Personaje*);
    virtual void Habilidad2(Personaje*);

};

#endif
