CC := gcc
OPTION := -Werror
BEHIND := 

all: test

%.o: %.c
	$(CC) $(OPTION) -c -o $@ $^

clean:
	rm *.o test

test: main.o linklist.o\
	coding1.o\
	coding2.o\
	coding3.o\
	coding4.o\
	coding5.o\
	coding6.o\
	coding7.o
	$(CC) $(OPTION) -o test $^ $(BEHIND)
