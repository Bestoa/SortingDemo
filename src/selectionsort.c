#include "sort_base.h"

void selectionsort_demo(int *array, size_t len) {
    int i, j, min;
    for (i = 0; i < len; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (array[j] < array[min])
                min = j;
        }
        swap(&array[i], &array[min]);
    }
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = selectionsort_demo;
}
