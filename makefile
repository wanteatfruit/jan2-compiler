bminor: main.o encoder.o scanner.o parser.o stmt.o decl.o expr.o type.o param_list.o
	gcc main.o encoder.o scanner.o parser.o -o bminor -lm

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

stmt.o: stmt.c
	gcc -c stmt.c -c -o stmt.o

expr.o: expr.c
	gcc -c expr.c -c -o expr.o

type.o: type.c
	gcc -c type.c -c -o type.o

param_list.o: param_list.c
	gcc -c param_list.c -c -o param_list.o


clean:
	rm -f bminor
	rm -f ./test/*/*.out

test: bminor
	./runtest.sh