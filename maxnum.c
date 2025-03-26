#include <stdio.h>
/*
    Maximum of Two Numbers
    Write a function that takes two integers, a and b, as input and returns the
    greater number using a ternary operator.
*/
int main(void)
{
    int a, b;

    printf("Enter number 1: ");
    scanf("%d", &a);
    printf("Enter number 2: ");
    scanf("%d", &b);

    int result;
    result = (a > b) ? a : b;

    printf("The maximum of two numbers is: %d", result);

    return 0;
}