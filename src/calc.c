#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double calc(char *str, int n, int x) {
    double buf[100] = {0};
    int inBuf = 0, f;

    for (int i = 0; i < n; i++) {  // idem po stroke
        if (chislo(str[i])) {      // sobiraem chisla
            buf[inBuf] = schet(str, &i);
            inBuf++;
        } else if (str[i] == 'x') {
            buf[inBuf] = x;
            inBuf++;
        } else if (!chislo(str[i]) && str[i] != ' ') {  // esli NE chislo to...

            f = (int)str[i];
            if (str[i] == 's') {  // zdes smotrim, mb this is func
                if (str[i + 1] == 'i')
                    f = 115;  // sin
                else if (str[i + 1] == 'q')
                    f = 113;  // sqrt
                else
                    printf("\nERROR s '%d'", i);
            }

            if (str[i] == 'c') {
                if (str[i + 1] == 'o')
                    f = 99;  // cos
                else if (str[i + 1] == 't')
                    f = 107;  // ctg
                else
                    printf("\nERROR c");
            }

            if (str[i] == 't' && str[i + 1] == 'a') f = 116;  // tan

            if (str[i] == 'l' && str[i + 1] == 'n') f = 108;  // ln    A zdes zakanchivaem smotret na func

            if (choose(buf, &inBuf, f)) {
                char c = str[i];
                printf("\nERROR on %d element\nProb symb - %c", i, c);
            }

            if (f == 115 || f == 99 || f == 107 ||
                f == 116)  // perehodim na konec, naprimer mi bili na Sin teper budem na siN
                i += 2;
            else if (f == 108)
                i += 1;
            else if (f == 113)
                i += 3;
        }
    }
    return buf[0];
}

int chislo(char c) {  // esli CIFRA -> 1 ya prosto debik a menyat len'
    int f = 0;
    if (c >= '0' && c <= '9') f++;
    return f;
}

double schet(char *str, int *index) {  // poluchaem chislo iz stroki do ' '
    int i = 0;
    double b[100], ret = 0;
    while (str[*index] != ' ' && str[*index] != '\0') {  // opredelyaem neforof

        if (chislo(str[*index])) {
            b[i] = (int)str[*index] - 48;
            i++;
        }
        (*index)++;
    }

    for (int j = 0; j < i; j++) {  // sobiraem neforof na zabiv
        if (j != i - 1)
            ret = (ret + b[j]) * 10;
        else
            ret += b[j];
    }

    return ret;
}

int choose(double *buf, int *inBuf, int f) {  // DEYSTVIYA
    int flag = 0;
    switch (f) {
        case 45:  // "-"
            buf[*inBuf - 2] -= buf[*inBuf - 1];
            (*inBuf)--;
            break;

        case 43:  // "+"
            buf[*inBuf - 2] += buf[*inBuf - 1];
            (*inBuf)--;
            break;

        case 42:  // "*"
            buf[*inBuf - 2] *= buf[*inBuf - 1];
            (*inBuf)--;
            break;

        case 47:  // "/"
            if (buf[*inBuf - 1] != 0) {
                buf[*inBuf - 2] /= buf[*inBuf - 1];
                (*inBuf)--;
            } else {
                printf("\nERROR - delenie na 0!\n");
            }
            break;

        case 115:  // "sin"
            buf[*inBuf - 1] = sin(Deg2Rad(buf[*inBuf - 1]));
            (*inBuf)--;
            break;

        case 99:  // "cos"
            buf[*inBuf - 1] = cos(Deg2Rad(buf[*inBuf - 1]));
            (*inBuf)--;
            break;

        case 116:  // "tan"
            if (cos(Deg2Rad(buf[*inBuf - 1])) != 0) {
                buf[*inBuf - 1] = tan(Deg2Rad(buf[*inBuf - 1]));
                (*inBuf)--;
            } else {
                printf("\nERROR - delenie na 0 v TAN!\n");
            }

            break;

        case 107:  // "ctg"
            if (sin(Deg2Rad(buf[*inBuf - 1])) != 0) {
                buf[*inBuf - 1] = cos(Deg2Rad(buf[*inBuf - 1])) / sin(Deg2Rad(buf[*inBuf - 1]));
                (*inBuf)--;
            } else {
                printf("\nERROR - delenie na 0 v CTG!\n");
            }
            break;

        case 113:  // "sqrt"
            if (buf[*inBuf - 1] > 0) {
                buf[*inBuf - 1] = sqrt(buf[*inBuf - 1]);
                (*inBuf)--;
            } else {
                printf("\nERROR sqrt(n < 0)!");
            }
            break;

        case 108:  // "ln"
            if (buf[*inBuf - 1] > 0) {
                buf[*inBuf - 1] = log(buf[*inBuf - 1]);
                (*inBuf)--;
            } else {
                printf("\nERROR ln(n <= 0)!");
            }
            break;

        default:
            flag = 1;
    }
    return flag;
}

double Deg2Rad(double a) { return a * 180 / M_PI; }