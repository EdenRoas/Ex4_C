CC=gcc
FLAGS= -Wall -g

#make all
all: graph

.PHONY: clean
#make clean
clean:
	rm -f *.o *.a *.so graph

graph: main.o
	$(CC) $(FLAGS) -o graph main.c

main.o: main.c algo.o edges.o graph.o
	$(CC) $(FLAGS) -c main.c

algo.o: algo.h algo.c
	$(CC) $(FLAGS) -c algo.c

Edge.o: Edge.h edges.c
	$(CC) $(FLAGS) -c edges.c

graph.o: graph.h graph.c edges.h
	$(CC) $(FLAGS) -c graph.c

