#include <stdio.h>

void getNumbers(int [], int);
int getOdd(int [], int);

int main()
{
    int length;

    printf("Enter the No. of values to store: ");
    scanf("%d", &length);

    int A[length];

    getNumbers(A, length);
    int sumOdd = getOdd(A, length);

    printf("Sum of Odd numbers: %d", sumOdd);

    return 0;
}

void getNumbers(int A[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        scanf("%d", &A[i]);
    }
}
int getOdd(int A[], int length)
{
    int sum = 0;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 != 0)
        {
            sum += A[i];
        }
    }

    return sum;
}
