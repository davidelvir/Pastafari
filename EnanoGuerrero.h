#include <iostream>
#include <string>
#include "Personaje.h"
#include "Enano.h"

using namespace std;

#ifndef ENANOGUERRERO_H
#define ENANOGUERRERO_H

class EnanoGuerrero: public Enano{
    protected:

    public:
        
        EnanoGuerrero(string, double,double,double,string,int,int,int,string,double,string,double);
        EnanoGuerrero();

    
};
#endif
