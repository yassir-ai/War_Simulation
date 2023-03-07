SRC=main.cpp cavalerie.cpp char.cpp force_aerienne.cpp infanterie.cpp simulation.cpp soldat.cpp terrain.cpp

# compilateur
CC = g++
# options 
CFLAGS =  -lSDL2 -lSDL2_image  -g -Wall -Wextra 
# liste des fichiers objets
OBJ = main.o cavalerie.o soldat.o infanterie.o simulation.o force_aerienne.o terrain.o char.o 
# regle de production finale tp :
prog : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o prog  
	rm -rf  *.o
	@echo "Lancer le programme avec  ./prog"
# regle de production pour chaque fichier
main.o : main.cpp soldat.cpp soldat.hpp infanterie.cpp char.cpp simulation.cpp simulation.hpp force_aerienne.cpp
	$(CC) main.cpp -c $(CFLAGS)
cavalerie.o : cavalerie.cpp soldat.hpp
	$(CC) cavalerie.cpp -c $(CFLAGS)
soldat.o : soldat.cpp soldat.hpp
	$(CC) soldat.cpp -c $(CFLAGS)
force_aerienne.o : force_aerienne.cpp soldat.hpp
	$(CC) force_aerienne.cpp -c $(CFLAGS)
char.o : char.cpp soldat.hpp
	$(CC) char.cpp -c $(CFLAGS)
infanterie.o : infanterie.cpp soldat.hpp
	$(CC) infanterie.cpp -c $(CFLAGS)
simulation.o : simulation.cpp simulation.hpp
	$(CC) simulation.cpp -c $(CFLAGS)
terrain.o : terrain.cpp terrain.hpp
	$(CC) terrain.cpp -c $(CFLAGS)

# regle de suppression des fichiers
clean:
	rm -rf prog *.o