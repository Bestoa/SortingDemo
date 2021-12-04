#ifndef __SORT_BASE__
#define __SORT_BASE__
#include <stddef.h>
typedef void (*PfnSortFunc)(int *, size_t);
extern void swap(int *a, int *b);
extern void init_sort_func(PfnSortFunc *);
#endif
