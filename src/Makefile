main: main.o tools.o walker.o walker_nopbc.o walker_pbc.o
	g++ -o randomwalk main.o tools.o walker.o walker_nopbc.o walker_pbc.o

main.o: main.cpp
	g++ -c main.cpp

tools.o: tools.cpp tools.h
	g++ -c tools.cpp

walker.o: walker.cpp walker.h
	g++ -c walker.cpp

walker_nopbc.o: walker_nopbc.cpp walker_nopbc.h
	g++ -c walker_nopbc.cpp

walker_pbc.o: walker_pbc.cpp walker_pbc.h
	g++ -c walker_pbc.cpp
