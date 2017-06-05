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
using namespace std;

int main() {
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * menuwin = newwin(5, xMax-20, yMax-20,5);
	box(menuwin, 0, 0);	
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	string choices[3]={"LOGIN","SALIR", "3"};
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
	initscr();
	noecho();
	cbreak();
	system("clear");
	if(choices[highlight]=="LOGIN")
	{
		getmaxyx(stdscr, yMax, xMax);
		menuwin = newwin(5, xMax-20, yMax-20,5);
		box(menuwin, 0, 0);	
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	string choices[3]={"Ingresar como Administrador","SALIR", "3"};
	choice;
	highlight = 0;
	
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
	}
	getch();
	endwin();
return 0;
}
