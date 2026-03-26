#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(){
    int n, i;
    int *ptr;
    
    printf("Input number of elements: ");
    scanf("%d", &n);

    ptr = (int*) calloc(n, sizeof(int));

    if (ptr == NULL){
        printf("Memory Allocation failed!");
        return 1;
    }

    printf("Initial values (after calloc): \n");

    displayData(ptr, n);

    printf("Enter The Elements: \n");
    for(i = 0; i < n; i++){
        printf("%d. ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("Output: \n");

    displayData(ptr, n);

    free(ptr);
    
    return 0;
}