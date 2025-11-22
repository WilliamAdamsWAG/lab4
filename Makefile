CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

.PHONY: all clean

%.o: %.c
	$(CC) $(CFLAGS) -c $<

primes: primes.o calculate_primes.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

goldbach: goldbach.o calculate_primes.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

all: primes goldbach

clean:
	rm *.o goldbach primes