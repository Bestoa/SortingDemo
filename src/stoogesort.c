#include "sort_base.h"

void __stoogesort_demo(int *array, int start, int end) {
    if (array[start] > array[end - 1]) {
        swap(&array[start], &array[end - 1]);
    }
    if (end - start > 2) {
        int t = (end - start) / 3;
        __stoogesort_demo(array, start, end - t);
        __stoogesort_demo(array, start + t, end);
        __stoogesort_demo(array, start, end - t);
    }
}

void stoogesort_demo(int *array, size_t len)
{
    __stoogesort_demo(array, 0, len);
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = stoogesort_demo;
}
