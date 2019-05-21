
CFLAGS = -O1

.PHONY: all clean

all: horizontal vertical

horizontal: cache_test.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

vertical: cache_test.c
	$(CC) $(CFLAGS) -DSCAN_VERTICAL=1 -o $@ $^ $(LDFLAGS)

clean:
	rm -f horizontal vertical
