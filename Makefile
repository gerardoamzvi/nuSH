CC = gcc
CFLAGS = -Wall -Wextra
TARGET = nush

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET) -lm

clean:
	rm -f $(TARGET).exe