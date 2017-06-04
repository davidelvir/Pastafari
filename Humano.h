#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

#ifndef HUMANO_H
#define HUMANO_H

class Humano:public Personaje{

    protected:

	string Color;

    public:
        
    	Humano(string, double,double,double,string,int,int,int,string, string,double);
        Humano();
        string getColor();
        void setColor(string);

    //virtual void Ataque(Personaje*,Personaje*)=0;

};
#endif
