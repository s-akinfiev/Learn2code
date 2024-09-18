CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=*.c
TARGET=../build/
EXECUTABLE=a
EXECUTABLE_STATIC=Quest_5
ALLC=-DSTRLEN -DSTRCMP -DSTRCPY -DSTRCAT




all:
	$(CC) $(CFLAGS) $(ALLC) $(SOURCES) -o $(TARGET)$(EXECUTABLE)

strlen_tests:
	$(CC) $(CFLAGS) $(SOURCES) -DSTRLEN -o $(TARGET)$(EXECUTABLE)

strcmp_tests:
	$(CC) $(CFLAGS) $(SOURCES) -DSTRCMP -o $(TARGET)$(EXECUTABLE)

strcpy_tests:
	$(CC) $(CFLAGS) $(SOURCES) -DSTRCPY -o $(TARGET)$(EXECUTABLE)

strcat_tests:
	$(CC) $(CFLAGS) $(SOURCES) -DSTRCAT -o $(TARGET)$(EXECUTABLE)


clean:
	rm -rf $(TARGET)*

rebuild: clean all

clang:
	cp ../materials/linters/.clang-format ../src/
	cd .. && clang-format -i */*.c */*.h --verbose