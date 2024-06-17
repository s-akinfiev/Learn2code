CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LIBS=../data_libs/
SOURCES=../data_libs/*.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
SRC_STATIC=../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
TARGET=../../build/
EXECUTABLE=Quest_3
EXECUTABLE_STATIC=Quest_5




all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)
	
clean:
	rm -rf $(TARGET)* $(LIBS)*.a *.o

rebuild: clean all

data_stat.a:
	$(CC) $(CFLAGS) -c $(LIBS)data_stat.c 
	ar r $(LIBS)libdata_stat.a *.o
	rm -rf *.o

build_with_static: data_stat.a
	$(CC) $(CFLAGS) -c $(SRC_STATIC)
	$(CC) $(CFLAGS) -o $(TARGET)$(EXECUTABLE_STATIC) *.o -L$(LIBS) -ldata_stat