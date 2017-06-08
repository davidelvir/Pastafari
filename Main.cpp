#include "Administrador.h"
#include "Jugador.h"
#include "Bestia.h"
#include "Caballo.h"
#include "Burro.h"
#include "Dragon.h"
#include "Elfo.h"
#include "ElfoGuerrero.h"
#include "ElfoSanador.h"
#include "Enano.h"
#include "EnanoGuerrero.h"
#include "EnanoHerrero.h"
#include "Guerrero.h"
#include "Humano.h"
#include "Item.h"
#include "Ladron.h"
#include "Noble.h"
#include "Persona.h"
#include "Persona.h"
#include "Witcher.h"
#include <ncurses.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;


void cleanScreen();
void historia();

int main() {
	initscr();
	noecho();
	cbreak();
	vector<string> usuarios;
	vector<string> contrasenas;
	Jugador jugadorRaiz;
	Administrador adminRaiz;
	string usuarioAdmin = "MONESVOL2017";
	string contraAdmin = "HailKingOswaldoTheThird";
	usuarios.push_back(usuarioAdmin);
	contrasenas.push_back(contraAdmin);
	bool juego = true;
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * menuwin = newwin(5, xMax-20, yMax-20,5);
	box(menuwin, 0, 0);	
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	char menuPrincipal='s';
	while(menuPrincipal=='s'||menuPrincipal=='S'){
	string choices[3]={"<<>>>LOGIN<<<>>","Historia del pastafarismo", "Salir"};
	int choice;
	int highlight = 0;
	
	while(1)
	{
		for(int i = 0; i < 3; i++)
		{
			if(i == highlight)
				wattron(menuwin,A_REVERSE);
			mvwprintw(menuwin,i+1,1,choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch(choice)
		{
			case KEY_UP:
				highlight--;
				if(highlight == -1)
					highlight=0;
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == 3)
					highlight = 2;
				break;
				default:
				break;
		}
		if(choice==10)
			break;
	}
	endwin();
	//printw("Your choice was: %s", choices[highlight].c_str());
	if(choices[highlight]=="Historia del pastafarismo")
	{
		cleanScreen();
		historia();
	}else if(choices[highlight]=="Salir"){
		exit(0);

	}
	if(choices[highlight]=="<<>>>LOGIN<<<>>"){

		start_color();
		echo();
		cleanScreen();
		juego=true;
		while(juego == true)
		{
			char resp[2];
			mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL");
			mvprintw(5, 10, "* Ingrese Usuario:");
			getstr(resp);
			string usuarioTemp(resp);
			cleanScreen();
			
			for (int i = 0; i < usuarios.size(); ++i)
			{
				if(usuarios[i]=="MONESVOL2017"){
					mvprintw(5, 10, "* Ingrese la contraseña del Admin.:");
					getstr(resp);
					string contraTemp(resp);
					cleanScreen();
					if(contrasenas[i]=="HailKingOswaldoTheThird"){
						
						mvprintw(2, 10, "MENU Administrador");
						mvprintw(3, 10, "1) Agregar cuentas.");
						mvprintw(4, 10, "2) Listar cuentas.");
						mvprintw(5, 10, "3) Borrar cuentas ");
						mvprintw(6, 10, "4) Autodestruccion");
						mvprintw(7, 10, "5) Salir del sistema");
						mvprintw(8, 10, "6) Salir del menu");

						getstr(resp);
						string cualquiera(resp);
						int respInt = atoi(cualquiera.c_str());
						if(respInt==1){

						}//end respInt 1
						if(respInt==2){

						}//end respInt 2
						if(respInt==3){

						}//end respInt 3
						if(respInt==4){

						}//end respInt 4
						if(respInt==5){
							exit(0);
						}//end respInt 5


					
				}//end if
			}//end for
			}

		}
	}
	mvprintw(8, 10, "Desea continuar? [s/n]");
	getstr(menuPrincipal);
	}
	getch();
	endwin();
return 0;
}

void cleanScreen(){
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLS; j++){
			mvprintw(i,j," ");
		}
	}
}

void historia()
{
	string historia;
	cleanScreen();
	mvprintw(2,10,"Escriba la historia aqui");

}