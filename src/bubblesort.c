#include "sort_base.h"

void bubble_demo(int *array, size_t len) {
    int i, j;
    for (i = len - 1; i > 0; i--) {
        for (j = 0; j < i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = bubble_demo;
}
