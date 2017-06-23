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
  int money = Dinero;
  while(vivo){
    clear();
    mvprintw(2, 10, "BIENVENIDO A LA TIENDA !!");
    mvprintw(3, 10, "Elija el item que desea comprar");
    mvprintw(4, 10, "PASTA: %d",money);
    mvprintw(5, 10, "1.) Espada de plata. -- 300 Pastas");
    mvprintw(6, 10, "2.) Armadura ligera. -- 50 Pastas");
    mvprintw(7, 10, "3.) Esfera del dragon. -- 2000 Pastas");
    mvprintw(8, 10, "4.) Salir");
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
  int money;
  money = dinero;

  while(vivo){
    clear();
    refresh();
    mvprintw(2, 10, "BIENVENIDO A LA BARBERIA !!");
    mvprintw(3, 10, "Elija el corte que desea comprar");
    mvprintw(4, 10, "PASTA: %i",money);
    mvprintw(5, 10, "1.) Razurado a los lados, largo de arriba. -- 50 Pastas");
    mvprintw(6, 10, "2.) Pelo largo. -- 50 Pastas");
    mvprintw(7, 10, "3.) Salir");
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

void Witcher::Entrenamiento(){
  clear();
  refresh();
  string vivo="s";
  char resp[100];
  int money = Dinero;
  while(vivo=="s"||vivo=="S"){
  mvprintw(2, 10, "BIENVENIDO JOVEN PADAWAN");
  mvprintw(3, 10, "SOY EL MAESTRO JEDI BOCANEGRA");
  mvprintw(4, 10, "PARA ASCENDER TUS PODERES TIENES QUE ENTRENAR CONMIGO");
  mvprintw(5, 10, "Costo: 200 Pastas");
  mvprintw(6, 10, "PASTA: %d",money);
  mvprintw(7, 10, "PRESIONE [ENTER] PARA CONTINUAR");
  getstr(resp);
  if(Nivel==2&&nivelEntrenamiento==0){
      if(Dinero>=200){
            clear();
            mvprintw(2, 10, "ENTRENAR A LV2? [S/N]");
            getstr(resp);
            string op(resp);
            clear();
            if(op=="s"||op=="S"){
                  clear();
                  mvprintw(2, 10, "LA FUERZA ES FUERTE EN TI MI JOVEN PADAWAN");
                  mvprintw(3, 10, "PRESIONE [ENTER] PARA CONTINUAR");
                      getstr(resp);
                  int pastaJugador;
                  Dinero=Dinero-200;
                  Vida=Vida + 300;
                  Ataque+=300;
                  Defensa+=300;
                  nivelEntrenamiento=1;
                                                                        
            }else{
                break;
            }

            }else{
                clear();
                mvprintw(2, 10, "No tiene suficiente pasta");
                mvprintw(3, 10, "PRESIONE [ENTER] PARA CONTINUAR");
                vivo="f";
                getstr(resp);
                clear();
  }
  }else if(Nivel==3&&nivelEntrenamiento==1){
            if(Dinero>=200){
                  clear();
                  mvprintw(2, 10, "ENTRENAR A LV3? [S/N]");
                  getstr(resp);
                  string op(resp);
                  clear();
                  if(op=="s"||op=="S"){
                      clear();
                      mvprintw(2, 10, "ERES SORPRENDENTE! TUS PROGRAMAS COMPILAN A LA PRIMERA!");
                      mvprintw(3, 10, "TUS PODERES SON INCREIBLES");
                      mvprintw(4, 10, "PRESIONE [ENTER] PARA CONTINUAR");
                      getstr(resp);
                      int pastaJugador;
                      Dinero=Dinero-200;
                      Vida=Vida + 500;
                      Ataque+=500;
                      Defensa+=500;
                      nivelEntrenamiento=2;

        }else{
            break;
        }

    }else{
        clear();
        mvprintw(2, 10, "No tiene suficiente pasta");
        mvprintw(3, 10, "PRESIONE [ENTER] PARA CONTINUAR");
        vivo="f";
        getstr(resp);
        clear();

    }
    }else if(Nivel==5&&nivelEntrenamiento==2){
          if(Dinero>=200){
              clear();
              mvprintw(2, 10, "ENTRENAR A LV4? [S/N]");
              getstr(resp);
              string op(resp);
              clear();
              if(op=="s"||op=="S"){
                    clear();
                    mvprintw(2, 10, "EL ALUMNO SUPERO AL MAESTRO");
                    mvprintw(3, 10, "BIENVENIDO INGENIERO.");
                    mvprintw(3, 10, "PRESIONE [ENTER] PARA CONTINUAR");
                      getstr(resp);
                    int pastaJugador;
                    Dinero=Dinero-200;
                    Vida=Vida + 500;
                    Ataque+=500;
                    Defensa+=500;

                }else{
                    break;
                }
        }else{
                    clear();
                    mvprintw(2, 10, "YA NO PUEDE ENTRENAR MAS");
                    mvprintw(3, 10, "USTED YA ES UN MAESTRO JEDI");
                    vivo="f";
                    mvprintw(4, 10, "PRESIONE [ENTER] PARA CONTINUAR");
                    getstr(resp);
                    clear();

        }
        
      }
        clear();
        mvprintw(2, 10, "DESEA CONTINUAR? [S/N]");
        getstr(resp);
        clear();
        string respuesta(resp);
        vivo=respuesta;
  }//fin while
            
}

void Witcher::BolasDelDragon(){
    clear();
    bool vivo=true;
    int money = Dinero;
    char resp[100];
    while(vivo=true){
    mvprintw(2, 10, "HAS COLECTADO LAS 7 BOLAS DEL DRAGON");
    mvprintw(3, 10, "BIENVENIDO");
    mvprintw(4, 10, "PASTA: %i",money);
    mvprintw(5, 10, "1.) HEALTH MEGA-BOOST");
    mvprintw(6, 10, "2.) ONE SHOT BOOST");
    mvprintw(7, 10, "3.) Salir");
    getstr(resp);
    string blah(resp);
    if(blah=="1"){
        clear();
        mvprintw(2, 10, "TU DESEO HA SIDO CUMPLIDO");
        mvprintw(3, 10, "NOS VEMOS");
        mvprintw(4, 10, "PRESIONE [ENTER] PARA CONTINUAR");
        getstr(resp);
        
        Bolas=0;
        Vida+=2000;
        vivo=false;
        
        clear();
    }
    if(blah=="2"){
        clear();
        mvprintw(2, 10, "TU DESEO HA SIDO CUMPLIDO");
        mvprintw(3, 10, "NOS VEMOS");
        mvprintw(4, 10, "PRESIONE [ENTER] PARA CONTINUAR");
        getstr(resp);
        
        Bolas=0;
        Ataque+=3000;
        vivo=false;
      
        clear();
    }else{
        mvprintw(3, 10, "NOS VEMOS");
        mvprintw(4, 10, "PRESIONE [ENTER] PARA CONTINUAR");
        getstr(resp);
        clear();
    }
  }
}

void Witcher::ArmaEspecial(Personaje* tem,Personaje* tem2){}

string Witcher::Provocar(){return "Ambas espadas son para matar monstruos!";}


