#include <stdio.h>
/*
    Smallest of Three Numbers
    Write a program that takes three integers, a, b, and c, and determines the smallest 
    of the three using nested ternary operator
*/
int main(void)
{
    int a, b, c;

    printf("Enter number for a: ");
    scanf("%d", &a);
    printf("Enter number for b: ");
    scanf("%d", &b);
    printf("Enter number for c: ");
    scanf("%d", &c);

    int smallest = (a < b && a < c) ? a :
                    (b < a && b < c) ? b: c;

    printf("%d", smallest); 

    return 0;
}