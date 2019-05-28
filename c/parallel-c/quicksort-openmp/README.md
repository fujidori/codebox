# quicksort
-------------
quicksort with OpenMP, and compare single-thread and multi-thread
```sh
$ sh run.sh
rm -f *.o *~ *.bak core gmon.out quicksort
gcc -fopenmp -g -Wall -O0 -c main.c
gcc -fopenmp -g -Wall -O0 -c quicksort.c
gcc -fopenmp -g -Wall -O0 -lm -o quicksort main.o quicksort.o  
./quicksort
Serial:1338.185 ms
Parallel:505.378 ms
Check: OK 
```
