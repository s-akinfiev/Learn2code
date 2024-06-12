/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int target_numbers_count(int *buffer, int length, int number);
void find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length;
    if (scanf("%d", &length) == 1 && length > 0 && length <= NMAX) {
        int source_array[length];
        int target_array[length];
        int target_length;
        if (input(source_array, length) == 1) {
            find_numbers(source_array, length, sum_numbers(source_array, length), target_array);
            target_length = target_numbers_count(source_array, length, sum_numbers(source_array, length));
            printf("%d\n", sum_numbers(source_array, length));
            output(target_array, target_length);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

int input(int *buffer, int length) {
    int input_ok = 1;

    for (int *a = buffer; a - buffer < length; a++) {
        if (scanf("%d", a) != 1) input_ok = 0;
    }
    return input_ok;
}

void output(int *buffer, int length) {
    for (int *a = buffer; a - buffer < length; a++) {
        if (a - buffer != length - 1)
            printf("%d ", *a);
        else
            printf("%d \n", *a);
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int *a = buffer; a - buffer < length; a++) {
        if (*a % 2 == 0) {
            sum = sum + *a;
        }
    }

    return sum;
}

int target_numbers_count(int *buffer, int length, int number) {
    int j = 0;
    int sum_even = number;
    for (int *a = buffer; a - buffer < length; a++) {
        if (*a != 0 && sum_even % *a == 0) {
            j++;
        }
    }
    return j;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
void find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    int sum_even = number;
    for (int *a = buffer; a - buffer < length; a++) {
        if (*a != 0 && sum_even % *a == 0) {
            numbers[j] = *a;
            j++;
        }
    }
}