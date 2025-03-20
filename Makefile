programa: build/main.o build/divide-y-venceras.o
	g++ build/main.o build/divide-y-venceras.o -o programa
build/main.o: src/main.cpp src/divide-y-venceras.hpp
	g++ -c src/main.cpp -o build/main.o
build/divide-y-venceras.o: src/divide-y-venceras.cpp src/divide-y-venceras.hpp
	g++ -c src/divide-y-venceras.cpp -o build/divide-y-venceras.o
clean:
	rm -fr build/main.o build/divide-y-venceras.o
