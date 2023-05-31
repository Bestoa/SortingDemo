#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "sort_base.h"

#define WARM_UP_NUM (1000)
#define DEFAULT_EVEN_NUM (20000)
#define DEFAULT_ODD_NUM (20001)
#define MAX (INT_MAX)
#define ROUND_MAX (10)

void validated(int array[], size_t size) {
    int i;
    for (i = 0; i < size - 2; i++) {
        if (array[i] > array[i + 1]) {
            printf("\nValiedated failed\n");
            return;
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_benchmark(size_t num)
{
    int *array;
    int i, round = 0;
    PfnSortFunc sort_func;
    clock_t t1, t2;
    double total = 0;
    array = (int *)malloc(num * sizeof(int));
    if (!array)
    {
        printf("OOM\n");
        return;
    }
    init_sort_func(&sort_func);
    while (round++ < ROUND_MAX)
    {
        double current = 0;
        srand(time(NULL));
        for (i = 0; i < num; i++) {
            array[i] = rand() % MAX;
        }
        t1 = clock();
        sort_func(array, num);
        t2 = clock();
        validated(array, num);
        current = (double)(t2 -t1)/CLOCKS_PER_SEC;
        printf("Round %d: %lfs ", round, current);
        total += current;
    }
    printf("\nAvg: %lfs\n", total / ROUND_MAX);
}

int main(int argc, char **argv) {
    int even_num = 0;
    int odd_num = 0;

    if (argc > 1)
    {
        even_num = atoi(argv[1]) * WARM_UP_NUM;
        odd_num = even_num + 1;
    }
    if (even_num <= 0)
        even_num = DEFAULT_EVEN_NUM;
    if (odd_num <= 0)
        odd_num = DEFAULT_ODD_NUM;

    printf("Warming up...\n");
    sort_benchmark(WARM_UP_NUM);
    printf("Test start, even = %d, odd = %d\n", even_num, odd_num);
    sort_benchmark(even_num);
    sort_benchmark(odd_num);
    printf("Test end.\n");
    return 0;
}
