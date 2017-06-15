#include "Pastafari.h"

using namespace std;

void Pastafari::run(){
	 
        Jugador jugadorRaiz;
        Administrador adminRaiz;
        adminRaiz.setUsername("u");
        adminRaiz.setPassword("p");
        vector<Jugador*> jugadores;
        Jugador* cualquiera=new Jugador("Alessandro", "QWERTY","v",20,"Ing en Sistemas");
        jugadores.push_back(cualquiera);
        bool juego = true;
 		string menuPrincipal;
        menuPrincipal="s";

        while(menuPrincipal=="s"||menuPrincipal=="S"){
                initscr();                      /* Start curses mode              */
                start_color();
                refresh();

        init_pair(1, COLOR_GREEN, COLOR_BLACK );
        bkgd( COLOR_PAIR(1) );
                noecho();
                cbreak();
                mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL");	
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
        	    refresh();
        	    echo();
        	    clear();
                char resp[2];
                Jugador* jugadorTemp2;
                jugadorTemp2 = agregarJugador(jugadores);
                jugadores.push_back(jugadorTemp2);
                clear();   
                mvprintw(2, 10, "Se agrego exitosamente!");
                mvprintw(3, 10, "Presione enter para continuar...");
                getstr(resp);
                clear();
                choices[highlight]=="LOGIN";
                   
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

                        for (int i = 0; i < jugadores.size(); i++)
                        {
                                if(adminRaiz.getUsername().compare(usuarioTemp)==0){
                                        mvprintw(5, 10, "* Ingrese la contraseña del Administrador:");
                                        getstr(resp);
                                        string contraTemp(resp);
                                        limpiarPantalla();
                                        if(adminRaiz.getPassword()==contraTemp){
                                                bool logout;
                                                logout=true;
                                                while(logout==true){
                                                        clear();
                                                        char resp2[2];
                                                mvprintw(2, 10, "MENU Administrador");
                                                mvprintw(3, 10, "1) Agregar cuentas");
                                                mvprintw(4, 10, "2) Listar cuentas");
                                                mvprintw(5, 10, "3) Borrar cuentas ");
                                                mvprintw(6, 10, "4) Autodestruccion");
                                                mvprintw(7, 10, "5) Logout");
                                                mvprintw(8, 10, "6) Salir");
                                                mvprintw(9, 10, "Ingrese opcion: ");
                                                getstr(resp2);
                                                string menuAdmin(resp2);

                                                if(menuAdmin[0]=='1'){
                                                	
                                                	Jugador* jugadorTemp;
                                                	jugadorTemp = agregarJugador(jugadores);
                                                	jugadores.push_back(jugadorTemp);
                                                	clear();
                                                    mvprintw(2, 10, "Se agrego exitosamente!");
                                                    mvprintw(3, 10, "Presione enter para continuar...");
                                                    getstr(resp2);
                         	


                                                }//end respInt 1
                                                if(menuAdmin[0]=='2'){

                                                }//end respInt 2
                                                if(menuAdmin[0]=='3'){

                                                }//end respInt 3
                                                if(menuAdmin[0]=='4'){

                                                }//end respInt 4
                                                if(menuAdmin[0]=='5'){
                                                        clear();
                                                        i=jugadores.size();
                                                        logout=false;
                                                        juego=false;
                                                        
                                                }//end respInt 5
                                                if(menuAdmin[0]=='6'){
                                                        endwin();
                                                        exit(0);


                                                }//end respInt 5
                                                if(menuAdmin[0]!='1'&&menuAdmin[0]!='2'&&menuAdmin[0]!='3'&&menuAdmin[0]!='4'&&menuAdmin[0]!='5'&&menuAdmin[0]!='6'){
                                                	clear();
                                                        mvprintw(2, 10, "Numero equivocado!");
                                                        mvprintw(3, 10, "Ingrese enter: ");
                                                        getstr(resp);
                                                }

                                        }//end logout
                                }//end contra
                        }//end usuario2
                        else if (jugadores[i]->getUsername()==usuarioTemp){
                        	char resp3[3];
                        	mvprintw(5, 10, "Ingrese la contraseña:");
                            getstr(resp3);
                            string contraTemp(resp3);
                            clear();

                        	if(jugadores[i]->getPassword().compare(contraTemp)==0){
                        		//usuario raiz
                        		initscr();
                        		clear();
                        		mvprintw(5, 10, "Chupala Jahaziel .|. 8) ");
                        		getstr(resp);
                        		clear();
                        	}
                        }//else if usuario
                        else{
                        	limpiarPantalla();
                        	if(i==jugadores.size()){
                            mvprintw(5, 10, "No existe ese usuario!");
                        	mvprintw(6, 10, "presione enter para seguir");
                   			}
                        }
                        }//end for

                }
        }
        limpiarPantalla();
        char resp[2];	
        mvprintw(8, 10, "Desea continuar? [s/n]");
        mvprintw(9, 10, "Ingrese una opcion: ");
        getstr(resp);
        clear();
        string padain(resp);
        menuPrincipal=padain;

        }
        limpiarPantalla();
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
Pastafari::Pastafari(){

}

Jugador* Pastafari:: agregarJugador(vector<Jugador*> jugadores){
	

	char resp[20];
    string strEdad, carrera;
    int numEdad;

    clear();
    mvprintw(2, 10, "Ingrese nombre:");
    getstr(resp);
    string nombre(resp);
    clear();

    mvprintw(2, 10, "Ingrese su edad:");
    getstr(resp);
    string edad(resp);
	numEdad=atoi(edad.c_str());

	while(numEdad<18){
		clear();
		mvprintw(2, 10, "No se aceptan menores de 18 años.");
		mvprintw(3, 10, "Ingrese otra edad:");
		getstr(resp);
    	string edad(resp);
		numEdad=atoi(edad.c_str());
	}

	clear();

    mvprintw(2, 10, "INGRESE CARRERA:");
    mvprintw(3, 10, "1) Ingenieria en Sistemas");
    mvprintw(4, 10, "2) Ingenieria Mecatronica");
    mvprintw(5, 10, "3) Ingenieria Biomedica");
    mvprintw(6, 10, "4) Ingenieria Civil");
    mvprintw(7, 10, "5) Ingresar licenciatura");
    mvprintw(8, 10, "Ingrese un numero: ");
    getstr(resp);
    string opcionCarrera(resp);
    int opcionTempCarrera=atoi(opcionCarrera.c_str());
    clear();

    while(opcionTempCarrera>5&&opcionTempCarrera<1){
    	clear();
    	mvprintw(2, 10, "NUMERO EQUIVOCADO!");
    	mvprintw(3, 10, "1) Ingenieria en Sistemas");
   	    mvprintw(4, 10, "2) Ingenieria Mecatronica");
        mvprintw(5, 10, "3) Ingenieria Biomedica");
        mvprintw(6, 10, "4) Ingenieria Civil");
        mvprintw(7, 10, "5) Ingresar licenciatura");
        mvprintw(8, 10, "INGRESE OTRO NUMERO: ");
        getstr(resp);
        string opcionCarrera(resp);
        opcionTempCarrera=atoi(opcionCarrera.c_str());
        clear();

    }//fin while

    	if(opcionTempCarrera==1){
    		carrera="Ingenieria en Sistemas";
    }
    	if(opcionTempCarrera==2){
    		carrera="Ingenieria en Sistemas";
    }
    	if(opcionTempCarrera==3){
    		carrera="Ingenieria en Sistemas";
    }
    	if(opcionTempCarrera==4){
    		carrera="Ingenieria en Sistemas";
    }
    while(opcionTempCarrera==5){
    	clear();
    	mvprintw(2, 10, "No aceptamos licenciados en este juego. :)");
    	mvprintw(3, 10, "Licenciados apreten el botond de enter :)");
    	getstr(resp);
    	clear();
    	mvprintw(2, 10, "INGRESE CARRERA:");
   	    mvprintw(3, 10, "1) Ingenieria en Sistemas");
    	mvprintw(4, 10, "2) Ingenieria Mecatronica");
   	    mvprintw(5, 10, "3) Ingenieria Biomedica");
  	    mvprintw(6, 10, "4) Ingenieria Civil");
  	    mvprintw(7, 10, "5) Ingresar licenciatura");
   	    mvprintw(8, 10, "Ingrese un numero: ");
   	    getstr(resp);
        string opcionCarrera(resp);
        opcionTempCarrera=atoi(opcionCarrera.c_str());
        clear();
    }
    clear();
    char resp4[4];
    mvprintw(2, 10, "Ingrese usuario:");
    getstr(resp4);
    string usuario(resp4);
    string t = usuario;
    clear();
    int verificar=0;
    while(verificar==0){
    	verificar=1;
    for (int i = 0; i < jugadores.size(); i++)
    {
    	if(t==jugadores[i]->getUsername()){
    		verificar=0;
    	}
    }
    if(verificar==0){
    	clear();	
   	    mvprintw(2, 10, "Ingrese otro usuario:");
        getstr(resp4);
        string usuario(resp);
        t = usuario;
        clear();
    }
	}//fin while


		clear();
   	    mvprintw(2, 10, "Ingrese contraseña:");
        getstr(resp);
        string contra(resp);
        clear();
        Jugador* temp;
    temp = new Jugador(nombre, t, contra, numEdad, carrera);
	return temp;
}