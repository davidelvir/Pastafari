#include "Ladron.h"

Ladron::Ladron(){

  this->Vida=300;
  this->Defensa=150;
  this->Ataque=200;
  this->Stamina=true;
  this->Dinero=0;
  this->Nivel=1;
  this->Experiencia=0;
  this->Bolas=0;
}

void Ladron::Ataque(Personaje* enemigo){
	//Ataque normal del ladron

		double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto;
        enemigos->setVida(nuevaSalud);


}

void Ladron::Habilidad1(Personaje* enemigo){// roba dinero y salud al enemigo
	//Habilidad 1 del ladron

	double impacto;
    double saludEnemiga;
    double defensaEnemiga;
    double nuevaSalud;
    

    saludEnemiga= enemigo->getVida();
    nuevaSalud= enemigo->getVida()*0.10;
    enemigos->setVida(saludEnemiga-nuevaSalud);


    Vida+=nuevaSalud;
    Dinero+=50;


}

void Ladron::Habilidad2(Personaje* enemigo){//El golpe tiene probabilidad de critico
	//Habilidad 2 del ladron



	#include <ctime>
	#include <cstdlib>

	srand(time(0));
    critico =rand()%13;
     
   	double impacto;
    double saludEnemiga;
    double defensaEnemiga;
    double nuevaSalud;
    	
    if(critico%3==0){
    	saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto*2;
        enemigos->setVida(nuevaSalud);




     } else{

     	saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigos->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto;
        enemigos->setVida(nuevaSalud);

     }






}

