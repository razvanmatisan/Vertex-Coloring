CC = g++
CFLAGS  = -Wall -Wextra -g
OBJ_FILES = algo.o algo_test.o
TARGET = algo

build: $(TARGET)

all: run_tests

algo.o:	algo.h algo.cpp
	$(CC) $(CFLAGS) -c -Iheaders algo.cpp

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)
  
run_tests: build
	./algo

clean:
	rm -f $(OBJ_FILES) $(TARGET) *~
