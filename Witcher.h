#include <iostream>
#include <string>
#include "Humano.h"

using namespace std;

#ifndef Witcher_H
#define Witcher_H

class Witcher:public Humano{

protected:


public:

	Witcher(string, double,double,double,string,int,int,int,string, string, double);
	Witcher();
	virtual void Atacar(Personaje*);
	virtual void Habilidad1(Personaje*);
	virtual void Habilidad2(Personaje*);
	virtual void Comprar(double);
	
	virtual void CortarPelo(double);
	virtual void ArmaEspecial(Personaje*,Personaje*);
};
#endif
//Witcher 4?
