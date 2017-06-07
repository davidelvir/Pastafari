#include "Personaje.h"
#include "Batalla.h"
#include <iostream>
#include <string>
#include "ElfoGuerrero.h"
#include "Guerrero.h"
#include "Witcher.h"

using namespace std;

Batalla::Batalla(){
}

void Batalla::BatallaEpica(Personaje* Heroe){
	//Crearemos aqui la batalla y su bitacora!

  cout<<"Bienvenido a la Batalla numero 1"<<endl;
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

      cout<<"Turno del Enemigo" <<endl;

      cout<<"Seleccione con que personaje desea atacar"<<endl; 
      cin>>opcion;
      cout<<"Seleccione a que personaje desea atacar"<<endl; 
      cin>>opcion2;



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

        cout<<"Seleccione a que personaje desea atacar"<<endl; 
        cin>>opcion2;


        
        saludEnemiga= enemigos[opcion2]->getVida();
        defensaEnemiga= enemigos[opcion2]->getDefensa();
        impacto = Heroe->getAtaque()-(defensaEnemiga/2);
        nuevaSalud= saludEnemiga-impacto;

        enemigos[opcion2]->setVida(nuevaSalud);
        double aux=enemigos[opcion2]->getVida();
        cout<<aux<<endl;
        if(aux<=0){
              enemigos.erase(enemigos.begin()+opcion2);
              cout <<"Ha asesinado al enemigo"<<endl;          
        }

      }else{

        cout<<"Seleccione con que personaje desea atacar"<<endl; 
        cin>>opcion;
        cout<<"Seleccione a que personaje desea atacar"<<endl; 
        cin>>opcion2;

      }

    }
    cont++;
  } 
  
  cout<<"La batalla a terminado"<<endl;

}
