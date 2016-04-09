all: purpleProgram.exe yellowProgram.exe

yellowProgram.exe: yellowMain.o red.o green.o
	g++ -o yellowProgram.exe yellowMain.o red.o green.o

purpleProgram.exe: purpleMain.o red.o blue.o
	g++ -o purpleProgram.exe purpleMain.o red.o blue.o

purpleMain.o: purpleMain.cpp red.h blue.h
	g++ -c purpleMain.cpp
	
yellowMain.o: yellowProgram.cpp red.h green.h
	g++ -c yellowProgram.cpp
	
red.o: red.cpp red.h
	g++ -c red.cpp 

green.o: green.cpp green.h
	g++ -c green.cpp 

blue.o: blue.cpp blue.h
	g++ -c blue.cpp 

clean:
	rm -rf *.o
	rm -rf *.exe