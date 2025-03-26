#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *medioCris(int a[], int s, int *c);
void printArr(int a[], int c);

int main()
{
    int ar[] = {8,1,3,6,5,0};
    int size = sizeof(ar)/sizeof(int);
    int count = 0;

    int *gotchu = medioCris(ar, size, &count);
    printArr(gotchu, count);

    return 0;
}
int *medioCris(int a[], int s, int *c)
{
    if (s == 1 )  //
    {
        int *newA = malloc(sizeof(int));
        newA[1] = a[0];
        *c = 1;
        newA[0] = *c;
        return newA;
    }

    int max = 0;  
    int max2 = 1;

    for (int i = max2; i < s; i++)
    {
        if (a[i] > a[max])
        {
            max2 = max;
            max = i;
        }
        else if (a[i] < a[max] && a[i] > a[max2])
        {
            max2 = i;
        }
    }

    *c = s - max2;
    int *newA = malloc(sizeof(int) * (*c + 1));
    memcpy(&newA[1], a + max2, sizeof(int) * (*c));

    newA[0] = *c;

    return newA;

}
void printArr(int a[], int c)
{
    printf("Numbers {");
    for (int i = 0; i <= c; i++)
    {
        printf("%d", a[i]);
        if (i <= c - 1) printf(", ");
    }
    printf("}");
}