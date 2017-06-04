#include "Item.h"
#include <string>

using namespace std;

Item::Item(){

}

Item::Item(string nombre,string tipo, double stat){
  this->nombre = nombre;
  this->tipo = tipo;
  this->stat = stat;
}

string Item::getNombre(){
  return nombre;
}

string Item::getTipo(){
  return tipo;
}

double Item::getStat(){
  return stat;
}

void Item::setNombre(string pNombre){
  nombre = pNombre;
}

void Item::setTipo(string pTipo){
  tipo = pTipo;
}

void Item::setStat(double pStat){
  stat = pStat;
}
