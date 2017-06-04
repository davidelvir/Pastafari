#include <iostream>
#include <string>
#include "Personaje.h"

using namespace std;

#ifndef ENANO_H
#define ENANO_H
class Enano: public Personaje{
    protected:

        string ColorBarba;
        double TamanoBarba;

    public:
        
        Enano(string, double,double,double,string,int,int,int,string,double, string, double);
        Enano();


        double getTamanoBarba();
        void setTamanoBarba(double);

        string getColorBarba();
        void setColorBarba(string);



};
#endif
