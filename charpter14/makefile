CC := gcc
OPTION := -Werror
BEHIND := 

all: test

%.o: %.c
	$(CC) $(OPTION) -c -o $@ $^

clean:
	rm *.o test

test: main.o \
	coding1.o\
	coding2.o
	$(CC) $(OPTION) -o test $^ $(BEHIND)
