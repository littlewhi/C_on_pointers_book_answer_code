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
	coding2.o\
	coding3.o\
	coding4.o\
	coding5.o\
	coding6.o\
	coding7.o\
	coding8.o\
	coding9.o\
	coding10.o\
	coding11.o\
	coding12.o\
	coding13.o\
	coding14.o\
	coding15.o\
	coding16.o\
	coding17.o
	$(CC) $(OPTION) -o test $^ $(BEHIND)
