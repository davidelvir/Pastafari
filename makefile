Main: Main.o Persona.o Administrador.o Jugador.o Item.o Personaje.o Humano.o Enano.o Noble.o Guerrero.o Ladron.o Witcher.o EnanoGuerrero.o EnanoHerrero.o Elfo.o ElfoGuerrero.o ElfoSanador.o Bestia.o Burro.o Dragon.o Caballo.o 
	g++ Main.o Persona.o Administrador.o Jugador.o Item.o Personaje.o Humano.o Enano.o Noble.o Guerrero.o Ladron.o Witcher.o EnanoGuerrero.o EnanoHerrero.o Elfo.o ElfoGuerrero.o ElfoSanador.o Bestia.o Burro.o Dragon.o Caballo.o -lncurses -o Main

Main.o: Main.cpp Persona.h Administrador.h Jugador.h Item.h Personaje.h Humano.h Noble.h Guerrero.h Ladron.h Witcher.h Enano.h EnanoGuerrero.h EnanoHerrero.h Elfo.h ElfoGuerrero.h ElfoSanador.h Bestia.h Burro.h Dragon.h Caballo.h 
	g++ -c Main.cpp
 
Persona.o: Persona.cpp Persona.h 
	g++ -c Persona.cpp 
 
Administrador.o:  Administrador.h Administrador.cpp Persona.h 
	g++ -c Administrador.cpp 
 
Jugador.o:  Jugador.h Jugador.cpp Persona.h 
	g++ -c Jugador.cpp 
 
Item.o: Item.cpp Item.h 
	g++ -c Item.cpp 
 
Personaje.o: Personaje.cpp Personaje.h 
	g++ -c Personaje.cpp 
 
Humano.o:  Humano.h Humano.cpp Personaje.h 
	g++ -c Humano.cpp 
 
Enano.o:  Enano.h Enano.cpp Personaje.h 
	g++ -c Enano.cpp 
	 
Elfo.o:  Elfo.h Elfo.cpp Personaje.h 
	g++ -c Elfo.cpp 
 
Noble.o:  Noble.h Noble.cpp Humano.h 
	g++ -c Noble.cpp 
 
Guerrero.o:  Guerrero.h Guerrero.cpp Humano.h 
	g++ -c Guerrero.cpp 
 
Ladron.o:  Ladron.h Ladron.cpp Humano.h 
	g++ -c Ladron.cpp 
 
Witcher.o:  Witcher.h Witcher.cpp Humano.h 
	g++ -c Witcher.cpp 
 
EnanoGuerrero.o:  EnanoGuerrero.h EnanoGuerrero.cpp Enano.h 
	g++ -c EnanoGuerrero.cpp 
 
EnanoHerrero.o:  EnanoHerrero.h EnanoHerrero.cpp Enano.h 
	g++ -c EnanoHerrero.cpp 
 
ElfoGuerrero.o:  ElfoGuerrero.h ElfoGuerrero.cpp Elfo.h 
	g++ -c ElfoGuerrero.cpp 
 
ElfoSanador.o:  ElfoSanador.h ElfoSanador.cpp Elfo.h 
	g++ -c ElfoSanador.cpp 
	 
Bestia.o: Bestia.cpp Bestia.h 
	g++ -c Bestia.cpp 
 
Burro.o:  Burro.h Burro.cpp Bestia.h 
	g++ -c Burro.cpp 
 
Dragon.o:  Dragon.h Dragon.cpp Bestia.h 
	g++ -c Dragon.cpp 
 
Caballo.o:  Caballo.h Caballo.cpp Bestia.h 
	g++ -c Caballo.cpp 
 
clean: 
	rm -f *.0 *.main
