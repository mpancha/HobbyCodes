CC=gcc
all: dfs.o

dfs.o: dfs.c
	$(CC) dfs.c -o dfs.o
clean:
	rm -rf *.o
