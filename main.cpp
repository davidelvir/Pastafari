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
using namespace std;

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

  temp->BatallaEpica(Heroe);

	cout <<"HOLA";

	


return 0;	
}
