a.out: main.o bolletta.o orario.o telefono.o
	g++ main.o bolletta.o orario.o telefono.o

main.o: main.cpp bolletta.o
	g++ -c main.cpp

orario.o: orario.cpp
	g++ -c orario.cpp

telefono.o: telefono.cpp orario.o
	g++ -c telefono.cpp

bolletta.o: bolletta.cpp telefono.o
	g++ -c bolletta.cpp

clean:
	rm *.o
	rm *.out