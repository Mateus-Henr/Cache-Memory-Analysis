cmake_minimum_required(VERSION 3.22)
project(TP3_OC1 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP3_OC1 src/main.c src/sorting/bubblesort.c src/sorting/bubblesort.h src/sorting/quicksort.c src/sorting/quicksort.h src/sorting/radixsort.c src/sorting/radixsort.h src/factorial/factorial.c src/factorial/factorial.h src/sorting/selectionsort.c src/sorting/selectionsort.h)
