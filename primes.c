#include <stdio.h>
#include <stdlib.h>

#include "calculate_primes.h" // Подключаем заголовочный файл и получаем доступ к функции из calculate_primes.c

int main() {
    int n; // До какого числа искать простые числа
    scanf("%d", &n);

    // int *primes                    - создаём переменную-указатель
    // malloc((m + 1) * sizeof(int))  - выделяем оперативную память под массив из m+1 элементов
    // (int*)                         - приводит результат функции malloc() к типу int
    int *primes = (int*)malloc((n + 1) * sizeof(int));

    calculate_primes(primes, n); // передаём указатель на массив и верхнюю границы, чтобы записать в primes таблицу простых чисел

    // Проходим по диапазону от 2 до N
    for (int i = 2; i <= n; ++i) {
        // Если число I простое то в массиве primes на его месте будет 1(True), иначе 0(False)
        if (primes[i]) {
            printf("%d\n", i);
        }
    }

    // Освобождаем primes из оперативной памяти
    free(primes);

    return 0;
}
