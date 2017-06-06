#include "Administrador.h"
#include "Persona.h"
#include "Jugador.h"
#include <iostream>
#include <string>

using namespace std;
Administrador::Administrador(string Nombre,string Username,string Password,int Edad,string Carrera){

	this->Nombre=Nombre;
    this->Username=Username;
    this->Password=Password;
    this->Edad=Edad;
    this->Carrera=Carrera;

}

Administrador::Administrador(){


}

void Administrador::EliminarUsuario(vector<Jugador*>& jugadores){
	//Falta crear aqui metodo para eliminar un solo usuario
  int opcion;
  cout<<"Elija la posicion que desea eliminar: ";  
  for(int i=0; i<jugadores.size();i++){
    cout<<i<<jugadores[i]->getNombre()<<endl;
  }
  cin>>opcion;

  jugadores.erase(jugadores.begin()+opcion);
}

void Administrador::AgregarUsuario(vector <Jugador*>& jugadores,Jugador* jugador){
	//falta crea metodo para agregar un jugador;
  jugadores.push_back(jugador);

}


//void Administrador::AutoDestruir(vector <Jugador*> jugadores){
	//falta aqui crear el metodo para chingar todo
	


//}
















