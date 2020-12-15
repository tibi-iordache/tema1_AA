CC = g++
CFLAGS = -Wall -Wextra -O2

build: 
	$(CC) solovay.h frobenius.h solovay.cpp frobenius.cpp checker.cpp -o checker $(CFLAGS)
	$(CC) tests_generator.cpp -o  tests_generator $(FLAGS)

run_tests: build
	./tests_generator
	./checker

clean:
	rm -rf *.o