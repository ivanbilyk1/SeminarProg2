CC = gcc

CFLAGS = -Wall -Wextra -std=c11

TARGET = main

all: $(TARGET)

$(TARGET): main.o KCM.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o KCM.o

main.o: main.c KCM.h
	$(CC) $(CFLAGS) -c main.c

KCM.o: KCM.c KCM.h
	$(CC) $(CFLAGS) -c KCM.c

clean:
	rm -f *.o $(TARGET)
