#include <math.h>
#include "calculate_primes.h"

// Заполняет массив индикаторов простых чисел от 0 до n включительно,
// primes — массив размера не менее n + 1.
void calculate_primes(int primes[], int n) {
    for (int i = 0; i <= n; ++i) {
        primes[i] = 1; // предполагаем все числа простыми
    }

    primes[0] = 0; // 0 — не простое
    primes[1] = 0; // 1 — не простое

    int limit = (int)sqrt(n);

    for (int i = 2; i <= limit; ++i) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0; // составное
            }
        }
    }
}