#include "Jugador.h"
#include "Personaje.h"
#include "Persona.h"
#include <stdio.h>
#include <string.h>

Jugador::Jugador(string nombre,string username,string contrasena,int edad,string carrera,int nivel):Persona(nombre,username,contrasena,edad,carrera){
	this->Nombre=Nombre;
    this->Username=Username;
    this->Password=Password;
    this->Edad=Edad;
    this->Carrera=Carrera;
    this->nivel=nivel;
}

Jugador::Jugador(){
	
}

Personaje* Jugador::getPersonaje(){
	return personaje;
}

void Jugador::setPersonaje(Personaje* personaje){
	this->personaje=personaje;
}

string Jugador::getN(){
	return n;
}

void Jugador::setN(string n){
	this->n=n;
}

int Jugador::getNivel(){
	return nivel;
}

void Jugador::setNivel(int nivel){
	this->nivel=nivel;
}
