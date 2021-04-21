CC = g++
FLAGS = -c

TARGETS = oss user sharedmemory errors childhandler clock resourcehandler filehandler

all: $(TARGETS)

oss: oss.o
	$(CC) $(FLAGS) -o $@ oss.o

user: user.o
	$(CC) $(FLAGS) -o $@ user.o

sharedmemory.o: sharedmemory.cpp sharedmemory.h
	$(CC) $(FLAGS) sharedmemory.cpp

errors.o: errors.cpp errors.h
	$(CC) $(FLAGS) errors.cpp

childhandler.o: childhandler.cpp childhandler.h
	$(CC) $(FLAGS) childhandler.cpp

clock.o: clock.cpp clock.h
	$(CC) $(FLAGS) clock.cpp

resourcehandler.o: resourcehandler.cpp resourcehandler.h
	$(CC) $(FLAGS) resourcehandler.cpp

filehandler.o: filehandler.cpp filehandler.h
	$(CC) $(FLAGS) filehandler.cpp

clean:
	rm -rf *.o $(TARGETS)
	
