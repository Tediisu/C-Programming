#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *medioCris(int a[], int s, int *c);
void printArr(int *a, int c);

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 5, 8};
    int size = sizeof(arr)/sizeof(int);
    int count = 0;

    int *justGot = medioCris(arr, size, &count);
    printArr(justGot, count);
    
    return 0;
}
int *medioCris(int a[], int s, int *c)
{
    if (s == 1)
    {
        int *newA = malloc(sizeof(int));
        newA[1] = a[0];
        *c = 1;
        newA[0] = *c;
        return newA;
    }

    int max = -99;
    int max2 = -99;
    int temp = 0;

    for (int i = 0; i < s; i++)
    {   
        if (a[i] > max)
        {
            max2 = max;
            max = a[i];
        }
        else if (a[i] < max && a[i] > max2)
        {   
            max2 = a[i];
            // temp = i;
        }
    }

    // *c = s - temp;
    for (int k = 0; k < s; k++)     
    {
        if (a[k] == max2)
        {
            temp = k;
            for (int j = k; j < s; j++)
            {
                (*c)++;
            }
            break;
        }
    }

    int *newA = malloc(sizeof(int) * (*c + 1));
    memcpy(&newA[1], a + temp, sizeof(int) * (*c));
    
    newA[0] = *c;

    //without memcpy 
    // if (s == 1)
    // {
    //     int *newA = malloc(sizeof(int));
    //     newA[0] = a[0];
    //     *c = 1;
    //     return newA;
    // }

    // int max = -999;
    // int max2 = -999;
    // int j = 0;

    // for (int i = 0; i < s; i++)
    // {
    //     if (a[i] > max)
    //     {
    //         max2 = max;
    //         max = a[i];
    //     }
    //     else if (a[i] < max && a[i] > max2)
    //     {
    //         max2 = a[i];
    //         j++;
    //     }
    // }

    // int *newA = malloc(sizeof(int) * j);

    // for (int i = 0; i < s; i++)
    // {
    //     if (a[i] == max2)
    //     {
    //         for (int k = i; k < s; k++)
    //         {
    //             newA[(*c)++] = a[k];
    //         }
    //         break;
    //     }
    // }

    return newA;
}
void printArr(int *a, int c)
{
    printf("The numbers [");
    for (int i = 0; i <= c; i++)
    {
        printf("%d", a[i]);
        if (i <= c - 1) printf(", ");
    }
    printf("]");

}