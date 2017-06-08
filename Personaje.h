#include <string>
#include <vector>
#include "Item.h"
#include "Bestia.h"

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

        virtual void Ataque(Personaje*)=0;
        virtual void Habilidad2(Personaje*)=0;
        virtual void Habilidad1(Personaje*)=0;
        /*virtual void Comprar(double)=0;
        virtual void CortarPelo(double)=0;
        virtual void ArmaEspecial(Personaje*,Personaje*)=0;*/
        

};
#endif
