all: testa_romanos

compile: romanos.o

test: testa_romanos
	./testa_romanos

cpplint:
	cpplint --exclude=catch.hpp *.*

gcov: romanos.gcda
	gcov romanos.cpp

debug: romanos.o
	g++ -std=c++11 -Wall -g romanos.o testa_romanos.cpp -o testa_romanos
	gdb testa_romanos

cppcheck:
	cppcheck --enable=warning .

valgrind: testa_romanos
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_romanos

romanos.o: romanos.cpp romanos.hpp
	g++ -std=c++11 -Wall -Wall -fprofile-arcs -ftest-coverage -c romanos.cpp

testa_romanos: testa_romanos.cpp romanos.o
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage romanos.o testa_romanos.cpp -o testa_romanos

clean:
	rm -rf *.o *.exe *.gc*
