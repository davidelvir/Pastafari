#include "Elfo.h"
#include "ElfoGuerrero.h"
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

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
  char resp[100];

  while(vivo){
    clear();
    mvprintw(2, 10, "BIENVENIDO A LA TIENDA !!");
    mvprintw(3, 10, "Elija el item que desea comprar");
    mvprintw(4, 10, "1.) Arco de roble. -- 100 Pastas");
    mvprintw(5, 10, "2.) Armadura ligera. -- 50 Pastas");
    mvprintw(6, 10, "3.) Esfera del dragon. -- 2000 Pastas");
    mvprintw(7, 10, "4.) Salir");
    getstr(resp);
    string temp(resp);
    op = atoi(temp.c_str());
    switch(op){
      case 1:
      if(Dinero<100){
        mvprintw(9, 10, "No tiene dinero suficiente.");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }else{
        Dinero-=100;
        Ataque+=30;
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 2:
      if(Dinero<50){
        mvprintw(9, 10, "No tiene dinero suficiente.");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();;
      }else{
        Dinero-=50;
        Defensa+=30;
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 3:
      if(Dinero<2000){
        mvprintw(9, 10, "No tiene dinero suficiente.");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();;
      }else{
        Dinero-=2000;
        Bolas++;
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 4:
      vivo = false;
        mvprintw(9, 10, "Gracias por venir!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
    }
  }
}

void ElfoGuerrero::CortarPelo(double dinero){

  int op;
  bool vivo = true;
  char resp[100];

  while(vivo){
    clear();
    mvprintw(2, 10, "BIENVENIDO A LA BARBERIA !!");
    mvprintw(3, 10, "Elija el corte que desea comprar");
    mvprintw(4, 10, "1.) Razurado a los lados, largo de arriba. -- 50 Pastas");
    mvprintw(5, 10, "2.) Pelo largo. -- 50 Pastas");
    mvprintw(6, 10, "3.) Salir");
    getstr(resp);
    string temp(resp);
    op=atoi(temp.c_str());
    switch(op){
      case 1:
      if(Dinero<50){
        mvprintw(9, 10, "No tiene dinero suficiente.");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();;
      }else{
        Dinero-=50;
        estiloCabello = "Cola de caballo";
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 2:
      if(Dinero<50){
         mvprintw(9, 10, "No tiene dinero suficiente.");
         mvprintw(10, 10, "Presione [ENTER] para continuar.");
         getstr(resp);
         clear();;
      }else{
        Dinero-=50;
        estiloCabello = "Pelo largo";
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 3:
        vivo = false;
        mvprintw(9, 10, "Gracias por venir!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      break;
    }
  }
}


void ElfoGuerrero::ArmaEspecial(Personaje* tem,Personaje* tem2){}

