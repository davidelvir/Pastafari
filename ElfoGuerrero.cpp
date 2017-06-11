#include "Elfo.h"
#include "ElfoGuerrero.h"

ElfoGuerrero::ElfoGuerrero(){

  this->Vida = 300;
  this->Defensa = 250;
  this->Ataque = 300;
  this->Stamina = true;
  this->Dinero = 0;
  this->Nivel = 1;
  this->Experiencia = 0;
  this->Bolas = 0;

}
void ElfoGuerrero::Atacar(Personaje* enemigo){
	//Ataque normal del Elfo

		double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.50);
        nuevaSalud= saludEnemiga-impacto;
        enemigo->setVida(nuevaSalud);


}

void ElfoGuerrero::Habilidad1(Personaje* LaMepen ){//s roba dinero y salud al enemigo

	//Habilidad 1 del ladron

	double impacto;
    double saludEnemiga;
    double defensaEnemiga;
    double nuevaSalud;
    if(Vida>0)
    Vida = (Vida * 0.20)+ Vida;


}

void ElfoGuerrero::Habilidad2(Personaje* enemigo){//El golpe tiene probabilidad de critico
	//Habilidad 2 del ladron


		double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.50);
        nuevaSalud= saludEnemiga-impacto;
        enemigo->setVida(nuevaSalud);

}

