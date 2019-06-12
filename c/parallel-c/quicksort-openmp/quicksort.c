#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "quicksort.h"

void QuickSort_Serial(int *array, int n) { quicksort_serial(array, 0, n - 1); }

void QuickSort_Parallel(int *array, int n) {
#pragma omp parallel
    {
#pragma omp single nowait
        quicksort_parallel(array, 0, n - 1);
    }
}

void quicksort_serial(int *array, int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partion(array, left, right);
        quicksort_serial(array, left, pivot - 1);
        quicksort_serial(array, pivot + 1, right);
    }
}

void quicksort_parallel(int *array, int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partion(array, left, right);
#pragma omp task
        { quicksort_parallel(array, left, pivot - 1); }
#pragma omp task
        { quicksort_parallel(array, pivot + 1, right); }
    }
}

int partion(int *array, int left, int right) {
    int x, i, j;
    x = array[right];
    i = left - 1;
    for (j = left; j < right; j++) {
        if (array[j] <= x) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return i + 1;
}

// Display n pieces of data
void ShowData(int *array, int n) {
    while (n--) printf("%d  ", *array++);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

// Shuffle n pieces of data
void Shuffle(int *array, int n) {
    int i, j;

    srand(1);
    for (i = 0; i < n; i++) {
        j = rand() % n;
        swap(&array[i], &array[j]);
    }
}
