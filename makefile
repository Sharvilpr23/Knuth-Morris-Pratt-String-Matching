all: main tests
main: main.cpp
	g++ -o main main.cpp
tests: tests.cpp
	g++ -o tests tests.cpp
clean: 
	rm -rf *.o *.d core main tests

