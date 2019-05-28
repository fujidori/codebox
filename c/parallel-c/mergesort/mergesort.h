#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void MergeSort_Serial(int *array, int n);
void MergeSort_Parallel(int *array, int n, int depth);
void mergesort_serial(int *array, int left, int right);
void mergesort_parallel(int *array, int left, int right, int depth);
void *mergesort_thread(void *arg);
void merge(int *a, int i, int j);

// Display n pieces of data
void ShowData(int *array, int n);

// Shuffle n pieces of data
void Shuffle(int *array, int n);

void swap(int *a, int *b);

typedef struct {
    int *array;
    int left;
    int right;
    int depth;
} msort_t;

#endif
