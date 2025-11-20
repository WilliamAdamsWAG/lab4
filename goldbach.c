#include <stdio.h>
#include <stdlib.h>

#include "calculate_primes.h"

int count_pairs(int n, int primes[]);
int min_x(int n, int primes[]);

int main() {
    int n;
    int m;

    scanf("%d", &n);
    scanf("%d", &m);

    int *primes = (int*)malloc((m + 1) * sizeof(int));

    calculate_primes(primes, m);

    if(n % 2 != 0) {
        n += 1;
    }

    if(m % 2 != 0) {
        m -= 1;
    }

    // Перебираем все числа в диапазоне [n, m]
    for(int i = n; i <= m; i+=2) {
        int c = count_pairs(i, primes); // Количество пар чисел, чья сумма ровняется исходному числу
        int x = min_x(i, primes);
        int y = i - x;

        printf("%d %d %d %d \n", i, c, x, y);
    }
}

int count_pairs(int n, int primes[]) {
    int count = 0;

    for(int i = 2; i <= n / 2; i++) {
        if(primes[i] == 1 && primes[n-i] == 1) {
            count += 1;
        }
    }

    return count;
}

int min_x(int n, int primes[]) {
    int count = 0;

    for(int i = 2; i <= n / 2; i++) {
        if(primes[i] == 1 && primes[n-i] == 1) {
            return i;
        }
    }
}