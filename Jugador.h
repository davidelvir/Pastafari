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

		friend istream& operator >> (istream& in, Jugador& jugador){
			char buffer[256];
			in.getline(buffer, 256);
			jugador.Nombre = buffer;
			
			char buffer2[256];
			in.getline(buffer2, 256);
			jugador.Username = buffer2;
			

			char buffer3[256];
			in.getline(buffer3, 256);
			jugador.Password = buffer3;
			
			in >> jugador.Edad;

			in.ignore(1, '\n');
			
			char buffer4[256];
			in.getline(buffer4, 256);
			jugador.Carrera = buffer4;



			return in;
		}

};
#endif
