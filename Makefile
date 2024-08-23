# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS= -Wall

all: main.o solve.o util.o tester.o
	g++ main.o solve.o util.o tester.o -o mipt

main.o: CPP/main.cpp
	$(CC) $(CFLAGS) -c CPP/main.cpp

solve.o: CPP/solve.cpp
	$(CC) $(CFLAGS) -c CPP/solve.cpp

util.o: CPP/util.cpp
	$(CC) $(CFLAGS) -c CPP/util.cpp

tester.o: CPP/tester.cpp
	$(CC) $(CFLAGS) -c CPP/tester.cpp
clean:
	rm -rf *.o mipt
