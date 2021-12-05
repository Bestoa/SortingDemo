#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_base.h"

#define EVEN_NUM (20000)
#define ODD_NUM (20001)
#define MAX (10000)
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

int main(){
    sort_benchmark(ODD_NUM);
    sort_benchmark(EVEN_NUM);
    sort_benchmark(ODD_NUM);
    return 0;
}
