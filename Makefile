programa: main.o divide-y-venceras.o
	g++ main.o divide-y-venceras.o -o programa
main.o: main.cpp divide-y-venceras.hpp
	g++ -c main.cpp
divide-y-venceras.o: divide-y-venceras.cpp divide-y-venceras.hpp
	g++ -c divide-y-venceras.cpp
clean:
	rm -fr main.o divide-y-venceras.o
