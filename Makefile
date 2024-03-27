CC = g++
CFLAGS = -Wall -Wextra -O2 -std=c++20 -w

all: run

run: testgen sortBenchmark
	./testgen
	./sortBenchmark

testgen: testgen.cpp
	$(CC) $(CFLAGS) -o testgen testgen.cpp

sortBenchmark: sortBenchmark.cpp
	$(CC) $(CFLAGS) -o sortBenchmark sortBenchmark.cpp
	./sortBenchmark
	rm sortBenchmark

clean:
	rm -f testgen sortBenchmark