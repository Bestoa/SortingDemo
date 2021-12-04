#include "sort_base.h"

void insertionsort_demo(int *array, size_t len) {
    int i, j, k;
    int key;
    for(i = 1; i < len; i++) {
        key = array[i];
        for (j = 0; j < i && array[j] < key; j++);
        for (k = i; k > j; k--) {
            array[k] = array[k - 1];
        }
        array[j] = key;
    }
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = insertionsort_demo;
}
