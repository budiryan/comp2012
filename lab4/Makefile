all: partA.exe partB.exe

partA.exe: partA.o Engine.o Car.o PoliceCar.o
	g++ -o partA.exe partA.o Engine.o Car.o PoliceCar.o

partB.exe: partB.o Vehicle.o Engine.o DeliveryCar.o
	g++ -o partB.exe partB.o Vehicle.o Engine.o DeliveryCar.o

partA.o: main_A.cpp Engine.h Car.h PoliceCar.h
	g++ -o partA.o -c main_A.cpp
	
partB.o: main_B.cpp Vehicle.h Engine.h DeliveryCar.h
	g++ -o partB.o -c main_B.cpp
	
Engine.o: Engine.cpp Engine.h
	g++ -c Engine.cpp 
	
Car.o: Car.cpp Car.h Engine.h
	g++ -c Car.cpp

Vehicle.o: Vehicle.cpp Vehicle.h Engine.h
	g++ -c Vehicle.cpp
	
PoliceCar.o: PoliceCar.cpp PoliceCar.h Car.h Engine.h
	g++ -c PoliceCar.cpp

DeliveryCar.o: DeliveryCar.cpp DeliveryCar.h Vehicle.h Engine.h
	g++ -c DeliveryCar.cpp

clean:
	rm -rf *.o
	rm -rf *.exe