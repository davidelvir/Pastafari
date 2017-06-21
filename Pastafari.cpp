#include "Pastafari.h"
#include <vector>
#include <typeinfo>

using namespace std;

void guardarJugadorTXT(Jugador*);
void guardarPersonajeTXT(Personaje*);
vector<Jugador*> cargarJugadorTXT(vector<Jugador*>, ifstream&);
void cargarPersonaje2TXT(vector<Personaje*>, Jugador*, ifstream&, int);

void Pastafari::run(){

    Jugador jugadorRaiz;
    Administrador adminRaiz;
    adminRaiz.setUsername("u");
    adminRaiz.setPassword("p");
    vector<Jugador*> jugadores;
    vector <Jugador*> jugadores2;

    ifstream file("Jugador.txt");

    if(file.is_open()){
        jugadores = cargarJugadorTXT(jugadores2, file);
    }
    file.close();

    vector<Personaje*> tempPersonajes;

    ifstream file2("Personajes.txt");

    if(jugadores.size()==0){
    if(file2.is_open()){
        for (int i = 0; i < jugadores.size(); ++i){

            cargarPersonaje2TXT(tempPersonajes, jugadores[i], file2, i);
        }

    }
    }
    

    bool juego = true;
    int opcionMenu;
    string menuPrincipal;
    menuPrincipal="s";

    while(menuPrincipal=="s"||menuPrincipal=="S"){
                initscr();                      /* Start curses mode */
        start_color();
        refresh();      
        opcionMenu =  menu();
        
        if(opcionMenu == 1)
        {
           refresh();
           echo();
           clear();
           char resp[100];
           Jugador* jugadorTemp2;
           jugadorTemp2 = agregarJugador(jugadores);
           jugadores.push_back(jugadorTemp2);
           guardarJugadorTXT(jugadorTemp2);

           clear();   

           mvprintw(2, 10, "Se agrego exitosamente!");

           mvprintw(3, 10, "Presione enter para continuar...");
           getstr(resp);
           clear();


       }else if(opcionMenu == 2){
        exit(0);

    }
    if(opcionMenu == 0){

        start_color();
        echo();
        limpiarPantalla();
        juego=true;
        while(juego == true)
        {
            char resp[2];
            mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL"); 
            mvprintw(3, 10, "-----------------------------------");
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
                            char resp2[8];
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
                                                    clear();
                                                    listarJugadores(jugadores);
                                                    mvprintw(1, 10, "Presione enter para salir: ");
                                                    getstr(resp);
                                                    clear();
                                                }//end respInt 2
                                                if(menuAdmin[0]=='3'){
                                                   int pos;
                                                   clear();
                                                   mvprintw(2, 10, "BORRAR CUENTA: ");
                                                   mvprintw(3, 10, "Ingrese cuenta que desearia borrar: ");
                                                   getstr(resp);
                                                   string temporal(resp);
                                                   int b = atoi(temporal.c_str());
                                                   jugadores.erase(jugadores.begin()+pos);
                                                   clear();
                                                   mvprintw(2, 10, "Se elimino exitosamente el jugador! ");
                                                   mvprintw(3, 10, "Presione enter para salir: ");
                                                   getstr(resp);

                                                }//end respInt 3
                                                if(menuAdmin[0]=='4'){

                                                    //autodestruccion

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
                              Jugador* raiz=jugadores[i];
                              bool loginRaiz=true;
                              initscr();
                              clear();
                              while(loginRaiz==true){
                                  int menuJugadorTemp;
                                  menuJugadorTemp=menuJugador();
                                  if(menuJugadorTemp==0){
                                        //Crear personaje nuevo o continuar(si personaje es null tire un mensaje)
                                    int menuContinuar;
                                    menuContinuar = menuPersonaje();
                                            if(menuContinuar==0){//NEW GAME
                                                if(raiz->getPersonaje()==NULL){
                                                    clear();
                                                    refresh();
                                                    echo();
                                                    initscr();
                                                    mvprintw(2, 10, "INGRESE JUGADOR QUE DESEA CREAR: ");
                                                    mvprintw(3, 10, "1) WITCHER");
                                                    mvprintw(4, 10, "2) GUERRERO");
                                                    mvprintw(5, 10, "3) ELFO GUERRERO");
                                                    mvprintw(6, 10, "Ingrese opcion: ");
                                                    getstr(resp);
                                                    string temporal2(resp);
                                                    if(temporal2=="1"){

                                                        Personaje* witcher = new Witcher();
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE NOMBRE DE SU WITCHER: ");
                                                        getstr(resp);
                                                        string nombre(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE APODO DE SU WITCHER: ");
                                                        getstr(resp);
                                                        string Reputacion(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE EL ESTILO DEL CABELLO PARA WITCHER: ");
                                                        getstr(resp);
                                                        string c(resp);
                                                        
                                                        witcher->setNombre(nombre);
                                                        witcher->setReputacion(Reputacion);
                                                        witcher->setEstiloCabello(c);


                                                        raiz->setPersonaje(witcher);

                                                        clear();
                                                    }else if(temporal2=="2"){
                                                        Humano* guerrero = new Guerrero();
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE NOMBRE DE SU GUERRERO: ");
                                                        getstr(resp);
                                                        string nombre(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE APODO DE SU GUERRERO: ");
                                                        getstr(resp);
                                                        string Reputacion(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE EL ESTILO DEL CABELLO PARA GUERRERO: ");
                                                        getstr(resp);
                                                        string c(resp);
                                                        mvprintw(2, 10, "INGRESE EL COLOR DE PIEL PARA EL GUERRERO: ");
                                                        getstr(resp);
                                                        string l(resp);
                                                        guerrero->setNombre(nombre);
                                                        guerrero->setReputacion(Reputacion);
                                                        guerrero->setEstiloCabello(c);
                                                        guerrero->setColor(l);


                                                        raiz->setPersonaje(guerrero);
                                                    }else if(temporal2 == "3"){
                                                        Elfo* elfoGuerrero = new ElfoGuerrero();
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE NOMBRE DE SU ELFOGUERRERO: ");
                                                        getstr(resp);
                                                        string nombre(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE APODO DE SU ELFOGUERRERO: ");
                                                        getstr(resp);
                                                        string Reputacion(resp);
                                                        clear();
                                                        mvprintw(2, 10, "INGRESE EL TAMAÑO DE OREJAS PARA EL GUERRERO: ");
                                                        getstr(resp);
                                                        string l(resp);
                                                        int lo=atoi(l.c_str());
                                                        elfoGuerrero->setNombre(nombre);
                                                        elfoGuerrero->setReputacion(Reputacion);
                                                        elfoGuerrero->setTamOrejas(lo);


                                                        raiz->setPersonaje(elfoGuerrero);
                                                    }else{
                                                       clear();
                                                       mvprintw(2, 10, "No existe esa opcion...");
                                                       clear();
                                                   }
                                               }else{
                                                clear();
                                                mvprintw(2, 10, "Ya tiene un personaje!");
                                                mvprintw(3, 10, "Presione enter para seguir: ");
                                                getstr(resp);
                                                clear();

                                            }
                                        }
                                            if(menuContinuar==1){//CONTINUAR PARTIDA
                                                if(raiz->getPersonaje()!=NULL){
                                                    clear();
                                                    refresh();
                                                    echo();
                                                    initscr();  
                                                    bool esferas = false;
                                                    bool boolPartida = true;
                                                    while(boolPartida==true){
                                                        clear();
                                                        mvprintw(2, 10, "1.) Modo historia");
                                                        mvprintw(3, 10, "2.) Tienda");
                                                        mvprintw(4, 10, "3.) Entrenar con el Maestro-Jedi Ing.Bocanegra");
                                                        mvprintw(5, 10, "4.) Guardar Partida");
                                                        mvprintw(6, 10, "5.) Atras...");
                                                        mvprintw(7, 10, "6.) Cortar Pelo");
                                                        if(raiz->getPersonaje()->getBolas()==7){
                                                            mvprintw(8, 10, "7.) Pedir deseo a Shen Long");
                                                            esferas = true;
                                                        }
                                                        getstr(resp);
                                                        clear();
                                                        string tempResp(resp);
                                                        if(tempResp=="1"){
                                                            Batalla* b1 = new Batalla();
                                                            //Modo  Historia
                                                            //5 batallas!
                                                            int nivel = raiz->getPersonaje()->getNivel();
                                                            if(nivel==1){
                                                                historia();
                                                                //Historia 1, llamamos a un metodo ue cuenta la primera historia
                                                                //con ncurses y luego la batalla;
                                                                Personaje* enemigo1= new Guerrero();
                                                                enemigo1->setNombre("Ex Rey Oswaldo");
                                                                Personaje* enemigo2= new Guerrero();
                                                                enemigo2->setNombre("Alexi Cruz");
                                                                Personaje* enemigo3= new Guerrero();
                                                                enemigo3->setNombre("Marty McFly");

                                                                vector <Personaje*> enemigos;

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);


                                                                Personaje* Aliado1= new Witcher();
                                                                Aliado1->setNombre("Jahaziel");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("Alessandro");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);

                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,1);
                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+1000);
                                                                raiz->getPersonaje()->setNivel(n+1);
                                                                raiz->getPersonaje()->setBolas(raiz->getPersonaje()->getBolas()+1);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }
                                                                
                                                            }

                                                            if(nivel==2){

                                                                Personaje* enemigo1= new Witcher();
                                                                enemigo1->setNombre("Osman");
                                                                Personaje* enemigo2= new ElfoGuerrero();
                                                                enemigo2->setNombre("David Leonel");
                                                                Personaje* enemigo3= new Guerrero();
                                                                enemigo3->setNombre("David El TOPO");
                                                                Personaje* enemigo4= new Guerrero();
                                                                enemigo4->setNombre("Dennis");

                                                                vector <Personaje*> enemigos;

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);
                                                                enemigos.push_back(enemigo4);

                                                                Personaje* Aliado1= new ElfoGuerrero();
                                                                Aliado1->setNombre("Maluma BABY");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("RICKY MARTIN");
                                                                Personaje* Aliado3= new Witcher();
                                                                Aliado3->setNombre("Freddie Mercury");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);
                                                                raiz->getPersonaje()->setAliado(Aliado3);
                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,2);

                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+1100);
                                                                raiz->getPersonaje()->setNivel(n+1);
                                                                raiz->getPersonaje()->setBolas(raiz->getPersonaje()->getBolas()+1);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }
                                                                
                                                            }                                                            

                                                            if(nivel==3){

                                                                Personaje* enemigo1= new Witcher();
                                                                enemigo1->setNombre("Optimus Prime");
                                                                Personaje* enemigo2= new Witcher();
                                                                enemigo2->setNombre("HELL-BERT");
                                                                Personaje* enemigo3= new Guerrero();
                                                                enemigo3->setNombre("Madonna");
                                                                Personaje* enemigo4= new Guerrero();
                                                                enemigo4->setNombre("Chum Lee");

                                                                vector <Personaje*> enemigos;

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);
                                                                enemigos.push_back(enemigo4);

                                                                Personaje* Aliado1= new Guerrero();
                                                                Aliado1->setNombre("Aceituno");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("Anastacio");
                                                                Personaje* Aliado3= new Witcher();
                                                                Aliado3->setNombre("METERPRETER");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);
                                                                raiz->getPersonaje()->setAliado(Aliado3);
                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,3);
                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+1200);
                                                                raiz->getPersonaje()->setNivel(n+1);
                                                                raiz->getPersonaje()->setBolas(raiz->getPersonaje()->getBolas()+1);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }
                                                                

                                                            }

                                                            if(nivel==4){
                                                                Personaje* enemigo1= new Witcher();
                                                                enemigo1->setNombre("Optimus Prime");
                                                                Personaje* enemigo2= new Witcher();
                                                                enemigo2->setNombre("HELL-BERT");
                                                                Personaje* enemigo3= new Guerrero();
                                                                enemigo3->setNombre("Madonna");
                                                                Personaje* enemigo4= new Guerrero();
                                                                enemigo4->setNombre("Chum Lee");

                                                                vector <Personaje*> enemigos;

                                                                enemigo4->setVida(900);
                                                                enemigo4->setDefensa(200);
                                                                enemigo4->setAtaque(300);

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);
                                                                enemigos.push_back(enemigo4);

                                                                Personaje* Aliado1= new Guerrero();
                                                                Aliado1->setNombre("Aceituno");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("Anastacio");
                                                                Personaje* Aliado3= new Witcher();
                                                                Aliado3->setNombre("METERPRETER");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);
                                                                raiz->getPersonaje()->setAliado(Aliado3);
                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,4);
                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+1300);
                                                                raiz->getPersonaje()->setNivel(n+1);
                                                                raiz->getPersonaje()->setBolas(raiz->getPersonaje()->getBolas()+1);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }
                                                                


                                                            }

                                                            if(nivel==5){

                                                                Personaje* enemigo1= new Witcher();
                                                                enemigo1->setNombre("Juan Orlando");
                                                                Personaje* enemigo2= new Witcher();
                                                                enemigo2->setNombre("HELL-BERT FASE 2");
                                                                Personaje* enemigo3= new Witcher();
                                                                enemigo3->setNombre("ADOLFO HITLER");
                                                                Personaje* enemigo4= new Guerrero();
                                                                enemigo4->setNombre("LUCIFER");
                                                                Personaje* enemigo5= new ElfoGuerrero();
                                                                enemigo5->setNombre("ZEUS");

                                                                enemigo2->setVida(1500);
                                                                enemigo2->setDefensa(400);
                                                                enemigo2->setAtaque(500);

                                                                vector <Personaje*> enemigos;

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);
                                                                enemigos.push_back(enemigo4);
                                                                enemigos.push_back(enemigo5);


                                                                Personaje* Aliado1= new Witcher();
                                                                Aliado1->setNombre("JESUS");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("ALLAH");
                                                                Personaje* Aliado3= new ElfoGuerrero();
                                                                Aliado3->setNombre("GAUTAMA BUDDAH");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);
                                                                raiz->getPersonaje()->setAliado(Aliado3);
                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,5);
                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+2000);
                                                                raiz->getPersonaje()->setNivel(n+1);
                                                                raiz->getPersonaje()->setBolas(raiz->getPersonaje()->getBolas()+2);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }
                                                                
                                                            }


                                                            if(nivel==6&&raiz->getPersonaje()->getBolas()==7){
                                                                //Con las esferas del dragon contra nasralla!


                                                                Personaje* enemigo1= new Witcher();
                                                                enemigo1->setNombre("Donald Trump");
                                                                Personaje* enemigo2= new Witcher();
                                                                enemigo2->setNombre("Elvis Presley");
                                                                Personaje* enemigo3= new Witcher();
                                                                enemigo3->setNombre("NATHALÍA (EX ALESSANDRO)");
                                                                Personaje* enemigo4= new Guerrero();
                                                                enemigo4->setNombre("VALERIA (Ex DAVID)-TICA");
                                                                Personaje* enemigo5= new Witcher();
                                                                enemigo5->setNombre("PAOLA (Ex JAHAZIEL)");
                                                                Personaje* enemigo6= new ElfoGuerrero();
                                                                enemigo6->setNombre("SALVADOR NASRALLA");

                                                                enemigo6->setVida(5000);
                                                                enemigo6->setDefensa(900);
                                                                enemigo6->setAtaque(900);
                                                                
                                                                vector <Personaje*> enemigos;

                                                                enemigos.push_back(enemigo1);
                                                                enemigos.push_back(enemigo2);
                                                                enemigos.push_back(enemigo3);
                                                                enemigos.push_back(enemigo4);
                                                                enemigos.push_back(enemigo5);
                                                                enemigos.push_back(enemigo6);


                                                                Personaje* Aliado1= new Guerrero();
                                                                Aliado1->setNombre("LEMPIRA");
                                                                Personaje* Aliado2= new Guerrero();
                                                                Aliado2->setNombre("GAL GADOT");
                                                                Personaje* Aliado3= new ElfoGuerrero();
                                                                Aliado3->setNombre("Scarlett Johansson");
                                                                Personaje* Aliado4= new Guerrero();
                                                                Aliado3->setNombre("ALESSANDRO FASE 2");
                                                                Personaje* Aliado5= new ElfoGuerrero();
                                                                Aliado3->setNombre("JAHAZIEL FASE 3");
                                                                Personaje* Aliado6= new ElfoGuerrero();
                                                                Aliado3->setNombre("DAVID FASE 2 /MALUMA-(FUSION)");

                                                                raiz->getPersonaje()->setAliado(Aliado1);
                                                                raiz->getPersonaje()->setAliado(Aliado2);
                                                                raiz->getPersonaje()->setAliado(Aliado3);
                                                                raiz->getPersonaje()->setAliado(Aliado4);
                                                                raiz->getPersonaje()->setAliado(Aliado5);
                                                                raiz->getPersonaje()->setAliado(Aliado6);

                                                                b1->BatallaEpica(raiz->getPersonaje(), enemigos,6);
                                                                clear();
                                                                
                                                                mvprintw(3, 10, "La batalla epica ha concluido!");
                                                                mvprintw(4, 10, "Presione [Enter] para continuar...");
                                                                getstr(resp);
                                                                int n =raiz->getPersonaje()->getNivel();

                                                                int pastaTemp = raiz->getPersonaje()->getDinero();
                                                                raiz->getPersonaje()->setDinero(pastaTemp+800);
                                                                raiz->getPersonaje()->setNivel(n+1);

                                                                for (int i = 0; i < raiz->getPersonaje()->getAliados().size(); ++i)
                                                                {
                                                                    raiz->getPersonaje()->getAliados().erase(raiz->getPersonaje()->getAliados().begin()+i); 

                                                                }

                                                            }

                                                        }
                                                        if(tempResp=="2"){
                                                            //Tienda
                                                            raiz->getPersonaje()->Comprar(raiz->getPersonaje()->getDinero());

                                                        }
                                                        if(tempResp=="3"){
                                                            //Entrenar
                                                            raiz->getPersonaje()->Entrenamiento();
                                                        }

                                                        if(tempResp=="4"){
                                                            //Guardar Personaje
                                                        	guardarPersonajeTXT(raiz->getPersonaje());


                                                        }

                                                        if(tempResp=="5"){
                                                            boolPartida=false;
                                                        }
                                                        if(tempResp=="7"){
                                                            if(esferas==true){
                                                                //Deseos
                                                                raiz->getPersonaje()->BolasDelDragon();
                                                                esferas=false;

                                                            }else{
                                                                clear();
                                                                mvprintw(2, 10, "OPCION INCORRECTA");
                                                                mvprintw(2, 10, "Ingrese [ENTER] para continuar:");
                                                                getstr(resp);
                                                                clear();
                                                            }
                                                        }//fin temp resp

                                                        if(tempResp=="6"){
                                                            //cortar pelo
                                                            raiz->getPersonaje()->CortarPelo(raiz->getPersonaje()->getDinero());

                                                        }

                                                    }//fin while
                                                }
                                            }
                                            if(menuContinuar==2){//LOGOUT
                                                juego = false;
                                                break;
                                            }

                                        }
                                        if(menuJugadorTemp==1){
                                            historia();
                                        }
                                        if(menuJugadorTemp==2){
                                            juego=false;
                                            loginRaiz=false;
                                        }

                        	}//while loginRaiz
                        }//password usuario
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
                refresh();
                echo();
                initscr();
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
      clear();
      char resp[100];
      mvprintw(1, 20,"LA HISTORIA DEL PASTAFARISMO, como una religion nacio");
      mvprintw(2, 20,"para morirse... Erase una vez en una universidad muy");
      mvprintw(3, 20,"conocida de Honduras, un grupo de programadores embistiendo");
      mvprintw(4, 20,"los largos codigos de un laboratorio, cuando ninguno de ellos");
      mvprintw(5, 20,"se imagino que revolucionarian la historia, ahi queridos amigos");
      mvprintw(6, 20,"nacio el PASTAFARISMO, pero antes de continuar, ¿Que significa el");
      mvprintw(7, 20,"PASTAFARISMO? Sin duda es una religion absoluta, que su ideologia");
      mvprintw(8, 20,"pseudo-existente consume todas las entrañas de los seres humanos como");
      mvprintw(9, 20,"tal convirtiendolos en zombies sin razon, y sin derecho a cuestionarse");
      mvprintw(10, 20,"es un dictamen que les dicen como hablar y que comer... Estos eran los dias");
      mvprintw(11, 20,"que todo el amor en el mundo desaparecio, y nadie se habia dado cuenta...");
      mvprintw(12, 20,"Este dia comienza un mundo que ya termino, comienza un mundo que grita");
      mvprintw(13, 20,"auxilio desesperadamente, un mundo donde los consumidos por MONESVOL");
      mvprintw(14, 20,"como dictado por la religion catolica, ya no tienen alma, son seres"); 
      mvprintw(15, 20,"impuros con una personalidad pecaminosa, que su unico proposito es");
      mvprintw(16, 20,"dañar todo lo bueno que tenemos en este mundo...");
      mvprintw(17, 20,"Ahora que ya sabes lo que te enfrentas, ¿TENDRAS LAS AGALLAS PARA");
      mvprintw(18, 20,"VENCER A NASRALLA Y DEVOLVERLE EL PODER AL REY OSWALDO/HERMANO DE");
      mvprintw(19, 20, "RICKY MARTIN?!");

      mvprintw(20, 20, "Clickee [ENTER] para continuar...");
      getstr(resp);
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

int Pastafari :: menu(){
    int temp;
    init_pair(1, COLOR_GREEN, COLOR_BLACK );
    bkgd( COLOR_PAIR(1) );
    noecho();
    cbreak();
    mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL"); 
    mvprintw(3, 10, "-----------------------------------");  
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * menuwin = newwin(5, xMax-120, yMax-43,10);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    string choices[3]={"LOGIN","CREAR CUENTA", "SALIR"};
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
    temp = highlight;
    return temp;
}

int Pastafari::menuJugador(){
    int temp;
    init_pair(2, COLOR_BLACK, COLOR_GREEN);;
    bkgd( COLOR_PAIR(1) );
    noecho();
    cbreak();
    mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL"); 
    mvprintw(3, 10, "-----------------------------------"); 

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * menuwin = newwin(5, xMax-120, yMax-43,10);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    string choices[3]={"COMENZAR HISTORIA...","ABOUT...", "LOGOUT"};
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
    temp = highlight;
    return temp;
}

int Pastafari :: menuPersonaje(){
    int temp;
    init_pair(2, COLOR_BLACK, COLOR_GREEN);;
    bkgd( COLOR_PAIR(1) );
    noecho();
    cbreak();
    mvprintw(2, 10, "PASTAFARI: LA VENGANZA DE MONESVOL"); 
    mvprintw(3, 10, "-----------------------------------");  
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW * menuwin = newwin(5, xMax-120, yMax-43,10);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    string choices[3]={"NEW GAME","CONTINUAR...", "LOGOUT"};
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
    temp = highlight;
    return temp;
}

void Pastafari :: listarJugadores(vector<Jugador*> jugadores){
   char temp1[3];
   for (int i = 0; i < jugadores.size(); ++i)
   {
    stringstream temp2;
    string temp;
    temp2 << i<<".) "<<"Nombre: " << jugadores[i]->getNombre()<<", Username: "
    << jugadores[i]->getUsername()<<", Password: "
    << jugadores[i]->getEdad()<<", Carrera: "
    << jugadores[i]->getCarrera();
    temp = temp2.str();
    char *cstr = new char[temp.length() + 1];
    strcpy(cstr, temp.c_str());         
    mvprintw(i+2, 10, cstr);
    delete [] cstr;
}

}

void Pastafari::sleep(int a)
{
    time_t t1,t2;
    t1 = time(NULL);
    t2 = time(NULL);
    while ((t2 - t1)*1000 < a)
        t2 = time(NULL);
}

void guardarJugadorTXT(Jugador* p){
  ofstream archivo;
  string ruta="Nombres.txt";
  stringstream ss;
  ss<<"Jugador.txt";   

  ruta=ss.str();
  archivo.open(ruta.c_str(),ios::app);

  archivo<<p->getNombre()<<endl<<p->getUsername()<<endl<< p->getPassword()<<endl<<p->getEdad()<<endl<<p->getCarrera()<<endl;
  archivo<<"w"<<endl;

/*
  */
archivo.close();

}

vector<Jugador*> cargarJugadorTXT(vector<Jugador*> jugadores, ifstream &file){


    while(!file.eof()){

        Jugador* jugador= new Jugador();

        file>>*jugador;
        jugadores.push_back(jugador);

    }

    return jugadores;
}

void guardarPersonajeTXT(Personaje* p){

    ofstream archivo;
    string ruta="Nombres.txt";
    stringstream ss;
    ss<<"Personajes.txt";   

    ruta=ss.str();
    archivo.open(ruta.c_str(),ios::app);

    archivo<<p->getNombre()<<endl;
    archivo<<p->getVida()<<endl;
    archivo<<p->getDefensa()<<endl;
    archivo<<p->getAtaque()<<endl;
    archivo<<p->getReputacion()<<endl;
    archivo<<p->getNivel()<<endl;
    archivo<<p->getExp()<<endl;
    archivo<<p->getBolas()<<endl;
    //archivo<<p->getReputacion()<<endl;
    archivo<<p->getEstiloCabello()<<endl;
    archivo<<p->getDinero()<<endl;
    archivo.close();

}

void cargarPersonaje2TXT(vector<Personaje*> personajes, Jugador* destino, ifstream& file, int n){

    while(!file.eof()){

        Personaje* personaje;

        if(destino->getN()=="w"){
            personaje = new Witcher();

        }
        if(destino->getN()=="g"){
            personaje = new Guerrero();   
        }
        if(destino->getN()=="e"){
            personaje = new ElfoGuerrero();
        }

        file>>*personaje;
        personajes.push_back(personaje);

    }

    destino->setPersonaje(personajes[n]);


}










