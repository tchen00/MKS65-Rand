all: main.o
	gcc -o program main.o

main.o:
	gcc -o main.c

run:
	./program

clean:
	rm *.o
	rm *~
