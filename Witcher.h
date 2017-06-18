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
	virtual void Comprar(double)=0;
	
	virtual void CortarPelo(double)=0;
	virtual void ArmaEspecial(Personaje*,Personaje*)=0;
};
#endif
//Witcher 4?
