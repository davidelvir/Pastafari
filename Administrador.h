#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador:public Persona{
    protected:
    	

    public:
        Administrador(string,string,string,int,string);
        Administrador();
	
		//void EliminarUsuario(vector<Jugador*>);
		//void AgregarUsuario(vector <Jugador*>);
		//void AutoDestruir(vector <Jugador*>);
			
		
};
#endif
