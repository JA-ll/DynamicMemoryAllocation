#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(){
    int n, i;
    int *ptr;
    char choice;
    
    printf("Input number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL){
        printf("Memory Allocation failed!");
        return 1;
    }

    printf("Enter The Elements: \n");
    for(i = 0; i < n; i++){
        printf("%d. ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("Output: \n");

    displayData(ptr, n);

    printf("Do you want to add the size? (Y/N)\n");
    scanf(" %c" , &choice);

    if(choice == 'Y' || choice == 'y'){
        int extra;

        printf("How many elements? \n");
        scanf("%d", &extra);

        int *temp = (int*) realloc(ptr, n + extra * sizeof(int));

        if (temp == NULL){
            printf("Reallocation failed!");
            return 1;
        }else{
            ptr = temp;
            printf("Enter Additional Value: \n");
        
            for(i = n; i < n + extra; i++){
                scanf("%d", ptr + i);
            }

            n = n + extra;

            printf("Updated Value: ");
            displayData(ptr, n);
        }

    }
    
    free(ptr);
    
    return 0;
}