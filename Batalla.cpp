#include "Personaje.h"
#include "Batalla.h"
#include <iostream>
#include <string>

using namespace std;

Batalla::Batalla(){
}

void Batalla::BatallaEpica(vector<Personaje*>& enemigos, Personaje* Heroe){
	//Crearemos aqui la batalla y su bitacora!

  cout<<"Bienvenido a la Batalla numero 1"<<endl;
  cout<<""<<endl;
  cout<<"------------------------"<<endl;
  
  int cont = 1;

  while(enemigos.size()>0){//Ocupamos el set aaliados para el size del while
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

    for(int i=0; i<4;i++){//por mientras listaremos hasta 4 hasta que se haga el setAliados
      cout<<"Aliado: "<<i<<" "<<Heroe->getAliado(i)<<endl;
    }
    cout<<Heroe->getNombre();
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
