#include "Personaje.h"
#include "Batalla.h"
#include <iostream>
#include <string>
#include "ElfoGuerrero.h"
#include "Guerrero.h"
#include "Witcher.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Batalla::Batalla(){
}

void Batalla::BatallaEpica(Personaje* Heroe/*, int i*/){
	//Crearemos aqui la batalla y su bitacora!
  srand(time(NULL));
  cout<<"Bienvenido a la Batalla numero "<</*i<<*/endl;
  cout<<endl;
  cout<<"------------------------"<<endl;
  
  Personaje* enemigo1 = new ElfoGuerrero();
  Personaje* enemigo2 = new Guerrero();
  Personaje* enemigo3 = new Witcher();

  enemigo1->setNombre("Jahaziel");
  enemigo2->setNombre("Marvin");
  enemigo3->setNombre("Juan");

  enemigos.push_back(enemigo1);
  enemigos.push_back(enemigo2);
  enemigos.push_back(enemigo3);


  int cont = 1;
  int ataqueEnemigo;
  int aliadoAtacado;
  int turnoEnemigo=0;

  while(enemigos.size()>0&&Heroe->getAliados().size()>0&&Heroe->getVida()>0){//Ocupamos el set aaliados para el size del while
    int opcion=0;
    int opcion2=0;
    int op=0;

    cout<<"Estos son los enemigos a derrotar: "<<endl;
    cout<<"----------------------------"<<endl;  
    //
    //Listar
    for(int i=0; i<enemigos.size();i++){
      cout<<"Enemigo: "<<i<<" "<<enemigos[i]->getNombre()<<endl;
    }

    cout<<"----------------------------------"<<endl;
    
    cout<<"Estos son sus Personajes: "<<endl;

    for(int i=0; i<Heroe->getAliados().size();i++){//por mientras listaremos hasta 4 hasta que se haga el setAliados
      cout<<"Aliado: "<<i<<" "<<Heroe->getAliado(i)->getNombre()<<endl;
    }
    cout<<Heroe->getNombre()<<endl;
    //----------------------------------------------------

    //turnos
    if(cont % 2 == 0){

      ataqueEnemigo = rand()%3;
      aliadoAtacado = rand()%Heroe->getAliados().size();

      if(ataqueEnemigo == 0){
        enemigos[turnoEnemigo]->Atacar(Heroe->getAliado(aliadoAtacado));

      }
      if(ataqueEnemigo == 1){
        enemigos[turnoEnemigo]->Habilidad1(Heroe->getAliado(aliadoAtacado));
      }
      if(ataqueEnemigo == 2){
        enemigos[turnoEnemigo]->Habilidad2(Heroe->getAliado(aliadoAtacado));
      }
      if(turnoEnemigo > 2){
        turnoEnemigo = 0;
      }else{
        turnoEnemigo++;
      }
      cout<<Heroe->getAliado(aliadoAtacado)->getVida()<<endl;
    } else{

      cout<<"Su turno "<< endl;
      
      cout<<"1-Atacar con Heroe principal"<<endl;
      cout<<"2-Atacar con Aliado"<<endl;
      cin>>op;
      if(op==1){
        double impacto;
        double saludEnemiga;
        double defensaEnemiga;
        double nuevaSalud;

        int attack;

        cout<<"Seleccione a que personaje desea atacar"<<endl; 
        cin>>opcion2;

        cout<<" "<<endl;

        double aux2=enemigos[opcion2]->getVida();
        cout<<aux2<<endl;
        

        Personaje* enemigoAtacado= enemigos[opcion2];


        cout<<"seleccione que habilidad desea utilizar: "<<endl;
        cout<<"1-Ataque normal"<<endl;
        cout<<"2-habilidad 1"<<endl;
        cout<<"3-habilidad 2"<<endl;
        cin>>attack;

        if(attack==1){
          Heroe->Atacar(enemigoAtacado);    

        } 
        if(attack==2){
          Heroe->Habilidad1(enemigoAtacado);

        }
        if(attack==3){
          Heroe->Habilidad2(enemigoAtacado);

        }


        double aux=enemigos[opcion2]->getVida();
        cout<<aux<<endl;
        if(aux<=0){
              enemigos.erase(enemigos.begin()+opcion2);
              cout <<"Ha asesinado al enemigo"<<endl;          
        }

      }else if (op==1){

        cout<<"Pija2"<<endl;

      }

    }
    cont++;
  } 
  
  cout<<"La batalla a terminado"<<endl;

}
