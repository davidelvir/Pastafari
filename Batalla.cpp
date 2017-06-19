#include "Personaje.h"
#include "Batalla.h"
#include <iostream>
#include <string>
#include "ElfoGuerrero.h"
#include "Guerrero.h"
#include "Witcher.h"
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>


using namespace std;

Batalla::Batalla(){
}

void Batalla::BatallaEpica(Personaje* Heroe, vector<Personaje*> enemigos,int m){
//Crearemos aqui la batalla y su bitacora!
srand(time(NULL));
int acum=1;
clear();
acum++;
mvprintw(acum, 10, "Bienvenido a la Batalla numero %i",m);
acum++;
mvprintw(acum, 10, "--------------------------------");

int cont = 1;
int ataqueEnemigo;
int aliadoAtacado;
int turnoEnemigo=0;

  while(enemigos.size()>0&&Heroe->getAliados().size()>0&&Heroe->getVida()>0){//Ocupamos el set aaliados para el size del while
  	int opcion=0;
  	int opcion2=0;
    char resp[100];
  	int op=0;
    acum=acum+2;
  	mvprintw(acum, 10, "Estos son los enemigos a derrotar");
    acum++;
  	mvprintw(acum, 10, "---------------------------------");
    acum++;
    //
    //Listar
  	for(int i=0; i<enemigos.size();i++){
  		acum++;
        string nombre = enemigos[i]->getNombre();
                    char *cstr = new char[nombre.length() + 1];
                    strcpy(cstr, nombre.c_str());
        mvprintw(acum, 10, "Enemigo: %i-) %s",i,cstr);
        delete [] cstr;
  	}
    acum++;
  	mvprintw(acum, 10, "---------------------------------");
    acum++;
    mvprintw(acum, 10, "Estos son sus personajes: ");
    acum++;
    for(int i=0; i<Heroe->getAliados().size();i++){//por mientras listaremos hasta 4 hasta que se haga el setAliados
        acum+=i;
        string nombre = Heroe->getAliado(i)->getNombre();
                    char *cstr = new char[nombre.length() + 1];
                    strcpy(cstr, nombre.c_str());
        mvprintw(acum, 10, "Aliado: %i-) %s",i,cstr);
        delete [] cstr;
    }
    acum++;
    acum++;
    string nombre1 = Heroe->getNombre();
                    char *cstr1 = new char[nombre1.length() + 1];
                    strcpy(cstr1, nombre1.c_str());
        mvprintw(acum, 10, "Heroe: %s",cstr1);
        delete [] cstr1;

    //turnos
    if(cont % 2 == 0){
    	if(enemigos.size()==0){
    		ataqueEnemigo=0;
    	}else{
    		ataqueEnemigo = rand()%1+enemigos.size();
    	}
    	aliadoAtacado = rand()%Heroe->getAliados().size();

    	if(ataqueEnemigo == 0){
    		enemigos[turnoEnemigo]->Atacar(Heroe->getAliado(aliadoAtacado));

    	}
      //validar la habilidad segun el personaje
    	Personaje* tem = enemigos[turnoEnemigo];
      //elfo guerrero
    	if(typeid(*tem)==typeid(ElfoGuerrero)){
    		if(ataqueEnemigo == 1){
    			enemigos[turnoEnemigo]->Habilidad1(Heroe->getAliado(aliadoAtacado));
    		}
    		if(ataqueEnemigo == 2){
    			for(int i = 0;i<enemigos.size();i++){
    				enemigos[turnoEnemigo]->Habilidad2(Heroe->getAliado(i));
    			}
    		}
    	}
      //guerrero
    	if(typeid(*tem)==typeid(Guerrero)){
    		if(ataqueEnemigo == 2){
    			enemigos[turnoEnemigo]->Habilidad1(Heroe->getAliado(aliadoAtacado));
    		}
    		if(ataqueEnemigo == 1){
    			for(int i = 0;i<enemigos.size();i++){
    				enemigos[turnoEnemigo]->Habilidad2(Heroe->getAliado(i));
    			}
    		}
    	}
      //witcher
    	if(typeid(*tem)==typeid(Witcher)){
    		if(ataqueEnemigo == 2){
    			enemigos[turnoEnemigo]->Habilidad1(Heroe->getAliado(aliadoAtacado));
    		}
    		if(ataqueEnemigo == 1){
    			for(int i = 0;i<enemigos.size();i++){
    				enemigos[turnoEnemigo]->Habilidad2(Heroe->getAliado(i));
    			}
    		}
    	}
    	turnoEnemigo++;
    	if(enemigos.size()==0||turnoEnemigo>2){
    		turnoEnemigo = 0;
    	}
    	if(enemigos.size()==2&&turnoEnemigo>1){
    		turnoEnemigo = 0;
    	}  

        string nombre=Heroe->getAliado(aliadoAtacado)->getNombre();
        double vida=Heroe->getAliado(aliadoAtacado)->getVida();
        
        char *cstr = new char[nombre.length() + 1];
        strcpy(cstr, nombre.c_str());
        
        string nombreHeroe=Heroe->getNombre();
        double vidaHeroe=Heroe->getVida();

        char *cstr2 = new char[nombreHeroe.length() + 1];
        strcpy(cstr2, nombreHeroe.c_str());
        
        acum++;
        mvprintw(acum, 10, "Ha atacado el enemigo, Reporte de Daños: ");
        acum++;
        mvprintw(acum, 10, "La salud del Aliado  %s es: %d",cstr,vida);
        acum++;
        mvprintw(acum, 10, "La salud del Heroe  %s es: %d",cstr2,vidaHeroe);
        acum++;
        mvprintw(acum, 10, "Toque [ENTER] para continuar");
        getstr(resp);
        delete [] cstr;
        delete [] cstr2;
        acum =1;
        clear();
    } else{
        acum++;
        mvprintw(acum, 10, "Su turno: ");
        acum++;
        mvprintw(acum, 10, "1-Atacar con Heroe principal");
        acum++;
        mvprintw(acum, 10, "2-Atacar con Aliado");
        acum++;
        move(acum,10);
    	getstr(resp);
        string temp(resp);
        op = atoi(temp.c_str());

    	if(op==1){
    		double impacto;
    		double saludEnemiga;
    		double defensaEnemiga;
    		double nuevaSalud;

    		int attack;

    		acum++;
            mvprintw(acum, 10, "Seleccione a que enemigo desea Atacar: ");
            getstr(resp);
            string temp1(resp);
            opcion2 = atoi(temp1.c_str());
            acum++;

    		//double aux2=enemigos[opcion2]->getVida();
    		//cout<<aux2<<endl;

    		Personaje* enemigoAtacado= enemigos[opcion2];

            acum++;
            mvprintw(acum, 10, "Seleccione que habilidad desea usar: ");
            acum++;
            mvprintw(acum, 10, "1-Ataque Normal");
            acum++;
            mvprintw(acum, 10, "2-Hablidad 1");
    		acum++;
            mvprintw(acum, 10, "3-Hablidad 2");
            acum++;
            move(acum,10);
            getstr(resp);
            string temp2(resp);
            attack=atoi(temp2.c_str());
            

    		if(attack==1){
    			Heroe->Atacar(enemigoAtacado);    

    		} 
        //validar la habilidad segun el personaje
    		Personaje* tem = Heroe;
      //elfo guerrero
    		if(typeid(*tem)==typeid(ElfoGuerrero)){
    			if(attack == 2){
    				Heroe->Habilidad1(enemigos[opcion2]);
    			}
    			if(attack == 3){
    				for(int i = 0;i<enemigos.size();i++){
    					Heroe->Habilidad2(enemigos[i]);
    				}
    			}
    		}
      //guerrero
    		if(typeid(*tem)==typeid(Guerrero)){
    			if(attack == 3){
    				Heroe->Habilidad2(enemigos[opcion2]);
    			}
    			if(attack == 2){
    				for(int i = 0;i<enemigos.size();i++){
    					Heroe->Habilidad1(enemigos[i]);
    				}
    			}
    		}
      //witcher
    		if(typeid(*tem)==typeid(Witcher)){
    			if(attack == 3){
    				Heroe->Habilidad2(enemigos[opcion2]);
    			}
    			if(attack == 2){
    				for(int i = 0;i<enemigos.size();i++){
    					Heroe->Habilidad1(enemigos[i]);
    				}
    			}
    		}


    		double aux=enemigos[opcion2]->getVida();

    		if(aux>0){
                acum++;
                mvprintw(acum, 10, "La salud del enemigo que ataco es de: %d",aux);               
    		}else{
    			enemigos.erase(enemigos.begin()+opcion2);
                acum++;
                mvprintw(acum, 10, "Ha asesinado al enemigo!");
    		}

            acum =1;
            clear();

    	}else if (op==2){
    		//Atacar con un aliado.
    		int SeleccionarAliado;
    		int SeleccionarEnemigo;
            acum++;
            mvprintw(acum, 10, "Seleccione con que Aliado desea atacar: ");
    	    acum++;
            acum++;
    		for(int i=0; i<Heroe->getAliados().size();i++){//por mientras listaremos hasta 4 hasta que se haga el setAliados
    			acum++;
                string temporal=Heroe->getAliado(i)->getNombre();
                char *ctrse = new char[temporal.length() + 1];
                strcpy(ctrse, temporal.c_str());
                mvprintw(acum, 10, "Aliado: %i.) %s ",i,ctrse);
                delete [] ctrse;
    		}
            getstr(resp);
            string cualqu(resp);
    		SeleccionarAliado=atoi(cualqu.c_str());

    		int attack;

    		acum++;
    		mvprintw(acum, 10, "Seleccione a que personaje Enemigo desea atacar: ");
            getstr(resp);
            string cualqui(resp);
            SeleccionarEnemigo=atoi(cualqui.c_str());

    		//double aux2=enemigos[SeleccionarEnemigo]->getVida();
    		//cout<<aux2<<endl;

    		Personaje* enemigoAtacado= enemigos[SeleccionarEnemigo];
    		Personaje* AliadoAtaca= Heroe->getAliado(SeleccionarAliado);


            acum++;
            mvprintw(acum, 10, "Seleccione que habilidad desea utilizar: ");
            acum++;
            mvprintw(acum, 10, "1-Ataque normal");
            acum++;
            mvprintw(acum, 10, "2-habilidad 1");
            acum++;
            mvprintw(acum, 10, "3-habilidad 2");
            acum++;
            move(acum,10);
            getstr(resp);
            string cualquie(resp);
            attack=atoi(cualquie.c_str());
            acum++;
    		if(attack==1){
    			AliadoAtaca->Atacar(enemigoAtacado);    

    		}

			if(typeid(*AliadoAtaca)==typeid(ElfoGuerrero)){
    			if(attack == 2){
    				AliadoAtaca->Habilidad1(enemigos[SeleccionarEnemigo]);
    			}
    			if(attack == 3){
    				for(int i = 0;i<enemigos.size();i++){
    					AliadoAtaca->Habilidad2(enemigos[i]);
    				}
    			}
    		}
      //guerrero
    		if(typeid(*AliadoAtaca)==typeid(Guerrero)){
    			if(attack == 3){
    				AliadoAtaca->Habilidad2(enemigos[SeleccionarEnemigo]);
    			}
    			if(attack == 2){
    				for(int i = 0;i<enemigos.size();i++){
    					AliadoAtaca->Habilidad1(enemigos[i]);
    				}
    			}
    		}
      //witcher
    		if(typeid(*AliadoAtaca)==typeid(Witcher)){
    			if(attack == 3){
    				AliadoAtaca->Habilidad2(enemigos[opcion2]);
    			}
    			if(attack == 2){
    				for(int i = 0;i<enemigos.size();i++){
    					AliadoAtaca->Habilidad1(enemigos[i]);
    				}
    			}
    		}

    		double aux=enemigos[SeleccionarEnemigo]->getVida();

    		if(aux>0){
                acum++;
                mvprintw(acum, 10, "La Salud del enemigo que ataco es de: %d",aux);
    			               
    		}else{
    			enemigos.erase(enemigos.begin()+opcion2);
                acum++;
                mvprintw(acum, 10, "Ha asesinado al enemigo");
    			
    		}    		
    		
            acum=1;
            clear();
    	}

    }

    cont++;
} 

acum++;
mvprintw(acum, 10, "La batalla ha terminado");
int n =Heroe->getNivel();

n++;
Heroe->setNivel(n);

}
