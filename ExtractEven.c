#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void getEven1(int [], int, int [], int *);
int *getEven2(int [], int, int *);
int *getEven3(int []);
void displayA(int [], int);
void displayB(int []);

int main(void)
{
    int A[MAX] = {1, 2, 3, 4, 5};
    int length = 5;
    int even[MAX];
    int evenCtr;

    int B[MAX]={1,2,3,4,5,6,7,8,-1,9};

    getEven1(A, length, even, &evenCtr);
    printf("Output of getEven1:\n");
    displayA(even, evenCtr);

    int *extractA = getEven2(A, length, &evenCtr);
    printf("Output of getEven2:\n");
    displayA(extractA, evenCtr);

    int *extractB = getEven3(B);
    printf("Output of getEven3:\n");
    displayB(extractB);

    return 0;
}
void getEven1(int A[], int length, int even[], int *evenCtr)
{
    *evenCtr = 0;
    int i;

    if (length  < MAX)
    {
        for (i = 0; i < length; i++)
        {
            if (A[i] % 2 == 0)
            {
                even[(*evenCtr)++] = A[i];
            }
        }
    }

}
int *getEven2(int A[], int length, int *evenCtr)
{
    *evenCtr = 0;
    int i;

    if (length < MAX)
    {
        int *list = (int*)malloc(sizeof(int) * length);

        for (i = 0; i < length; i++)
        {
            if (A[i] % 2 == 0)
            {
                list[(*evenCtr)++] = A[i];
            }
        }

        return list;
    }

    return 0;
}
int *getEven3(int A[])
{
    int *list = (int*)malloc(sizeof(int) * (MAX + 1));
    int nDx = 0;
    int i;

    for (i = 0; i < MAX; i++)
    {
        if (A[i] % 2 == 1)
        {
            list[nDx++] = A[i];
        }
    }

    list[nDx++] = -1;

    return list;
}
void displayA(int A[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%d", A[i]);
        if (i < length - 1) printf(", ");
    }

    printf("\n");
}
void displayB(int A[])
{
    int i;

    for (i = 0; A[i] != -1; i++)
    {
        printf("%d", A[i]);
        if (A[i + 1] != -1) printf(", ");
    }
}
