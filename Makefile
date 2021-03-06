#Player.o: Player.cpp Player.h
#	g++ -Wall -c Player.cpp

#Person.o: Player.cpp Player.h Person.h Person.cpp
#	g++ -Wall -c Person.cpp

#Computer.o: Player.cpp Player.h Computer.h Computer.cpp
#	g++ -Wall -c Computer.cpp

#not really sure how makefiles work


# default target is all
all: driver

# driver is made by linking object files together
driver: Game.o Player.o Room.o Person.o Computer.o driver.o
	g++ Game.o Player.o Room.o Person.o Computer.o driver.o -o driver

# the Game.o object file needs recompiled if Game.cpp or Game.h changes
Game.o: Game.cpp Game.h
	g++ -c Game.cpp -o Game.o

# the Room.o object file needs recompiled if Room.cpp or Room.h changes
Room.o: Room.cpp Room.h
	g++ -c Room.cpp -o Room.o

# the Player.o object file needs recompiled if Player.cpp or Player.h changes
Player.o: Player.cpp Player.h
	g++ -c Player.cpp -o Player.o

# the Person.o object file needs recompiled if Person.cpp or Person.h changes
Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o

# the Computer.o object file needs recompiled if Computer.cpp or Computer.h changes
Computer.o: Computer.cpp Computer.h
	g++ -c Computer.cpp -o Computer.o

# the driver.o object file needs recompiled if driver.cpp or Person.h changes
driver.o: driver.cpp Game.o Player.o Room.o Person.o Computer.o
	g++ -c driver.cpp -o driver.o

# clean removes all object files and the compiled executable
clean:
	rm -f *.o driver
