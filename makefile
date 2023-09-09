bminor: main.c encoder.c
	make clean
	gcc -o bminor main.c encoder.c

clean:
	rm -f bminor
	rm -f ./test/*/*.out

test: bminor
	./runtest.sh