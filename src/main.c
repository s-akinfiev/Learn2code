#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "stack.h"
#include "stack.c"


int main (void) {

    char A[100];
    scanf("%s", A);
   
    struct token first;
    strcpy(first.data, A);

    init(&first);
    printf("%s", A);
    
    
    
    return 0;
}