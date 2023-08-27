CC := gcc
OPTION := -Werror
BEHIND := -lm

test: main.o coding1.o	\
	coding2.o \
	coding3.o \
	coding4.o \
	coding5.o
	$(CC) $(OPTION) -o test $^ $(BEHIND)

%.o: %.c
	$(CC) $(OPTION) -c -o $@ $^

clean:
	rm *.o test