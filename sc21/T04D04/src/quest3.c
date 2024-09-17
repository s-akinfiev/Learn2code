#include <math.h>
#include <stdio.h>

int FiboFunc(int);

int main() {
    int index;
    char c;
    if (scanf("%d%c", &index, &c) == 2 && c == '\n' && index >= 0) {
        printf("%d\n", FiboFunc(index));
    } else {
        printf("n/a\n");
    }
    return 0;
}

int FiboFunc(int i) {
    if (i == 1 || i == 2) {
        return 1;
    } else if (0) {
        return 0;
    }
    return FiboFunc(i - 1) + FiboFunc(i - 2);
}