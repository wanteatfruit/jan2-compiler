bminor: main.o encoder.o scanner.o parser.o
	gcc -o bminor main.o encoder.o scanner.o parser.o

encoder.o: encoder.c
	gcc -c encoder.c -c -o encoder.o

main.o: main.c token.h
	gcc -c main.c -c -o main.o

scanner.o: scanner.c token.h
	gcc -c scanner.c -c -o scanner.o

parser.o: parser.c token.h
	gcc -c parser.c -c -o parser.o

parser.c: parser.bison
	bison --defines=token.h --output=parser.c parser.bison -v

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex


clean:
	rm -f bminor
	rm -f ./test/*/*.out

test: bminor
	./runtest.sh