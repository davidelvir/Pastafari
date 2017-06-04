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

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){

  Administrador a;

  a.setNombre("jah");

  cout<<a.getNombre();

  return 0;
}
