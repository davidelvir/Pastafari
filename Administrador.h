#include <iostream>
#include <string>
#include "Persona.h"
#include "Jugador.h"
#include <vector>

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador:public Persona{
    protected:
    
    	

    public:
        Administrador(string,string,string,int,string);
        Administrador();
	
		void EliminarUsuario(vector<Jugador*>&);
		void AgregarUsuario(vector<Jugador*>&,Jugador*);
		//void AutoDestruir(vector <Jugador*>);
			
		
};
#endif
