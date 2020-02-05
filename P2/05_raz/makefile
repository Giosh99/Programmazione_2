#Makefile conversione raz
#
raz.out: main.o raz.o
	g++ main.o raz.o
#
raz.o: raz.cpp raz.h
	g++ -c raz.cpp
#
main.o: main.cpp
	g++ -c main.cpp
#
clean:
	rm *.out
	rm *.o