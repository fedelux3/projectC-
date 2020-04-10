
main.exe:  main.o sortedexception.o
	g++ main.o sortedexception.o -o main.exe

main.o: main.cpp sortedArray.h
	g++ -c main.cpp -o main.o

sortedexception.o: sortedException.cpp
	g++ -c sortedException.cpp -o sortedexception.o

clean:
	rm *.o *.exe