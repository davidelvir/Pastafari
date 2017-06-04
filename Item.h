#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item{

  private:
    string nombre;
    string tipo;
    double stat;

  public:
    //constructores
    Item();
    Item(string,string,double);

    //getters
    string getNombre();
    string getTipo();
    double getStat();

    //setters
    void setNombre(string);
    void setTipo(string);
    void setStat(double);

};

#endif
