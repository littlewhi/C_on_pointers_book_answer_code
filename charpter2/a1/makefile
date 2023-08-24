test: main.o increment.o negate.o
	gcc -o test $^

%.o: %.c
	gcc -c -o $@ $^

clean:
	rm *.o test