#include "quicksort.h"

#define DEPTH 2  // The total number of threads will be DEPTH^2

int main(int argc, char **argv) {
    int i;
    int iflag;
    struct timeval time_start, time_end;

    // data
    const int data_num = 10000000;
    int *array_serial = NULL;
    int *array_parallel = NULL;
    array_serial = (int *)malloc(sizeof(int) * data_num);
    array_parallel = (int *)malloc(sizeof(int) * data_num);
    for (i = 0; i < data_num; i++) {
        array_serial[i] = i;
        array_parallel[i] = i;
    }

    Shuffle(array_serial, data_num);
    Shuffle(array_parallel, data_num);

    // Show data before sorting
    // printf("Before   serial: ");
    // ShowData(array_serial, data_num);
    // printf("Before parallel: ");
    // ShowData(array_parallel, data_num);

    // Serial
    gettimeofday(&time_start, NULL);
    QuickSort_Serial(array_serial, data_num);
    gettimeofday(&time_end, NULL);

    // Display execution time in serial
    printf("%s", "Serial:");
    printf("%.3lf ms\n", ((time_end.tv_sec - time_start.tv_sec) +
                          (time_end.tv_usec - time_start.tv_usec) * 1.0E-6) *
                             1000);

    // Parallel
    gettimeofday(&time_start, NULL);
    QuickSort_Parallel(array_parallel, data_num, DEPTH);
    gettimeofday(&time_end, NULL);

    // Display execution time in parallel
    printf("%s", "Parallel:");
    printf("%.3lf ms\n", ((time_end.tv_sec - time_start.tv_sec) +
                          (time_end.tv_usec - time_start.tv_usec) * 1.0E-6) *
                             1000);

    // Show data after sorting
    // printf("After   serial: ");
    // ShowData(array_serial, data_num);
    // printf("After parallel: ");
    // ShowData(array_parallel, data_num);

    // check serial, parallel for the same
    iflag = 0;
    for (i = 0; i < data_num; i++) {
        if (array_serial[i] != array_parallel[i]) {
            printf(" Error!\n");
            iflag = 1;
            break;
        }
    }

    if (iflag == 0) {
        printf("Check: OK \n");
    } else {
        printf("Check: NG! \n");
    }

    free(array_serial);
    free(array_parallel);

    return 0;
}
