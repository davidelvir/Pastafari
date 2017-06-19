#include "Personaje.h"
#include "Item.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Personaje::Personaje(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello,double Dinero){

	this->Nombre=Nombre;
	this->Vida=Vida;
	this->Defensa=Defensa;
	this->Ataque=Ataque;
	this->Reputacion=Reputacion;
	this->Nivel=Nivel;
	this->Experiencia=Experiencia;
	this->Bolas=Bolas;
	this->estiloCabello=estiloCabello;
	this->Stamina=true;
	this->Dinero=Dinero;
}

Personaje::Personaje(){
	
}

//se necesita un getAliado que retorne el arraylist, para poder tener el tamaño del arraylist ;
//y asi en el metodo batalla hacer un for que recorra ese arreglo, para poder listarlos;

Personaje* Personaje::getAliado(int pos){
	return Aliados[pos];
}

void Personaje:: setAliado(Personaje* aliado){
	Aliados.push_back(aliado);
}

vector<Personaje*>& Personaje::getAliados(){
	return Aliados;
}
double Personaje::getDinero(){
	return Dinero;
}
void Personaje::setDinero(double pDinero){
	Dinero = pDinero;
}

string Personaje::getNombre(){
	return Nombre;
}
void Personaje::setNombre(string pNombre){
	Nombre = pNombre;
}

double Personaje::getVida(){
	return Vida;
}
void Personaje::setVida(double pVida){
	Vida = pVida;
}

double Personaje::getDefensa(){
	return Defensa;
}
void Personaje::setDefensa(double pDefensa){
	Defensa = pDefensa;
}

double Personaje::getAtaque(){
	return Ataque;
}
void Personaje::setAtaque(double pAtaque){
	Ataque = pAtaque;
}

string Personaje::getReputacion(){
	return Reputacion;
}
void Personaje::setReputacion(string pReputacion){
	Reputacion = pReputacion;
}

int Personaje::getNivel(){
	return Nivel;
}
void Personaje::setNivel(int pNivel){
	Nivel = pNivel;
}

bool Personaje::getStamina(){
	return Stamina;
}

void Personaje::setStamina(bool pStamina){
	Stamina = pStamina;
}

int Personaje::getExp(){return Experiencia;}
void Personaje::setExp(int exp){Experiencia = exp;}

string Personaje::getEstiloCabello(){return estiloCabello;}
void Personaje::setEstiloCabello(string estilo){estiloCabello = estilo;}

int Personaje::getBolas(){return Bolas;}
void Personaje::setBolas(int bolas){Bolas = bolas;}

string Personaje::Provocar(){return "Inútil!!";}
