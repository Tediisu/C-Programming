#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bubbleSort(int [], int);
void display(int [], int);
void pause();

int main(void)
{
    int A[] = {5, 4, 3, 1, 2};
    int length = sizeof(A) / sizeof(A[0]);

    printf("Before Sorting\n");
    display(A, length);
    pause();
    bubbleSort(A, length);
    printf("After Sorting\n");
    display(A, length);
    pause();

    return 0;
}

void bubbleSort(int A[], int length)
{
    int i, j, swap;

    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap = A[j];
                A[j] = A[j + 1];
                A[j + 1] = swap;
            }
        }
        printf("Iteration: %d\n", i + 1);
        display(A, length);
        pause();
    }
}
void display(int A[], int length)
{
    int i;
    
    printf("Array List {");
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