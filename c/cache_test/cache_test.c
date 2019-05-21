#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_WIDTH  (8192)
#define DEFAULT_HEIGHT (4096)

/* from: https://qiita.com/NaOHaq/items/55573f088d0b1d3b0dc6
 *
 * perf stat -d ./horizontal
 * perf stat -d ./vertical
 */

static double
get_current_time( void )
{
	double t;
	struct timeval tv;
	gettimeofday(&tv, NULL);

	t  = ((double)tv.tv_usec) * 1.0e-6;
	t += (double)tv.tv_sec;

	return t;
}

#ifdef SCAN_VERTICAL
static void
process_pixels(uint8_t * pixbuf, int32_t w, int32_t h)
{
	for (int32_t x=0; x<w; x+=1) {
		for (int32_t y=0; y<h; y+=1) {
			pixbuf[y*w + x] += 1;
		}
	}
}

#else
static void
process_pixels(uint8_t * pixbuf, int32_t w, int32_t h)
{
	for (int32_t y=0; y<h; y+=1) {
		for (int32_t x=0; x<w; x+=1) {
			pixbuf[y*w + x] += 1;
		}
	}
}

#endif

int
main(int argc, char * argv[])
{
	uint8_t * pixbuf;
	int32_t w = DEFAULT_WIDTH;
	int32_t h = DEFAULT_HEIGHT;
	double t0;
	double t1;

	if (argc > 1) {
		w = strtol(argv[1], NULL, 10);
	}

	if (argc > 2) {
		h = strtol(argv[2], NULL, 10);
	}

	pixbuf = malloc(w * h);
	if (pixbuf == NULL) {
		fprintf(stderr, "Not enough memory...\n");
		exit(1);
	}

	memset(pixbuf, 0, w * h);

	t0 = get_current_time( );

	for (int32_t k=0; k<128; k+=1) {
		process_pixels(pixbuf, w, h);
		fputc('.', stdout);
		fflush(stdout);
	}
	fputc('\n', stdout);

	t1 = get_current_time( );

	printf("Elapsed time: %.3f\n", t1 - t0);

	return 0;
}
