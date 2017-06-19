#include "Administrador.h"
#include "Jugador.h"
#include "Bestia.h"
#include "Caballo.h"
#include "Burro.h"
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
#include "Ladron.h"
#include "Noble.h"
#include "Persona.h"
#include "Persona.h"
#include "Witcher.h"
#include "Batalla.h"
#include <ncurses.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

void guardarJugadorTXT(Jugador* p);
vector<Jugador*> cargarJugador(vector<Jugador*>);

int main(){

  vector <Jugador*> jugadores;
  vector <Jugador*> jugadores2;

  ifstream file("Jugador.txt");

  if(file.is_open()){
    jugadores= cargarJugador(jugadores2);
      
  } 
  
	vector <Batalla*> batallas;
  
  Personaje* Heroe = new Witcher();

  Heroe->setNombre("Alexi");

  Personaje* A1 = new Witcher();
  Personaje* A2 = new Witcher();

  A1->setNombre("Aceituno");
  A2->setNombre("Hellbert");

  Heroe->setAliado(A1);
  Heroe->setAliado(A2);
	Batalla* temp = new Batalla();

  //temp->BatallaEpica(Heroe);
  
  
return 0;	
}

void guardarJugadorTXT(Jugador* p){
  ofstream archivo;
  string ruta="Nombres.txt";
  stringstream ss;
  ss<<"Jugador.txt";   

  ruta=ss.str();
  archivo.open(ruta.c_str(),ios::app);
  
  archivo<<p->getNombre()<<endl<<p->getUsername()<<endl<< p->getPassword()<<endl<<p->getEdad()<<endl<<p->getCarrera()<<endl;
  archivo<<p->getPersonaje()->getNombre()<<endl;
  archivo<<p->getPersonaje()->getVida()<<endl;
  archivo<<p->getPersonaje()->getDefensa()<<endl;
  archivo<<p->getPersonaje()->getAtaque()<<endl;
  archivo<<p->getPersonaje()->getReputacion()<<endl;
  archivo<<p->getPersonaje()->getNivel()<<endl;
  archivo<<p->getPersonaje()->getExp()<<endl;
  archivo<<p->getPersonaje()->getBolas()<<endl;
  archivo<<p->getPersonaje()->getReputacion()<<endl;
  archivo<<p->getPersonaje()->getEstiloCabello()<<endl;
  archivo<<p->getPersonaje()->getDinero()<<endl;
  
  archivo.close();
    
}

vector<Jugador*> cargarJugador(vector<Jugador*> jugadores){
    ifstream file("Jugador.txt");

    for (int i = 0; i < jugadores.size(); ++i){
        file>>*jugadores[i];
    }

    return jugadores;
}

