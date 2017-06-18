#include "Humano.h"
#ifndef NOBLE_H
#define NOBLE_H

class Noble : public Humano{
public: 
	Noble();
	virtual void Atacar(Personaje*);
	virtual void Habilidad1(Personaje*);
	virtual void Habilidad2(Personaje*);
	virtual void Comprar(double)=0;
	
	virtual void CortarPelo(double)=0;
	virtual void ArmaEspecial(Personaje*,Personaje*)=0;

};

#endif
