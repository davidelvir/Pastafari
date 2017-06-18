#include "Humano.h"
#ifndef LADRON_H
#define LADRON_H

class Ladron : public Humano{
public:
	Ladron();

    virtual void Atacar(Personaje*);//enemigo
    virtual void Habilidad2(Personaje*);
    virtual void Habilidad1(Personaje*);

    virtual void Comprar(double);
    
    virtual void CortarPelo(double);
    virtual void ArmaEspecial(Personaje*,Personaje*);
    
};

#endif
