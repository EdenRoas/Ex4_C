CC=gcc



all: graph


graph: main.o
	$(CC) -Wall -g -o graph main.c

main.o: main.c algo.o edges.o graph.o
	$(CC) -Wall -g -c main.c

algo.o: algo.h algo.c
	$(CC) -Wall -g -c algo.c

edges.o: edges.h edges.c
	$(CC) -Wall -g -c edges.c

graph.o: graph.h graph.c edges.h
	$(CC) -Wall -g -c graph.c

.PHONY: clean

clean:
	rm -f *.o *.a *.so graph


	