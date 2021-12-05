#include "sort_base.h"

void __qsort(int *array, int start, int end) {
    int i = start, j = start;
    int flag = array[end - 1];
    if (start >= end)
        return;
    for (i = start; i < end; i++) {
        if (array[i] < flag) {
            swap(&array[i], &array[j]);
            j++;
        }
    }
    swap(&array[j], &array[end - 1]);
    __qsort(array, start, j);
    __qsort(array, j + 1, end);
}

void qsort_demo(int *array, size_t len)
{
    __qsort(array, 0, len);
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = qsort_demo;
}
