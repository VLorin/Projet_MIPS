all: main.o translate.o 
	gcc -o main main.o translate.o 

main.o: main.c
	gcc -c main.c -Wall -o main.o
	
translate.o: translate.c translate.h
	gcc -c translate.c -Wall -o translate.o
	
memory.o: memory.c memory.h
	gcc -c memory.c -Wall -o memory.o
	
clean:
	rm -Rf *.o

unistall:
	rm -Rf main
	rm -Rf *.o
