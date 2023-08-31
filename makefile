bminor: main.c encoder.c
	make clean
	gcc -o bminor main.c encoder.c

clean:
	rm -f bminor

test: bminor
	./runtest.sh