CC := gcc
OPTION := -Werror

test: main.o coding1.o	\
	coding2.o \
	coding3.o \
	coding4.o \
	coding5.o \
	coding6.o 
	$(CC) $(OPTION) -o test $^

%.o: %.c
	$(CC) $(OPTION) -c -o $@ $^

clean:
	rm *.o test