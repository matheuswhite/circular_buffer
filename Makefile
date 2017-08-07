MAIN=main.c
OBJECTS=circular_buffer.o
TARGET=main
DEFINES=-DDEBUG

all:$(OBJECTS)
	$(CC) $(MAIN) $^ -o $(TARGET) $(DEFINES)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
