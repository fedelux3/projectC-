
main.exe:  main.o grafoexception.o
	g++ main.o grafoexception.o -o main.exe

main.o: main.cpp grafo.h
	g++ -c main.cpp -o main.o

grafoexception.o: grafoexception.cpp
	g++ -c grafoexception.cpp -o grafoexception.o

clean:
	rm *.o *.exe
