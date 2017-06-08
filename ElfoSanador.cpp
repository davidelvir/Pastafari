#include "ElfoSanador.h"

ElfoSanador::ElfoSanador(){
  
  this->Vida=400;
  this->Defensa = 150;
  this->Ataque = 150;
  this->Stamina = true;
  this->Nivel=1;
  this->Dinero=0;
  this->Experiencia=0;
  this->Bolas=0;

}

void ElfoSanador::Ataque(Personaje* enemigo){
	//Ataque normal del ElfoSanador

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

void ElfoSanador::Habilidad1(Personaje* aliado){
	//Habilidad 1 del ElfoSanador +%50 salud a aliados

	double impacto;
    double saludAliado;
    double defensaEnemiga;
    double nuevaSalud;
    
    saludAliado= aliado->getVida() + aliado->getVida()*0.50;
    aliado->setVida(saludAliado);


}

void ElfoSanador::Habilidad2(Personaje* aliado){
	//Habilidad 2 del Elfo sanador +10% defensa
	double impacto;
    double defensaAliado;
    double defensaEnemiga;
    double nuevaSalud;
    

    defensaAliado= aliado->getDefensa() + aliado->getDefensa()*0.10;
    aliado->setDefensa(defensaAliado);

}