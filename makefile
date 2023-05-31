CC=gcc
RM=rm
CFLAGS=-Wall -O3
all: ./bin/mergesort ./bin/cocktailsort ./bin/stoogesort ./bin/bubblesort ./bin/selectionsort ./bin/shellsort ./bin/qsort ./bin/insertionsort 
./bin/__GEN__COMMON_OBJ.o: ./src/sort_base.c 
	$(CC) $^ $(CFLAGS) -o $@ -c
./bin/mergesort: ./bin/__GEN__COMMON_OBJ.o ./src/mergesort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/cocktailsort: ./bin/__GEN__COMMON_OBJ.o ./src/cocktailsort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/stoogesort: ./bin/__GEN__COMMON_OBJ.o ./src/stoogesort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/bubblesort: ./bin/__GEN__COMMON_OBJ.o ./src/bubblesort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/selectionsort: ./bin/__GEN__COMMON_OBJ.o ./src/selectionsort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/shellsort: ./bin/__GEN__COMMON_OBJ.o ./src/shellsort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/qsort: ./bin/__GEN__COMMON_OBJ.o ./src/qsort.c
	$(CC) $^ $(CFLAGS) -o $@
./bin/insertionsort: ./bin/__GEN__COMMON_OBJ.o ./src/insertionsort.c
	$(CC) $^ $(CFLAGS) -o $@
clean:
	$(RM) -rvf ./bin/*.o ./bin/mergesort ./bin/cocktailsort ./bin/stoogesort ./bin/bubblesort ./bin/selectionsort ./bin/shellsort ./bin/qsort ./bin/insertionsort 