//Dynamic Array Population
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void populateEven(int *, int *, int);
void populateOdd(int *, int *, int);

int main(void)
{
    int *A = malloc(sizeof(int));
    int *B = malloc(sizeof(int));
    int countA = 0;
    int countB = 0;
    int i, num;
    
    while (true)
    {
        scanf("%d", &num);
        if (num == -1) break;
        (num % 2 == 0) ? populateEven(A, &countA, num) : populateOdd(A, &countB, num);
    }
    
    
    printf("Even: ");
    for (i = 0; i < countA; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("Odd: ");
    for (i = 0; i < countA; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    
    free(A);
    free(B);
    
    return 0;
}
void populateEven(int *A, int *count, int num)
{
    if (A != NULL)
    {
        A = realloc(A, sizeof(int) * 1);
        A[(*count)++] = num;
    }
}
void populateOdd(int *B, int *count, int num)
{
    if (B != NULL)
    {
        B = realloc(B, sizeof(int) * 1);
        B[(*count)++] = num;
    }
}