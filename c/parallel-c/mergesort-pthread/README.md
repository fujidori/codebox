# mergesort
-------------
mergesort with pthread, and compare single-thread and multi-thread
```sh
$ sh run.sh
rm -f *.o *~ *.bak core gmon.out mergesort
gcc -g -Wall -O0 -c main.c
gcc -g -Wall -O0 -c mergesort.c
gcc main.o mergesort.o -g -Wall -O0 -lm -pthread -o mergesort 
./mergesort
Serial: 1434.304 ms
Parallel: 534.395 ms
Check: OK 
```
