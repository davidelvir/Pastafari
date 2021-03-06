#include <iostream>
#include <string>
#include "Personaje.h"
#include "Persona.h"
#include "Witcher.h"
#include "Guerrero.h"
#include "ElfoGuerrero.h"

using namespace std;

#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador: public Persona{
    protected:

	Personaje* personaje;
	string n;
	int nivel;

    public:
        Jugador(string,string,string,int,string, int);
        Jugador();
		Personaje* getPersonaje();
		void setPersonaje(Personaje*);

		string getN();
		void setN(string);

		int getNivel();
		void setNivel(int);

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

			char buffer5[256];
			in.getline(buffer5, 256);
			jugador.setN(buffer5);


			in>>jugador.nivel;
			in.ignore(1, '\n');
	
			/*if(n=="w"){

				jugador.setPersonaje(new Witcher());
			}
			if(n=="g"){
				jugador.setPersonaje(new Guerrero());	
			}
			if(n=="e"){
				jugador.setPersonaje(new ElfoGuerrero());
			}
	
			in >> *jugador.personaje;
			
			*/
			return in;
		}

};
#endif





