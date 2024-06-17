CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=../data_libs/*.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
TARGET=../../build/
EXECUTABLE=Quest_3



all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)
	
clean:
	rm -rf $(TARGET)*

rebuild: clean all