#include <stdio.h>

// 1, если k чётное и −1, если k нечётное.

int main() {
    for (int i = 0; i < 5; i++) {
        printf("%d\t", i);
        printf("%d\n", i + 100);
    }
    return 0;
}