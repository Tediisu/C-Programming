#include <stdio.h>
#define MAX 10

int sumOfEven(int [], int);
int sumOfOdd(int [], int);
int countOfEven(int [], int);
int countOfOdd(int [], int);
float avgEven(int [], int);
float avgOdd(int [], int);
void displayEven(int [], int);
void displayOdd(int [], int);
void displayAll(int [], int);

int main(void)
{
    int A[] = {1, 2, 3, 4, 5};
    int length = sizeof(A) / sizeof(A[0]);

    printf("Sum of Even: %d\n", sumOfEven(A, length));
    printf("Sum of Odd: %d\n", sumOfOdd(A, length));  
    printf("Average of Even: %.2f\n", avgEven(A, length));  
    printf("Average of Odd: %.2f\n", avgOdd(A, length));
    printf("Count of Even Numbers: %d\n", countOfEven(A, length));
    printf("Count of Odd Numbers: %d\n", countOfOdd(A, length));

    printf("\n\n");
    displayEven(A, length);
    displayOdd(A, length);
    displayAll(A, length);

    return 0;
}
int sumOfEven(int A[], int length)
{
    int sum = 0;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 == 0)
        {
            sum += A[i];
        }
    }

    return sum;
}
int sumOfOdd(int A[], int length)
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
int countOfEven(int A[], int length)
{
    int evenCtr = 0;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 == 0)
        {
            evenCtr++;
        }
    }

    return evenCtr;
}
int countOfOdd(int A[], int length)
{
    int oddCtr = 0;
    int i;

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 != 0)
        {
            oddCtr++;
        }
    }

    return oddCtr;
}
float avgEven(int A[], int length)
{
    return sumOfEven(A, length) / countOfEven(A, length);
}
float avgOdd(int A[], int length)
{
    return sumOfOdd(A, length) / countOfOdd(A, length);
}
void displayEven(int A[], int length)
{
    int i;

    printf("Even Numbers: ");

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 == 0)
        {
            printf("%d ", A[i]);
        }
    }

    printf("\n");
}
void displayOdd(int A[], int length)
{
    int i;

    printf("Odd Numbers: ");

    for (i = 0; i < length; i++)
    {
        if (A[i] % 2 != 0)
        {
            printf("%d ", A[i]);
        }
    }

    printf("\n");
}
void displayAll(int A[], int length)
{
    int i;

    printf("Array List: ");

    for (i = 0; i < length; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}




