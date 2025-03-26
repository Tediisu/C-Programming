#include <stdio.h>
#include <string.h>
#define MAX 10

int sumEven(int [], int);
int sumOdd(int [], int);
float avgEven(int [], int);
float avgOdd(int [], int);
int countEven(int [], int);
int countOdd(int [], int);
void insertFirst(int [], int *, int);
void insertSorted(int [], int *, int);
void insertLast(int [], int *, int);
void displayCalcs(int [], int);
void display(int [], int);

int main()
{
    int arr[MAX] = {1, 2, 3, 4, 5};
    int size = 5;

    //=====Before Manipualting=====//
    displayCalcs(arr, size);
    display(arr, size);
    //=====After Manipulating=====//
    printf("\n\n");
    insertFirst(arr, &size, 100);
    insertSorted(arr, &size, 50);
    insertLast(arr, &size, 128);
    insertSorted(arr, &size, 130);
    displayCalcs(arr, size);
    display(arr, size);


    return 0;
}
int sumEven(int A[], int size)
{   
    int sumEven = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 == 0)
        {
            sumEven += A[i];
        }
    }

    return sumEven;
}
int sumOdd(int A[], int size)
{
    int sumOdd = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 != 0)
        {
            sumOdd += A[i];
        }
    }

    return sumOdd;
}
float avgEven(int A[], int size)
{
    int sum = 0;
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 == 0)
        {
            sum += A[i];
            count++;
        }
    }

    return (count > 0) ?  ((float)sum / (float)count) : 0.0;
}
float avgOdd(int A[], int size)
{
    int sum = 0;
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 != 0)
        {
            sum += A[i];
            count++;
        }
    }

    return (count > 0) ? ((float)sum / (float)count) : 0.0;
}
int countEven(int A[], int size)
{
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}
int countOdd(int A[], int size)
{
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] % 2 != 0)
        {
            count++;
        }
    }

    return count;
}
void insertFirst(int A[], int *size, int num)
{
    if (*size < MAX)
    {
        memcpy(A + 1, A + 0, sizeof(int) * (*size)); //dest, src, size
        A[0] = num;
        (*size)++;
    }
}
void insertSorted(int A[], int *size, int num)
{   
    int i;

    if (*size < MAX)
    {
        // for (i = 0; i < *size; i++)
        // {
        //     if (num < A[i]) //50 < 100
        //     {
        //         memcpy(A + i + 1, A + i, sizeof(int) *( *size - i)); //{100, 1, 2,3 ,4 ,5, 128} -> {0, 100, 1, 2, 3, 4, 5, 128}
        //         A[i] = num;
        //         (*size)++;

        //         return;
        //     }
        // }
        // 
        // A[(*size)++] = num;

        for (i = 0; i < *size && num > A[i]; i++){}
        memcpy(A + i + 1, A + i, sizeof(int) * (*size - i));
        A[i] = num;
        (*size)++;
    }
}
void insertLast(int A[], int *size, int num)
{
    if (*size < MAX)
    {
        A[(*size)++] = num;
    }
}
void displayCalcs(int A[], int size)
{
    printf("Sum of Even: %d\n", sumEven(A, size));
    printf("Sum of Odd: %d\n", sumOdd(A, size));
    printf("Average of Even: %.2f\n", avgEven(A, size));
    printf("Average of Odd: %.2f\n", avgOdd(A, size));
    printf("Count of Even: %d\n", countEven(A, size));
    printf("Count of Odd: %d\n", countOdd(A, size));
}
void display(int A[], int size)
{
    int i;

    printf("Array List: {");
    for (i = 0; i < size; i++)
    {
        printf("%d", A[i]);
        if (i < size - 1) printf(", ");
    }
    printf("}");
}