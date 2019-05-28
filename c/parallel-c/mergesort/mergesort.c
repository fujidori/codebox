#include "mergesort.h"

void MergeSort_Serial(int *array, int n) { mergesort_serial(array, 0, n - 1); }

void MergeSort_Parallel(int *array, int n, int depth) {
    mergesort_parallel(array, 0, n - 1, depth);
}

void mergesort_serial(int *array, int left, int right) {
    int mid = (left + right) / 2;

    if (left >= right) return;

    mergesort_serial(array, left, mid);
    mergesort_serial(array, mid + 1, right);

    merge(array, left, right);
}

void mergesort_parallel(int *array, int left, int right, int depth) {
    int mid = (left + right) / 2;
    if (left >= right) return;

    if (depth-- > 0) {
        msort_t temp = {array, left, mid, depth};
        pthread_t thread;
        int ret = pthread_create(&thread, NULL, mergesort_thread, &temp);
        assert((ret == 0) && "Thread creation failed");
        mergesort_parallel(array, mid + 1, right, depth);
        pthread_join(thread, NULL);
    } else {
        mergesort_serial(array, left, mid);
        mergesort_serial(array, mid + 1, right);
    }

    merge(array, left, right);
}

void *mergesort_thread(void *arg) {
    msort_t *start = arg;
    mergesort_parallel(start->array, start->left, start->right, start->depth);
    return NULL;
}

void merge(int *array, int left, int right) {
    int mid = (left + right) / 2;
    int leftp = left;
    int rightp = mid + 1;

    int *temp;
    temp = (int *)malloc(sizeof(int) * (right - left + 1));

    int tempi = 0;

    while (leftp <= mid && rightp <= right) {
        if (array[leftp] > array[rightp]) {
            temp[tempi++] = array[rightp++];
        } else {
            temp[tempi++] = array[leftp++];
        }
    }

    while (leftp <= mid) {
        temp[tempi++] = array[leftp++];
    }

    while (rightp <= right) {
        temp[tempi++] = array[rightp++];
    }

    for (leftp = 0; leftp < (right - left + 1); leftp++) {
        array[left + leftp] = temp[leftp];
    }
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
