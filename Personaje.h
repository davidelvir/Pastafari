#include <string>
#include <vector>
#include "Item.h"
#include "Bestia.h"
#include <fstream>

using namespace std;

#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje{
protected:
	string Nombre;
	double Vida;
	double Defensa;
	double Ataque;
	string Reputacion;
	int Nivel;
	int Experiencia;
	vector<Item*>Bolsa;
	int Bolas;
	vector<Personaje*>Aliados;
	vector<Bestia*>Bestias;
	Item Armadura;
	Item Arma;
	bool Stamina;
	string estiloCabello;
	double Dinero;

public:

	Personaje(string, double,double,double,string,int,int,int,string,double);
	Personaje();

        //Set y Get de Aliados;

	Personaje* getAliado(int);

	vector<Personaje*>& getAliados();

	void setAliado(Personaje*);

        //_________________________________

	bool getStamina();
	void setStamina(bool);

	int getExp();
	void setExp(int);

	string getEstiloCabello();
	void setEstiloCabello(string);

	int getBolas();
	void setBolas(int);

	double getDinero();
	void setDinero(double);

	string getNombre();
	void setNombre(string);

	double getVida();
	void setVida(double);

	double getDefensa();
	void setDefensa(double);

	double getAtaque();
	void setAtaque(double);

	string getReputacion();
	void setReputacion(string);

	int getNivel();
	void setNivel(int);

	virtual void Atacar(Personaje*)=0;
	virtual void Habilidad2(Personaje*)=0;
	virtual void Habilidad1(Personaje*)=0;

	virtual void Comprar(double)=0;
	
	virtual void CortarPelo(double)=0;
	virtual void ArmaEspecial(Personaje*,Personaje*)=0;

	friend istream& operator >> (istream& in, Personaje& personaje){
		char buffer[256];
		in.getline(buffer, 256);
		personaje.Nombre = buffer;

		in >> personaje.Vida;
		in.ignore(1, '\n');

		in >> personaje.Defensa;
		in.ignore(1, '\n');

		in >> personaje.Ataque;
		in.ignore(1, '\n');


		char buffer2[256];
		in.getline(buffer2, 256);
		personaje.Reputacion = buffer2;

		in >> personaje.Nivel;
		in.ignore(1, '\n');

		in >> personaje.Experiencia;
		in.ignore(1, '\n');

		in >> personaje.Bolas;
		in.ignore(1, '\n');

		char buffer3[256];
		in.getline(buffer3, 256);
		personaje.estiloCabello = buffer3;


		in >> personaje.Dinero;
		in.ignore(1, '\n');

		return in;
	}   

};
#endif
