TARGET := exp_test
CC := g++ -std=c++17
CFLAGS := -g -Wall

$(TARGET): main.o parser.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o parser.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

parser.o: parser.cpp parser.h
	$(CC) $(CFLAGS) -c parser.cpp

.PHONY: clean
clean: 
	rm -f $(TARGET) *.o
