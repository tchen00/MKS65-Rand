all: main.o
	gcc main.o

main.o: main.c
	gcc -c -g main.c

run:
	./a.out

clean:
	rm -rf *.o a.out
