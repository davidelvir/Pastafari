#include "Humano.h"
#include "Witcher.h"	
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

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
  char resp[100]; 

  while(vivo){
    clear();
    mvprintw(2, 10, "BIENVENIDO A LA TIENDA !!");
    mvprintw(3, 10, "Elija el item que desea comprar");
    mvprintw(4, 10, "1.) Espada de plata. -- 300 Pastas");
    mvprintw(5, 10, "2.) Armadura ligera. -- 50 Pastas");
    mvprintw(6, 10, "3.) Esfera del dragon. -- 2000 Pastas");
    mvprintw(7, 10, "4.) Salir");
    getstr(resp);
    string temp(resp);
    op = atoi(temp.c_str());
    switch(op){
      case 1:
      if(Dinero<300){
         mvprintw(9, 10, "No tiene dinero suficiente.");
         mvprintw(10, 10, "Presione [ENTER] para continuar.");
         getstr(resp);
         clear();
      }else{
        Dinero-=300;
        Ataque+=70;
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
         clear();
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
         clear();
      }else{
        Dinero-=2000;
        Bolas++;
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      break;
    }
      case 4:
        vivo = false;
        mvprintw(9, 10, "Gracias por venir!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
        break;
    
  }
}
}

void Witcher::CortarPelo(double dinero){
  
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
         clear();
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


void Witcher::ArmaEspecial(Personaje* tem,Personaje* tem2){}


