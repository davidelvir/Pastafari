#include <iostream>
#include <string>
#include "Personaje.h"
#include "Enano.h"

using namespace std;

#ifndef ENANOHERRERO_H
#define ENANOHERRERO_H
class EnanoHerrero: public Enano{
    protected:
        
    	bool tanque=false;

    public:
        
        EnanoHerrero(string, double,double,double,string,int,int,int,string,double,string,double);
        EnanoHerrero();


	virtual void Atacar(Personaje*);//enemigo
  	virtual void Habilidad2(Personaje*);
  	virtual void Habilidad1(Personaje*);


        bool getTanque();
        void setTanque(bool);


    
};
#endif
