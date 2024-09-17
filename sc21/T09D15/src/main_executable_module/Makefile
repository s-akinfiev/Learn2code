CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LIBS=../data_libs/
SOURCES=../data_libs/*.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
SOURCE_DYNAMIC=../data_libs/*.c ../yet_another_decision_module/decision.c *.c
PROC=../data_module/
SRC_STATIC=../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c *.c
TARGET=../../build/
EXECUTABLE=Quest_3
EXECUTABLE_STATIC=Quest_5




all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)
	
clean:
	rm -rf $(TARGET)* $(LIBS)*.a *.o $(PROC)*.so *.o

rebuild: clean all

data_stat.a:
	$(CC) $(CFLAGS) -c $(LIBS)data_stat.c 
	ar r $(LIBS)libdata_stat.a *.o
	rm -rf *.o

build_with_static: data_stat.a
	$(CC) $(CFLAGS) -c $(SRC_STATIC)
	$(CC) $(CFLAGS) -o $(TARGET)$(EXECUTABLE_STATIC) *.o -L$(LIBS) -ldata_stat

data_process.so:
	$(CC) $(CFLAGS) -c -fPIC $(PROC)data_process.c $(LIBS)data_stat.c
	$(CC) $(CFLAGS) -shared -o $(PROC)libdata_process.so *.o
	rm -rf *.o

build_with_dynamic: data_process.so
	$(CC) $(CFLAGS) -c $(SOURCE_DYNAMIC)
	$(CC) $(CFLAGS) -o $(TARGET)Quest_6 *.o -L$(PROC) -ldata_process
	rm -rf *.o

clang:
	cp ../../materials/linters/.clang-format ../../src/
	cd .. && clang-format -i */*.c */*.h --verbose