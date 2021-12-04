#include "sort_base.h"

void shellsort_demo(int *array, size_t len) {
    int i, j, gap;
    int key;
    for(gap = len >> 1; gap > 0; gap >>= 1) {
        for(i = gap; i < len; i++) {
            key = array[i];
            for (j = i - gap; j >= 0 && array[j] > key; j -= gap)
                array[j + gap] = array[j];
            array[j + gap] = key;
        }
    }
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = shellsort_demo;
}
