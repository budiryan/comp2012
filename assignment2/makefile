

ifeq (Windows_NT, $(OS))
target=pa2.exe
newtarget=newPA2.exe
lib=ncurses_lib/pdcurses
flag=_WIN_
ifeq (, $(OSTYPE))
GUESS_OS=native-windows
else
GUESS_OS=cygwin-or-msys
endif
else
GUESS_OS=MAC_OR_OTHER
target=pa2.out
newtarget=newPA2.out
lib=ncurses
flag=_MAC_
endif

req=Controller.o View.o Robot.o Weapon.o WeaponBlade.o Main.o Arena.o
nreq=Controller.o View.o Weapon.o WeaponBlade.o Main.o
todoreq=testArena.o testArena2.o testRobot.o todo.o


all: demo $(newtarget)

demo: create_directory $(target)

create_directory: object todo

object:
	mkdir object 
		
todo:
	mkdir todo
		
echo:
	@echo $(GUESS_OS)

pa2.exe: *.cpp $(addprefix object/, $(req) )
	g++ -Wall -D$(flag) -o pa2.exe -l$(lib) -static -L".\\" -std=c++11 $(addprefix object/, $(req)) pdcurses.dll
	
pa2.out: *.cpp $(addprefix object/, $(req) )
	g++ -Wall -D$(flag) -o pa2.out -l$(lib) -std=c++11 $(addprefix object/, $(req))

newPA2.exe: *.cpp $(addprefix object/, $(nreq)) $(addprefix todo/, $(todoreq))
	g++ -Wall -D$(flag) -D_TESTING -o newPA2.exe -l$(lib) -static -L".\\" -std=c++11 $(addprefix object/, $(nreq)) ./todo/*.o pdcurses.dll

newPA2.out: *.cpp $(addprefix object/, $(nreq)) $(addprefix todo/, $(todoreq))
	g++ -Wall -D$(flag) -D_TESTING -o newPA2.out -l$(lib) -std=c++11 $(addprefix object/, $(nreq)) ./todo/*.o 

todo/testArena.o todo/testArena2.o: Arena.cpp newArena.cpp Arena.h TODO.h 
	g++ -Wall -D$(flag) -D_TESTING -c -std=c++11 -o ./todo/testArena.o Arena.cpp
	g++ -Wall -D$(flag) -D_TESTING -c -std=c++11 -o ./todo/testArena2.o newArena.cpp
	
todo/testRobot.o: Robot.cpp Robot.h Weapon.h
	g++ -Wall -D$(flag) -D_TESTING -c -std=c++11 -o ./todo/testRobot.o Robot.cpp

todo/todo.o: TODO.cpp TODO.h
	g++ -Wall -D$(flag) -D_TESTING -c -std=c++11 -o ./todo/todo.o TODO.cpp

object/Main.o: main.cpp Controller.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/Main.o main.cpp

object/Controller.o: Controller.cpp Controller.h View.h Arena.h Robot.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/Controller.o Controller.cpp
	
object/View.o: View.cpp View.h Robot.h Weapon.h definition.h Arena.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/View.o View.cpp
	
object/Robot.o: Robot.cpp Robot.h Weapon.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/Robot.o Robot.cpp 
	
object/Weapon.o: Weapon.cpp Weapon.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/Weapon.o Weapon.cpp

object/WeaponBlade.o: WeaponBlade.cpp WeaponBlade.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/WeaponBlade.o WeaponBlade.cpp

object/Arena.o: Arena.cpp Arena.h Robot.h
	g++ -Wall -D$(flag) -c -std=c++11 -o ./object/Arena.o Arena.cpp


clean:
	rm -f *.exe *.out object/*.o  todo/*.o
