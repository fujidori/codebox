#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void QuickSort_Serial(int *array, int n);
void QuickSort_Parallel(int *array, int n);
void quicksort_serial(int *array, int left, int right);
void quicksort_parallel(int *array, int left, int right);
int partion(int *array, int left, int right);

// Display n pieces of data
void ShowData(int *array, int n);

// Shuffle n pieces of data
void Shuffle(int *array, int n);

void swap(int *a, int *b);

#endif
