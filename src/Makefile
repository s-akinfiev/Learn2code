CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=list.c list_test.c
TARGET=../build/
EXECUTABLE=Quest_1
ALLC=-DSTRLEN -DSTRCMP -DSTRCPY -DSTRCAT


all: door_struct list_test stack_test

door_struct:
	$(CC) $(CFLAGS) dmanager_module.c -o $(TARGET)Quest_1

list_test:
	$(CC) $(CFLAGS) list.c list_test.c -o $(TARGET)Quest_2

stack_test:
	$(CC) $(CFLAGS) stack.c stack_test.c -o $(TARGET)Quest_3
	
clean:
	rm -rf $(TARGET)*

rebuild: clean all

cl:
	cp ../materials/linters/.clang-format ../src/
	cd .. && clang-format -i */*.c */*.h --verbose

cc:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h