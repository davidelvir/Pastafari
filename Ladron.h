#include "Humano.h"
#ifndef LADRON_H
#define LADRON_H

class Ladron : public Humano{
public:
	Ladron();

    virtual void Atacar(Personaje*);//enemigo
    virtual void Habilidad2(Personaje*);
    virtual void Habilidad1(Personaje*);

    virtual void Comprar(double)=0;
    .
    virtual void CortarPelo(double)=0;
    virtual void ArmaEspecial(Personaje*,Personaje*)=0;
    
};

#endif
