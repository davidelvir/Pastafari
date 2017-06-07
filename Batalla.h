#include <string>
#include <vector>
#include "Personaje.h"

#ifndef BATALLA_H
#define BATALLA_H
class Batalla{
    protected:

       vector<Personaje*>enemigos;

    public:
        
        Batalla();

        void BatallaEpica(Personaje*);//el vector es de los enemigos, y el personaje es el principal que contiene su vector de aliados




};
#endif
