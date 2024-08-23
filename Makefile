# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: main.o solve.o util.o tester.o
	g++ main.o factorial.o hello.o -o mipt

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp

util.o: util.cpp
	$(CC) $(CFLAGS) util.cpp

tester.o: tester.cpp
	$(CC) $(CFLAGS) tester.cpp
clean:
	rm -rf *.o mipt
