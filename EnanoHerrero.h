#include <iostream>
#include <string>
#include "Personaje.h"
#include "Enano.h"

using namespace std;

#ifndef ENANOHERRERO_H
#define ENANOHERRERO_H
class EnanoHerrero: public Enano{
    protected:
        
    public:
        
        EnanoHerrero(string, double,double,double,string,int,int,int,string,double,string,double);
        EnanoHerrero();

    
};
#endif
