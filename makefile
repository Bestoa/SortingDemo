CC=gcc
RM=rm
CFLAGS=-Wall
all: ./src/bubblesort ./src/stoogesort ./src/qsort ./src/insertionsort ./src/shellsort ./src/cocktailsort ./src/selectionsort 
__GEN__COMMON_OBJ.o: ./src/sort_base.c 
	$(CC) $^ $(CFLAGS) -o $@ -c
./src/bubblesort: __GEN__COMMON_OBJ.o ./src/bubblesort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/stoogesort: __GEN__COMMON_OBJ.o ./src/stoogesort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/qsort: __GEN__COMMON_OBJ.o ./src/qsort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/insertionsort: __GEN__COMMON_OBJ.o ./src/insertionsort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/shellsort: __GEN__COMMON_OBJ.o ./src/shellsort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/cocktailsort: __GEN__COMMON_OBJ.o ./src/cocktailsort.c
	$(CC) $^ $(CFLAGS) -o $@
./src/selectionsort: __GEN__COMMON_OBJ.o ./src/selectionsort.c
	$(CC) $^ $(CFLAGS) -o $@
clean:
	$(RM) -rvf *.o ./src/bubblesort ./src/stoogesort ./src/qsort ./src/insertionsort ./src/shellsort ./src/cocktailsort ./src/selectionsort 