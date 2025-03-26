#include <stdio.h>

int main()
{
    int i, l;

    printf("Enter the length of the array: ");
    scanf("%d", &l);

    int A[l];

    printf("Enter the values of the array:\n");
    for (i = 0; i < l; i++)
    {
        scanf("%d", A + i);
    }

    //dsiplay

    printf("Array Values: ");
    for (i = 0; i < l; i++)
    {
        printf("%d ", *(A + i));
    }

    return 0;
}