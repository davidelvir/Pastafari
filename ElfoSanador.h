#include "Elfo.h"
#ifndef ELFOSANADOR_H
#define ELFOSANADOR_H

class ElfoSanador : public Elfo{

	ElfoSanador();
	
   virtual void Atacar(Personaje*);//enemigo
   virtual void Habilidad2(Personaje*);
   virtual void Habilidad1(Personaje*);
   virtual void Comprar(double);
   
   virtual void CortarPelo(double);
   virtual void ArmaEspecial(Personaje*,Personaje*);

};

#endif
