#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int *doubleArray(int[], int);

int main (){
    
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    int *doubled = doubleArray(arr, size);
    
    printf("Doubled array elements: ");
    for(int i = 0; i < size; i++){
        printf("%d ", *(doubled + i));
    }
    
    
    return 0;
}

int *doubleArray(int *arr, int size){
    
    int *ptrArr = malloc(sizeof(int) * size);
     
    for(int i = 0; i < size; i++){
        ptrArr[i] = arr[i] * 2;
    }
    
    return ptrArr;
    
}