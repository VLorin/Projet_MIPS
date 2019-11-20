all: main.o translate.o 
	gcc -o -g main main.o translate.o

main.o: main.c
	gcc -g -c main.c -Wall -o main.o
	
translate.o: translate.c translate.h
	gcc -g -c translate.c -Wall -o translate.o
	
memory.o: memory.c memory.h
	gcc -g -c memory.c -Wall -o memory.o
	
clean:
	rm -Rf *.o

unistall:
	rm -Rf main
	rm -Rf *.o