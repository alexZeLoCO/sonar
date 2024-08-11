CC=g++
FLAGS=-g -pg

main : main.cpp ship.o Directions.h Contact.h graph.o
	$(CC) main.cpp ship.o graph.o -o main $(FLAGS)

ship.o : Ship.cpp Ship.h Directions.h Contact.h
	$(CC) -c Ship.cpp -o ship.o $(FLAGS)

graph.o : Graph.cpp Graph.h Contact.h
	$(CC) -c Graph.cpp -o graph.o $(FLAGS)

clean :
	rm main *.o
