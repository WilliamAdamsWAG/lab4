#include <stdio.h>
#include <stdlib.h>

#include "calculate_primes.h"

int main() {
    int n;
    scanf("%d", &n);

    int *primes = (int*)malloc((n + 1) * sizeof(int));

    calculate_primes(primes, n);

    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            printf("%d\n", i);
        }
    }

    free(primes);
    return 0;
}
