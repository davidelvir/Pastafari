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

<<<<<<< HEAD
	virtual void Ataque(Personaje*);//enemigo
  	virtual void Habilidad2(Personaje*);
  	virtual void Habilidad1(Personaje*);
=======

        bool getTanque();
        void setTanque(bool);


    	virtual void Ataque(Personaje*)=0;//enemigo
    	virtual void Habilidad2(Personaje*)=0;
    	virtual void Habilidad1(Personaje*)=0;
>>>>>>> cde9b653352e70652e1700fa4a30db775ed6adbf
    
};
#endif
