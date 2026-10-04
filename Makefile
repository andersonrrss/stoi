CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
TARGET = out/main
TEST_TARGET = out/run_tests

LIB_SRCS = $(wildcard src/*.c)
LIB_OBJS = $(LIB_SRCS:.c=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET) : main.o $(LIB_OBJS)
	mkdir -p $(@D)
	$(CC) $^ -o $@

$(TEST_TARGET) : tests/tests.o $(LIB_OBJS)
	mkdir -p $(@D)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf *.o tests/*.o out/ $(LIB_OBJS) $(TARGET) $(TEST_TARGET)

.PHONY: all test clean