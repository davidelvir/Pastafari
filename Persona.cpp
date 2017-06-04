#include "Persona.h"

Persona::Persona(string Nombre,string Username,string Password,int Edad,string Carrera){
    this->Nombre=Nombre;
    this->Username=Username;
    this->Password=Password;
    this->Edad=Edad;
    this->Carrera=Carrera;
}
Persona::Persona(){

}void Persona::setNombre(string Nombre){
   this-> Nombre=Nombre;
}
string Persona::getNombre(){
   return Nombre;
}
void Persona::setUsername(string Username){
   this-> Username=Username;
}
string Persona::getUsername(){
   return Username;
}
void Persona::setPassword(string Password){
   this-> Password=Password;
}
string Persona::getPassword(){
   return Password;
}
void Persona::setEdad(int Edad){
   this-> Edad=Edad;
}
int Persona::getEdad(){
   return Edad;
}
void Persona::setCarrera(string Carrera){
   this-> Carrera=Carrera;
}
string Persona::getCarrera(){
   return Carrera;
}
