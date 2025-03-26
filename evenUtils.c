#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void getEven1(int [], int, int [], int *);
int *getEven2(int [], int, int *);
int *getEven3(int [], int);
void display1(int [], int);
void display2(int []);

int main()
{
    int arr[] = {1, 2 ,3 , 4, 5};
    int size = 5;
    int arrEven[MAX];
    int countEven = 0;

    int newArr[] = {1, 30, 64, 23, 29, 100};

    getEven1(arr, size, arrEven, &countEven);
    printf("getEven1: ");
    display1(arrEven, countEven);

    int *evenArr2 = getEven2(arr, size, &countEven);
    printf("getEven2: ");
    display1(evenArr2, countEven);

    int *evenArr3 = getEven3(newArr, 6);
    printf("getEven3: ");
    display2(evenArr3);


    return 0;
}
void getEven1(int A[], int sizeA, int B[], int *sizeB)
{   
    int i;

    if (*sizeB < MAX)
    {
        for (i = 0; i < sizeA; i++)
        {
            if (A[i] % 2 == 0)
            {
                B[(*sizeB)++] = A[i];
            }
        }
    }
}
int *getEven2(int A[], int sizeA, int *count)
{
    *count = 0;
    int i;

    if (sizeA < MAX)
    {
        int *even = malloc(sizeof(int) * sizeA);

        for (i = 0; i < sizeA; i++)
        {
            if (A[i] % 2 == 0)
            {
                even[(*count)++] = A[i];
            }
        }

        return even;
    }
}
int *getEven3(int A[], int count)
{
    int i;
    int index = 0;
    int *even = malloc(sizeof(int) * (MAX + 1));

    for (i = 0; i < count; i++)
    {
        if (A[i] % 2 == 0)
        {
            even[index++] = A[i];
        }
    }

    even[index++] = -1;
    return even;
}
void display1(int A[], int count)
{
    int i;

    printf("{");
    for (i = 0; i < count; i++)
    {
        printf("%d", A[i]);
        if (i < count - 1) printf(", ");
    }
    printf("}\n");
}
void display2(int A[])
{
    int i;
    printf("{");
    for (i = 0; A[i] != -1; i++)
    {
        printf("%d", A[i]);
        if (A[i + 1] != -1) printf(", ");
    }
    printf("}");
}