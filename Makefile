
calculate_primes.o: calculate_primes.c calculate_primes.h
	gcc -c -O0 calculate_primes.c

primes.o: primes.c
	gcc -c -O0 primes.c

goldbach.o: goldbach.c
	gcc -c -O0 goldbach.c

primes: primes.o calculate_primes.o
	gcc -o primes primes.o calculate_primes.o -lm

goldbach: goldbach.o calculate_primes.o
	gcc -o goldbach goldbach.o calculate_primes.o -lm

all: primes goldbach

clean:
	rm *.o goldbach primes