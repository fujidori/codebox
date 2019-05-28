CC		      = gcc
CFLAGS        = -fopenmp -g -Wall -O0
LIBS          = -lm
OBJS	      = main.o quicksort.o
PROGRAM	      = quicksort

.PHONY: all
all:		$(PROGRAM)

$(PROGRAM):     $(OBJS)
		$(CC) $(CFLAGS) $(LIBS) -o $(PROGRAM) $(OBJS)  

.SUFFIXES: .c .o
.c.o:
		$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ *.bak core gmon.out $(PROGRAM)

run:	$(PROGRAM)
		./$(PROGRAM)

