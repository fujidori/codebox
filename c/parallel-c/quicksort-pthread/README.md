# quicksort
-------------
quicksort with pthread, and compare single-thread and multi-thread
```sh
$ sh run.sh
rm -f *.o *~ *.bak core gmon.out quicksort
gcc -g -Wall -O0 -c main.c
gcc -g -Wall -O0 -c quicksort.c
gcc main.o quicksort.o -g -Wall -O0 -lm -pthread -o quicksort
./quicksort
Serial:2639.817 ms
Parallel:1714.032 ms
Check: OK 
```
