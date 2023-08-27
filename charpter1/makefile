CC := gcc
OPTION := -Werror
BEHIND := 

test: main.o coding1.o	\
	coding2.o \
	coding3.o \
	coding4.o 
	$(CC) $(OPTION) -o test $^ $(BEHIND)

%.o: %.c
	$(CC) $(OPTION) -c -o $@ $^

clean:
	rm *.o test