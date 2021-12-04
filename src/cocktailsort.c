#include "sort_base.h"

void cocktailsort_demo(int *array, size_t len) {
    int i, swaped = 1;
    int left = 0, right = len - 1;
    while(swaped) {
        swaped = 0;
        for (i = left; i < right - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                swaped = 1;
            }
        }
        for (i = right - 1; i > left; i--) {
            if (array[i] < array[i - 1]) {
                swap(&array[i], &array[i - 1]);
                swaped = 1;
            }
        }
        right--;
        left++;
    }
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = cocktailsort_demo;
}
