#include <string>
#include "Personaje.h"
#ifndef ELFO_H
#define ELFO_H

using namespace std;

class Elfo: public Personaje{

  protected:
    
    int tamOrejas;
  
  public:

    Elfo();

    int getTamOrejas();
    void setTamOrejas(int);

};

#endif

