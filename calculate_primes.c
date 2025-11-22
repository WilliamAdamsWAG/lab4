/**
 * calculate_primes.c
 *
 * Copyright (c) 2025, Nikita Chesnokov <chesnoko@cs.petrsu.ru>
 *
 * This code is licensed under MIT license.
 */
#include <math.h>
#include "calculate_primes.h"

void calculate_primes(int primes[], int n) {
    for (int i = 0; i <= n; i++) {
        primes[i] = 1; // Заполняем массив единицами, из предположения что все числа простые
    }

    primes[0] = 0; // 0 — не простое
    primes[1] = 0; // 1 — не простое

    int limit = (int)sqrt(n); // верхняя граница рассматриваемого диапазона, дальше неё нет смысла рассматривать числа

    for (int i = 2; i <= limit; i++) {
        // Если число I простое то в массиве primes на его месте будет 1(True), иначе 0(False)
        if (primes[i]) {
            // Начиная с числа I в квадрате проходимся по диапазону значений, прибавляя на каждом шагу I,
            // то есть по принципу решета Эратосфена говорим что все степени числа I не простые числа
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0; // не простое
            }
        }
    }
}