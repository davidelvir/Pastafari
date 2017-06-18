#include "Humano.h"
#include "Witcher.h"	

Witcher::Witcher(string Nombre, double Vida, double Defensa, double Ataque,string Reputacion,int Nivel,int Experiencia,int Bolas,string estiloCabello, string Color, double Dinero){
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

Witcher::Witcher(){

	this->Vida=300;
	this->Defensa=300;
	this->Ataque=350;
	this->Stamina=true;
	this->Dinero=0;
	this->Nivel=1;
	this->Experiencia=0;
	this->Bolas=0;

}

void Witcher::Atacar(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.25);
  double vidaActual = enemigo->getVida();

  enemigo->setVida(vidaActual-damage);
}

void Witcher::Habilidad1(Personaje* enemigo){
  double damage = Ataque - (enemigo->getDefensa()*0.6);
  double vidaActual = enemigo->getVida();

  enemigo->setVida(vidaActual-damage);
}

void Witcher::Habilidad2(Personaje* enemigo){
  Ataque+=Ataque*0.05;
  Defensa+=Defensa*0.05;
}

void Witcher::Comprar(double dinero){
  int op;
  bool vivo = true;

  while(vivo){
    cout<<"Bienvenido a la tienda !!"<<endl;
    cout<<"Elija el item que desea comprar: "<<endl;
    cout<<"1. Espada de plata. -- 300 Pastas"<<endl;
    cout<<"2. Armadura ligera. -- 50 Pastas"<<endl;
    cout<<"3. Esfera del dragon. -- 2000 Pastas"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>op;
    switch(op){
      case 1:
      if(Dinero<300){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=300;
        Ataque+=70;
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 2:
      if(Dinero<50){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=50;
        Defensa+=30;
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

void Witcher::CortarPelo(double dinero){
  int op;
  bool vivo = true;

  while(vivo){
    cout<<"Bienvenido a la barberia !!"<<endl;
    cout<<"Elija el corte que desea comprar: "<<endl;
    cout<<"1. Razurado a los lados, largo de arriba. -- 50 Pastas"<<endl;
    cout<<"2. Pelo largo. -- 50 Pastas"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>op;
    switch(op){
      case 1:
      if(Dinero<50){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=50;
        estiloCabello = "Cola de caballo";
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 2:
      if(Dinero<50){

        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=50;
        estiloCabello = "Pelo largo";
        cout<<"Gracias por la compra!"<<endl;
      }
      break;
      case 3:
      vivo = false;
      break;
    }
  }
}


void Witcher::ArmaEspecial(Personaje* tem,Personaje* tem2){}


