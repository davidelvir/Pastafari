#include "Bestia.h"
#include "Item.h"
#include <string>
#include <vector>

using namespace std;
Bestia::Bestia(){
}
Bestia::Bestia(string nombre){
	this->nombre=nombre;
}
string Bestia:: getNombre(){
	return nombre;
}
void Bestia:: setNombre(string nombre){
	this->nombre=nombre;
}
/*vector<Item> Bestia:: getItem(){
	return items;
}*/
/*void Bestia:: setItems(vector<Items> items){
	this->items=items;
}
void Bestia::setItem(Item item, int pos){
	items[pos]=item;
}*/
