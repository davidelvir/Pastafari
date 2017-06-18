#include "Ladron.h"
#include <ctime>
#include <cstdlib>


using namespace std;
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

void Ladron::Atacar(Personaje* enemigo){
	//Ataque normal del ladron

		double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;
        
        saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto;
        enemigo->setVida(nuevaSalud);


}

void Ladron::Habilidad1(Personaje* enemigo){// roba dinero y salud al enemigo
	//Habilidad 1 del ladron

	double impacto;
    double saludEnemiga;
    double defensaEnemiga;
    double nuevaSalud;
    

    saludEnemiga= enemigo->getVida();
    nuevaSalud= enemigo->getVida()*0.10;
    enemigo->setVida(saludEnemiga-nuevaSalud);


    Vida+=nuevaSalud;
    Dinero+=50;


}

void Ladron::Habilidad2(Personaje* enemigo){//El golpe tiene probabilidad de critico
	//Habilidad 2 del ladron

	srand(time(0));
    	int critico =rand()%13;
     
   	double impacto;
    	double saludEnemiga;
    	double defensaEnemiga;
    	double nuevaSalud;
    	
    if(critico%3==0){
    	saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto*2;
        enemigo->setVida(nuevaSalud);
     } else{

     	saludEnemiga= enemigo->getVida();
        defensaEnemiga= enemigo->getDefensa();
        impacto = Ataque-(defensaEnemiga*0.75);
        nuevaSalud= saludEnemiga-impacto;
        enemigo->setVida(nuevaSalud);

     }

}
void Ladron::Comprar(double dinero){}
        
void Ladron::CortarPelo(double dinero){}


void Ladron::ArmaEspecial(Personaje* tem,Personaje* tem2){}