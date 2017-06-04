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

using namespace std;

int main() {
	initscr();
	noecho();
	cbreak();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * menuwin = newwin(4, xMax-12, yMax-8,5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	keypad(menuwin, true);

	string choices[2]={"LOGIN","SALIR"};
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
				if(highlight == 2)
					highlight = 1;
				break;
				default:
				break;
		}
		if(choice==10)
			break;
	}
	getch();
	endwin();
return 0;
}
