#include "Personaje.h"
#include "EnanoGuerrero.h"
#include <string>

using namespace std;

EnanoGuerrero::EnanoGuerrero(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello,double Dinero,string ColorBarba, double TamanoBarba){

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
    this->ColorBarba=ColorBarba;
    this->TamanoBarba=TamanoBarba;
}

EnanoGuerrero::EnanoGuerrero(){
	
}

void EnanoGuerrero::Ataque(Personaje* enemigo){
    //Ataque normal del ladron

        double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.20);
        nuevaSalud= saludEnemiga-impacto;
        enemigos->setVida(nuevaSalud);


}

void EnanoGuerrero::Habilidad1(Personaje* enemigo){// roba dinero y salud al enemigo
    //Habilidad EGuerrero
        double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque;
        nuevaSalud= saludEnemiga-impacto;
        enemigos->setVida(nuevaSalud);

}

void EnanoGuerrero::Habilidad2(Personaje* enemigo){//El golpe tiene probabilidad de critico
    //Chance de stun de 2 turnos randomly

    #include <ctime>
    #include <cstdlib>

    srand(time(0));
    stun =rand()%13;
     
    double impacto;
    double saludEnemiga;
    double defensaEnemiga;
    double nuevaSalud;
        
    if(stun%3==0){
        enemigo->setStamina(false);

     } else{

        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.35);
        nuevaSalud= saludEnemiga-impacto;
        enemigos->setVida(nuevaSalud);

     }







}

