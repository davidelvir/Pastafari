#include <iostream>
#include <string>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H
class Persona{
    protected:
        string Nombre;
        string Username;
        string Password;
        int Edad;
        string Carrera;
    public:
        Persona(string,string,string,int,string);
        Persona();
        string getNombre();
        void setNombre(string);

        string getUsername();
        void setUsername(string);

        string getPassword();
        void setPassword(string);

        int getEdad();
        void setEdad(int);

        string getCarrera();
        void setCarrera(string);

};
#endif