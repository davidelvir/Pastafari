#include "Humano.h"
#include "Guerrero.h"	

Guerrero::Guerrero(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello, string Color, double Dinero){
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
  this->Color=Color;
  this->Dinero=Dinero;
}

Guerrero::Guerrero(){

	this->Vida=300;
	this->Defensa=150;
	this->Ataque=200;
	this->Stamina=true;
	this->Dinero=0;
	this->Nivel=1;
	this->Experiencia=0;
	this->Bolas=0;

}

void Guerrero::Atacar(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.5);
  double saludActual = enemigo->getVida();
  enemigo->setVida(saludActual - damage);
}

void Guerrero::Habilidad1(Personaje* enemigo){
  double saludActual = enemigo->getVida();
  double damage = Ataque * 0.2;
  enemigo->setVida(saludActual - damage);
}

void Guerrero::Habilidad2(Personaje* enemigo){
  enemigo->setStamina(false);
}

void Guerrero::Comprar(double dinero){
  int op;
  bool vivo = true;

  while(vivo){
    cout<<"Bienvenido a la tienda !!"<<endl;
    cout<<"Elija el item que desea comprar: "<<endl;
    cout<<"1. Espada de acero. -- 100 Pastas"<<endl;
    cout<<"2. Armadura mediana. -- 100 Pastas"<<endl;
    cout<<"3. Esfera del dragon. -- 2000 Pastas"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>op;
    switch(op){
      case 1:
      if(Dinero<100){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=100;
        Ataque+=40;
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 2:
      if(Dinero<100){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=100;
        Defensa+=40;
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 3:
      if(Dinero<2000){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=2000;
        Bolas++;
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 4:
      vivo = false;
      cout<<"Gracias por venir!!"<<endl;
    }
  }
}

void Guerrero::CortarPelo(double dinero){
  int op;
  bool vivo = true;

  while(vivo){
    cout<<"Bienvenido a la barberia !!"<<endl;
    cout<<"Elija el corte que desea comprar: "<<endl;
    cout<<"1. Razurado. -- 50 Pastas"<<endl;
    cout<<"2. Mohawk. -- 50 Pastas"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>op;
    switch(op){
      case 1:
      if(Dinero<50){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=50;
        estiloCabello = "Razurado";
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 2:
      if(Dinero<50){

        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=50;
        estiloCabello = "Mohawk";
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 3:
      vivo = false;
      break;
    }
  }
}


void Guerrero::ArmaEspecial(Personaje* tem,Personaje* tem2){}


