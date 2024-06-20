CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=*.c
TARGET=../build/
EXECUTABLE=Quest_1
ALLC=-DSTRLEN -DSTRCMP -DSTRCPY -DSTRCAT


1: all run

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)

door_struct:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)
	
run:
	$(TARGET)$(EXECUTABLE) 

clean:
	rm -rf $(TARGET)*

rebuild: clean all

cl:
	cp ../materials/linters/.clang-format ../src/
	cd .. && clang-format -i */*.c */*.h --verbose

cc:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h