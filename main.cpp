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

int main(){

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
  
	cout <<"HOLA";

  vector <Jugador*> jugadores;

  Jugador* prueba = new Jugador();
  Jugador* prueba2 = new Jugador();


  jugadores.push_back(prueba);
  jugadores.push_back(prueba2);

  ifstream file("Jugador.txt");

  if(file.is_open()){
    for (int i = 0; i < jugadores.size(); ++i){
        file>>*jugadores[i];
    }
      
  } 
  file.close();

  cout << "Jugador 1"<<endl;
  cout << jugadores[0]->getNombre()<<endl;
  cout << jugadores[0]->getUsername()<<endl;
  cout << jugadores[0]->getPassword()<<endl;
  cout << jugadores[0]->getEdad()<<endl;
  cout << jugadores[0]->getCarrera()<<endl;

  cout<<" "<<endl;

  cout << "Jugador 2"<<endl;
  cout << jugadores[1]->getNombre()<<endl;
  cout << jugadores[1]->getUsername()<<endl;
  cout << jugadores[1]->getPassword()<<endl;
  cout << jugadores[1]->getEdad()<<endl;
  cout << jugadores[1]->getCarrera()<<endl;



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
  archivo.close();
    
}
