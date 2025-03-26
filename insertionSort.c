#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insertionSort(int [], int);
void display(int [], int);
void pause();

int main(void)
{
    int A[] = {4, 5, 3, 1, 2};
    int length = sizeof(A) / sizeof(A[0]);

    printf("Before Sorting:\n");
    display(A, length);
    pause();
    insertionSort(A, length);
    printf("After Sorting:\n");
    display(A, length);
    pause();

    return 0;
}
void insertionSort(int A[], int length)
{
    int i, j, num;

    for (i = 1; i < length; i++)
    {
        num = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > num)
        {
            A[j + 1] = A[j];
            j--;
            display(A, length);
            pause();
        }

        A[j + 1] = num;
        printf("Iteration: %d\n", i);
        display(A, length);
        pause();

    }
}
void display(int A[], int length)
{
    int i;

    printf("Array: {");
    for (i = 0; i < length; i++)
    {
        printf("%d", A[i]);
        if (i < length - 1) printf(", ");
    }
    printf("}");
}
void pause()
{
    printf("\n\nEnter any key to continue....\n\n");
    _getch();
    system("CLS");
}