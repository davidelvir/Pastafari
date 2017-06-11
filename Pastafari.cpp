#include "Pastafari.h"

using namespace std;

void Pastafari::run(){
	 vector<string> usuarios;
        vector<string> contrasenas;
        Jugador jugadorRaiz;
        Administrador adminRaiz;
        string usuarioAdmin = "qwerty";
        string contraAdmin = "v";
        usuarios.push_back(usuarioAdmin);
        contrasenas.push_back(contraAdmin);
        bool juego = true;
 		char menuPrincipal[2];
        menuPrincipal[0]='s';
        while(menuPrincipal[0]=='s'||menuPrincipal[0]=='S'){
                initscr();                      /* Start curses mode              */
                start_color();
                refresh();

        init_pair(1, COLOR_GREEN, COLOR_WHITE );
        bkgd( COLOR_PAIR(1) );
                noecho();
                cbreak();


                int yMax, xMax;
                getmaxyx(stdscr, yMax, xMax);
                WINDOW * menuwin = newwin(5, xMax-20, yMax-20,5);
                box(menuwin, 0, 0);
                refresh();
                wrefresh(menuwin);
                keypad(menuwin, true);
                string choices[3]={"LOGIN","Crear cuenta", "Salir"};
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
        if(choices[highlight]=="Crear cuenta")
        {
                limpiarPantalla();
                historia();
        }else if(choices[highlight]=="Salir"){
                exit(0);

        }
        if(choices[highlight]=="LOGIN"){

                start_color();
                echo();
                limpiarPantalla();
                juego=true;
                while(juego == true)
                {
                        char resp[2];
                        mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL");
                        mvprintw(5, 10, "* Ingrese Usuario:");
                        getstr(resp);
                        string usuarioTemp(resp);
                        limpiarPantalla();

                        for (int i = 0; i < usuarios.size(); ++i)
                        {
                                if(usuarios[i]=="qwerty"){
                                        mvprintw(5, 10, "* Ingrese la contraseña del Administrador:");
                                        getstr(resp);
                                        string contraTemp(resp);
                                        limpiarPantalla();
                                        if(contrasenas[i]=="v"){
                                                bool logout;
                                                logout=true;
                                                while(logout==true){
                                                        clear();
                                                mvprintw(2, 10, "MENU Administrador");
                                                mvprintw(3, 10, "1) Agregar cuentas");
                                                mvprintw(4, 10, "2) Listar cuentas");
                                                mvprintw(5, 10, "3) Borrar cuentas ");
                                                mvprintw(6, 10, "4) Autodestruccion");
                                                mvprintw(7, 10, "5) Logout");
                                                mvprintw(8, 10, "6) Salir");
                                                mvprintw(9, 10, "Ingrese opcion: ");
                                                getstr(resp);

                                                if(resp[0]=='1'){

                                                }//end respInt 1
                                                if(resp[0]=='2'){

                                                }//end respInt 2
                                                if(resp[0]=='3'){

                                                }//end respInt 3
                                                if(resp[0]=='4'){

                                                }//end respInt 4
                                                if(resp[0]=='5'){
                                                        limpiarPantalla();
                                                        logout=false;
                                                }//end respInt 5
                                                if(resp[0]=='6'){

                                                        juego=false;
                                                        logout=false;
                                                        limpiarPantalla();
                                                        clear();
                                                        exit(0);


                                                }//end respInt 5
                                                if(resp[0]!='1'&&resp[0]!='2'&&resp[0]!='3'&&resp[0]!='4'&&resp[0]!='5'&&resp[0]!='6'){
                                                	clear();
                                                        mvprintw(2, 10, "Numero equivocado!");
                                                        mvprintw(3, 10, "Ingrese enter: ");
                                                        getstr(resp);
                                                }

                                        }//end logout
                                }//end if
                        }//end for
                        }

                }
        }
        limpiarPantalla();
        mvprintw(8, 10, "Desea continuar? [s/n]");
        mvprintw(9, 10, "Ingrese una opcion: ");
        clear();
        getstr(menuPrincipal);
        endwin();
        }
        limpiarPantalla();
        getch();
        endwin();


}

void Pastafari::limpiarPantalla(){
	for (int i = 0; i < LINES; i++){
                for (int j = 0; j < COLS; j++){
                        mvprintw(i,j," ");
                }
        }
}

void Pastafari::historia(){
		string historia;
        limpiarPantalla();
}