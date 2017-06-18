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

	virtual void Comprar(double);
	
	virtual void CortarPelo(double);
	virtual void ArmaEspecial(Personaje*,Personaje*);


};
#endif
