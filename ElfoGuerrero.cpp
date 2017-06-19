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

void ElfoGuerrero::Comprar(double dinero){
  int op;
  bool vivo = true;

  while(vivo){
    cout<<"Bienvenido a la tienda !!"<<endl;
    cout<<"Elija el item que desea comprar: "<<endl;
    cout<<"1. Arco de roble. -- 100 Pastas"<<endl;
    cout<<"2. Armadura ligera. -- 50 Pastas"<<endl;
    cout<<"3. Esfera del dragon. -- 2000 Pastas"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>op;
    switch(op){
      case 1:
      if(Dinero<100){
        cout<<"NO tiene dinero suficiente !"<<endl;
      }else{
        Dinero-=100;
        Ataque+=30;
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

void ElfoGuerrero::CortarPelo(double dinero){

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


void ElfoGuerrero::ArmaEspecial(Personaje* tem,Personaje* tem2){}

string ElfoGuerrero::Provocar(){return "Tus orejas dan pena!!";}

