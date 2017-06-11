#include <iostream>
#include <string>
#include "Personaje.h"
#include "Persona.h"

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador: public Persona{
    protected:

	Personaje* personaje;

    public:
        Jugador(string,string,string,int,string);
        Jugador();
		Personaje* getPersonaje();
		void setPersonaje(Personaje*);
};
#endif
