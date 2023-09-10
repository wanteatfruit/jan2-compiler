bminor: main.o encoder.c scanner.o
	gcc -o bminor main.o encoder.c scanner.o

main.o: main.c token.h
	gcc -c main.c -c -o main.o

scanner.o: scanner.c token.h
	gcc -c scanner.c -c -o scanner.o

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex


clean:
	rm -f bminor
	rm -f ./test/*/*.out

test: bminor
	./runtest.sh