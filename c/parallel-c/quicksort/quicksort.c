#include "quicksort.h"

void QuickSort_Serial(int *array, int n) { quicksort_serial(array, 0, n - 1); }

void QuickSort_Parallel(int *array, int n, int depth) {
    quicksort_parallel(array, 0, n - 1, depth);
}

void quicksort_serial(int *array, int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partion(array, left, right);
        quicksort_serial(array, left, pivot - 1);
        quicksort_serial(array, pivot + 1, right);
    }
}

void quicksort_parallel(int *array, int left, int right, int depth) {
    int pivot;
    if (left < right) {
        pivot = partion(array, left, right);
        if (depth-- > 0) {
            qsort_t temp = {array, left, pivot - 1, depth};
            pthread_t thread;
            int ret = pthread_create(&thread, NULL, quicksort_thread, &temp);
            assert((ret == 0) && "Thread creation failed");
            quicksort_parallel(array, pivot + 1, right, depth);
            pthread_join(thread, NULL);
        } else {
            quicksort_serial(array, left, pivot - 1);
            quicksort_serial(array, pivot + 1, right);
        }
    }
}

void *quicksort_thread(void *arg) {
    qsort_t *start = arg;
    quicksort_parallel(start->array, start->left, start->right, start->depth);
    return NULL;
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
