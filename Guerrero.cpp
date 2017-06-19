#include "Humano.h"
#include "Guerrero.h"
#include <string>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

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
  char resp[100];

  while(vivo){
    clear();
    mvprintw(2, 10, "BIENVENIDO A LA TIENDA !!");
    mvprintw(3, 10, "Elija el item que desea comprar");
    mvprintw(4, 10, "1.) Espada de acero. -- 100 Pastas");
    mvprintw(5, 10, "2.) Armadura mediana. -- 100 Pastas");
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
        Ataque+=40;
        mvprintw(9, 10, "Gracias por la compra!");
        mvprintw(10, 10, "Presione [ENTER] para continuar.");
        getstr(resp);
        clear();
      }
      break;
      case 2:
      if(Dinero<100){
         mvprintw(9, 10, "No tiene dinero suficiente.");
         mvprintw(10, 10, "Presione [ENTER] para continuar.");
         getstr(resp);
         clear();
      }else{
        Dinero-=100;
        Defensa+=40;
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

void Guerrero::CortarPelo(double dinero){
   
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


void Guerrero::ArmaEspecial(Personaje* tem,Personaje* tem2){}


