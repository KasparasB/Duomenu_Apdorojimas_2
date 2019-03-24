main: Source.o Funkcijos.o
	g++ -o main Source.o Funkcijos.o
Source.o: Source.cpp
	g++ -c Source.cpp
Funkcijos.o: Funkcijos.cpp
	g++ -c Funkcijos.cpp
clean:
	rm *.o main
