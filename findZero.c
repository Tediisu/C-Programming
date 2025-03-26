/*
Write a program that takes an integer array arr and its size size as input. 
Rearrange the elements in the array by moving all the zeros to the end while maintaining the order 
of non-zero elements and then print the modified array to the console.


For example, given the input array is {0, 2, 0, 4, 0, 5} with a size of 6, it should produce the following output:

Enter the size of the array: 10
Enter the elements of the array:
Element 0: 1
Element 1: 0
Element 2: 2
Element 3: 0
Element 4: 3
Element 5: 4
Element 6: 5
Element 7: 0
Element 8: 6
Element 9: 7
Array with zeros moved to the end: 1 2 3 4 5 6 7 0 0 0
*/
#include <stdio.h>
#include <string.h>

void shiftZeroes(int [], int);

int main(void)
{
    int i, size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    shiftZeroes(arr, size);
    printf("Array with zeros moved to the end: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
void shiftZeroes(int A[], int size)
{
    int i, j;
    int count = 3;

    // for (i = 0; i < size; i++)
    // {
    //     for (j = 0; j < size && A[j] != 0; j++){}
    //     int temp = A[j];
    //     memcpy(A + j, A + j + 1, sizeof(int) * (size - j - 1));
    //     A[size - 1] = temp;
    // }

    for (i = 0; i < size; i++)
    {
        if (A[i] == 0)
        {
            for (j = i + i; j < size; j++)
            {
                if (A[j] != 0)
                {
                    int swap = A[j];
                    A[i] = A[j];
                    A[j] = swap;
                    break;
                }
            }
        }
    }
}