//includes
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
//include clases
#include "Administrador.h"
#include "Batalla.h"
#include "Bestia.h"
#include "Burro.h"
#include "Caballo.h"
#include "Dragon.h"
#include "Elfo.h"
#include "ElfoGuerrero.h"
#include "ElfoSanador.h"
#include "Enano.h"
#include "EnanoGuerrero.h"
#include "EnanoHerrero.h"
#include "Guerrero.h"
#include "Humano.h"
#include "Item.h"
#include "Jugador.h"
#include "Ladron.h"
#include "Noble.h"
#include "Persona.h"
#include "Personaje.h"
#include "Witcher.h"
#include "stdlib.h"
#include <vector>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#ifndef PASTAFARI_H
#define PASTAFARI_H

using namespace std;

class Pastafari{
	private:
		Jugador* jugadorRaiz;
		Jugador* jugadorTemp;
		Jugador* jugadorTemp2;
		Jugador* cualquiera;
		Administrador* adminRaiz;
		vector<Jugador*> jugadores;
		
	public:
		Pastafari();
		void run();
		void limpiarPantalla();
		void historia();
		int menuJugador();
		int menu();
		int menuPersonaje();
		Jugador* agregarJugador(vector<Jugador*> jugadores);
		void listarJugadores(vector<Jugador*>);
		void sleep(int);


};

#endif