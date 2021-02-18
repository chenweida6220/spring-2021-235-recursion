main: main.o knights.o
	g++ -o main main.o knights.o

main.o: main.cpp knights.h

knights.o: knights.cpp knights.h

clean:
	rm -f a.out main main.o knights.o
