CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = main
OBJS = main.o murmurhash.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c murmurhash.h
	$(CC) $(CFLAGS) -c main.c

murmurhash.o: murmurhash.c murmurhash.h
	$(CC) $(CFLAGS) -c murmurhash.c

clean:
	rm -f $(OBJS) $(TARGET)
