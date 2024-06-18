#include "s21_string.h"

#define test1 "hi!"
#define test2 ""  
#define test3 " "
#define test4 "\0"
#define test5 "!@#$\%^&*()_+~<>?\":{}"



void s21_strlen_test(char *str_test, size_t l);

int main(void){
    #ifdef STRLEN
   s21_strlen_test(test1, 3);
   s21_strlen_test(test2, 0);
   s21_strlen_test(test3, 1);
   s21_strlen_test(test4, 0);
   s21_strlen_test(test5, 20);
   #endif
}



void s21_strlen_test(char *str_test, size_t l){
    
    printf("%s\t%ld\t", str_test, s21_strlen(str_test));
    if((s21_strlen(str_test) == l)) printf("SUCCESS\n"); else printf("FAIL\n");
    
}