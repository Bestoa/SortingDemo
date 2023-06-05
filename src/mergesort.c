#include <stdlib.h>
#include "sort_base.h"

void __merge(int *array, int s1, size_t len1, int s2, size_t len2, int *tmp)
{
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2)
    {
        if (array[s1 + i] < array[s2 + j])
            tmp[k++] = array[s1 + i++];
        else
            tmp[k++] = array[s2 + j++];
    }
    while(i < len1)
        tmp[k++] = array[s1 + i++];
    while(j < len2)
        tmp[k++] = array[s2 + j++];
    for (i = 0; i < k; i++)
       array[s1 + i] = tmp[i]; 
}

void __sort(int *array, int start, size_t len, int *tmp)
{
    if (len > 1)
    {
        int s1 = start, s2 = start + len / 2;
        size_t len1 = s2 - s1, len2 = len - len1;
        __sort(array, s1, len1, tmp);
        __sort(array, s2, len2, tmp);
        __merge(array, s1, len1, s2, len2, tmp);
    }
}

void mergesort_demo(int *array, size_t len)
{
    int *tmp = (int *)malloc(sizeof(int) * len);
    __sort(array, 0, len, tmp);
    free(tmp);
}

void init_sort_func(PfnSortFunc *sort_func) {
    *sort_func = mergesort_demo;
}
