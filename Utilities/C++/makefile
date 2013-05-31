all: utils
	mv utils.exe bin/

utils: main.o utilities.o
	g++ main.o utilities.o -o utils
    
main.o: src/main.cpp
	g++ -I. -c src/main.cpp

utilities.o: src/utilities.cpp
	g++ -I. -c src/utilities.cpp

clean:
	rm -rf *.o