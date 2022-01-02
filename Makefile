CC = gcc
AR = ar
FLAGS = -Wall -g 
OBJECTS = main.o nodes.o algo.o edges.o

all: graph
graph: $(OBJECTS) 
	$(CC) $(FLAGS) -o graph $(OBJECTS)
main.o: main.c algo.h 
	$(CC) $(FLAGS) -c main.c
nodes.o: nodes.c nodes.h 
	$(CC) $(FLAGS) -c nodes.c
edges.o: edges.c edges.h
	$(CC) $(FLAGS) -c edges.c
algo.o: algo.c algo.h nodes.h edges.h
	$(CC) $(FLAGS) -c algo.c
.PHONY: all clean
clean:
	rm -f graph *.o