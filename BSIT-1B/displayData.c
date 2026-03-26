#include "function.h"
#include <stdio.h>

void displayData(int *ptr, int size){
    int i;

    for(i = 0; i < size; i++){
        printf("%d \n", *(ptr + i));
    }
}