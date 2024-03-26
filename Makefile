CC = g++
CFLAGS = -Wall -Wextra -O2 -std=c++20

all: testgen sortBenchmark

run: testgen sortBenchmark
	./testgen
	./sortBenchmark

testgen: testgen.cpp
	$(CC) $(CFLAGS) -o testgen testgen.cpp

sortBenchmark: sortBenchmark.cpp
	$(CC) $(CFLAGS) -o sortBenchmark sortBenchmark.cpp
	./sortBenchmark

clean:
	rm -f testgen sortBenchmark