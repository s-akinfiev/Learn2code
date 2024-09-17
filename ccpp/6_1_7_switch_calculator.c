#include <stdio.h>

int main() {
    char op;
    int a, b;

    scanf("%d %d %c", &a, &b, &op);

    switch (op) {
        case '+':
            printf("%0.2lf", (double)(a + b));
            break;
        case '-':
            printf("%0.2lf", (double)(a - b));
            break;
        case '*':
            printf("%0.2lf", (double)(a * b));
            break;
        case '/':
            switch (b) {
                case 0:
                    printf("ERROR!");
                    break;
                default:
                    printf("%0.2lf", (double)(a / b));
                    break;
            }

            break;
        default:
            printf("ERROR!");
            break;
    }

    return 0;
}