Main: Main.o Persona.o Admin.o Jugador.o Personaje.o Humano.o Enano.o Elfo.o Criatura.o guerreroHumano.o Sacerdote.o Brujo.o Mago.o Ladron.o Enano.o enanoGuerrero.o Herrero.o Elfo.o Sanador.o elfoGuerrero.o Trolls.o Duendes.o Bestias.o Burro.o Caballo.o Dragon.o Batalla.o Pueblo.o 
	g++ Main.o Persona.o Admin.o Jugador.o Personaje.o Humano.o Enano.o Elfo.o Criatura.o guerreroHumano.o Sacerdote.o Brujo.o Mago.o Ladron.o Enano.o enanoGuerrero.o Herrero.o Elfo.o Sanador.o elfoGuerrero.o Trolls.o Duendes.o Bestias.o Burro.o Caballo.o Dragon.o Batalla.o Pueblo.o -o Main

Main.o: Main.cpp Persona.h Admin.h Jugador.h Personaje.h Humano.h Enano.h Elfo.h Criatura.h guerreroHumano.h Sacerdote.h Brujo.h Mago.h Ladron.h Enano.h enanoGuerrero.h Herrero.h Elfo.h Sanador.h elfoGuerrero.h Trolls.h Duendes.h Bestias.h Burro.h Caballo.h Dragon.h Batalla.h Pueblo.h 
	g++ -c Main.cpp
 
Persona.o: Persona.cpp Persona.h 
	g++ -c Persona.cpp 
 
Admin.o:  Admin.h Admin.cpp Persona.h 
	g++ -c Admin.cpp 
 
Jugador.o:  Jugador.h Jugador.cpp Persona.h 
	g++ -c Jugador.cpp 
 
Personaje.o: Personaje.cpp Personaje.h 
	g++ -c Personaje.cpp 
 
Humano.o:  Humano.h Humano.cpp Personaje.h 
	g++ -c Humano.cpp 
 
Enano.o:  Enano.h Enano.cpp Personaje.h 
	g++ -c Enano.cpp 
 
Elfo.o:  Elfo.h Elfo.cpp Personaje.h 
	g++ -c Elfo.cpp 
 
Criatura.o:  Criatura.h Criatura.cpp Personaje.h 
	g++ -c Criatura.cpp 
 
guerreroHumano.o:  guerreroHumano.h guerreroHumano.cpp Humano.h Personaje.h
	g++ -c guerreroHumano.cpp 
 
Sacerdote.o:  Sacerdote.h Sacerdote.cpp Humano.h Personaje.h
	g++ -c Sacerdote.cpp 
 
Brujo.o:  Brujo.h Brujo.cpp Humano.h Personaje.h
	g++ -c Brujo.cpp 
 
Mago.o:  Mago.h Mago.cpp Humano.h Personaje.h
	g++ -c Mago.cpp 
 
Ladron.o:  Ladron.h Ladron.cpp Humano.h Personaje.h
	g++ -c Ladron.cpp 
 
Enano.o: Enano.cpp Enano.h Personaje.h
	g++ -c Enano.cpp 
 
enanoGuerrero.o:  enanoGuerrero.h enanoGuerrero.cpp Enano.h Personaje.h
	g++ -c enanoGuerrero.cpp 
 
Herrero.o:  Herrero.h Herrero.cpp Enano.h Personaje.h
	g++ -c Herrero.cpp 
 
Elfo.o: Elfo.cpp Elfo.h Personaje.h
	g++ -c Elfo.cpp 
 
Sanador.o:  Sanador.h Sanador.cpp Elfo.h Personaje.h
	g++ -c Sanador.cpp 
 
elfoGuerrero.o:  elfoGuerrero.h elfoGuerrero.cpp Elfo.h Personaje.h
	g++ -c elfoGuerrero.cpp 
 
Trolls.o: Trolls.cpp Trolls.h Personaje.h
	g++ -c Trolls.cpp 
 
Duendes.o: Duendes.cpp Duendes.h Personaje.h
	g++ -c Duendes.cpp 
 
Bestias.o: Bestias.cpp Bestias.h 
	g++ -c Bestias.cpp 
 
Burro.o:  Burro.h Burro.cpp Bestias.h 
	g++ -c Burro.cpp 
 
Caballo.o:  Caballo.h Caballo.cpp Bestias.h 
	g++ -c Caballo.cpp 
 
Dragon.o:  Dragon.h Dragon.cpp Bestias.h 
	g++ -c Dragon.cpp 
 
Batalla.o: Batalla.cpp Batalla.h 
	g++ -c Batalla.cpp 
 
Pueblo.o: Pueblo.cpp Pueblo.h 
	g++ -c Pueblo.cpp 
 
clean: 
	rm -f *.0 *.main
