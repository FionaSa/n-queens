CC = gcc

CFLAGS= -std=c99 -O3

CFLAGS_TEST= -std=c99 -O0 -g

CFLAGS_BONUS = --coverage

LDFLAGS = -lcmocka

.PHONY: all clean gnuplot rdtsc

all: check 

gnuplot: gnuplot.c queens.c
	$(CC) $(CFLAGS) $^ -o $@
	./gnuplot > plot.dat
	gnuplot plot.p


rdtsc: rdtsc.c queens.c
	$(CC) $(CFLAGS) $^ -o $@
	./rdtsc > rdtsc.md


rapport: test_queens check
	llvm-cov gcov -f -b $^


check: test_main test_queens
	./$^
	./test_queens

test_main: test_main.c main.c
	$(CC) $(CFLAGS_TEST) $< -o $@ $(LDFLAGS)

test_queens: test_queens.c queens.c
	$(CC) $(CFLAGS_TEST) $(CFLAGS_BONUS) $< -o $@ $(LDFLAGS)

queens: queens.c main.c
	$(CC) $(CFLAGS) $^ -o $@	


clean:
	rm -f *.o test_main test_queens rdtsc.md

