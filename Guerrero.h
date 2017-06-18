#include <iostream>
#include <string>
#include "Humano.h"

using namespace std;

#ifndef Guerrero_H
#define Guerrero_H

class Guerrero:public Humano{

protected:


public:

	Guerrero(string, double,double,double,string,int,int,int,string, string, double);
	Guerrero();

	virtual void Atacar(Personaje*);
	virtual void Habilidad1(Personaje*);
	virtual void Habilidad2(Personaje*);

	/*virtual void Comprar(double)=0;
	.
	virtual void CortarPelo(double)=0;
	virtual void ArmaEspecial(Personaje*,Personaje*)=0;*/


};
#endif
