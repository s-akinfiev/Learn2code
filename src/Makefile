CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=cipher.c
TARGET=../build/
EXECUTABLE=cipher



all: cipher

cipher:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)$(EXECUTABLE)

clean:
	rm -rf $(TARGET)*

rebuild: clean all

cl:
	cp ../materials/linters/.clang-format ../src/
	cd .. && clang-format -i */*.c */*.h --verbose

cc:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h