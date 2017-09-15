main: main.o Luchador.o Guerrero.o Aprendiz.o Mago.o Alquimista.o Dragonborn.o
	g++ main.o Luchador.o Guerrero.o Aprendiz.o Mago.o Alquimista.o Dragonborn.o -o main

main.o: main.cpp Luchador.h Aprendiz.h Guerrero.h Mago.h Alquimista.h Dragonborn.h
	g++ -c main.cpp

Luchador.o: Luchador.cpp Luchador.h
	g++ -c Luchador.cpp

Guerrero.o: Guerrero.cpp Guerrero.h Luchador.h
	g++ -c Guerrero.cpp

Aprendiz.o: Aprendiz.cpp Aprendiz.h Luchador.h
	g++ -c Aprendiz.cpp

Mago.o: Mago.cpp Mago.h Luchador.h
	g++ -c Mago.cpp

Alquimista.o: Alquimista.cpp Alquimista.h Luchador.h
	g++ -c Alquimista.cpp

Dragonborn.o: Dragonborn.cpp Dragonborn.h Luchador.h
	g++ -c Dragonborn.cpp
