#include "Elfo.h"
#ifndef ELFOSANADOR_H
#define ELFOSANADOR_H

class ElfoSanador : public Elfo{

   ElfoSanador();
	
   virtual void Ataque(Personaje*);//enemigo
   virtual void Habilidad2(Personaje*);
   virtual void Habilidad1(Personaje*);

};

#endif
