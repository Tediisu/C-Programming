#include <stdio.h>
/*
    Even or Odd
    Given an integer, use a ternary operator to print "Even" or "Odd"
*/
int main(void)
{
    int a;

    printf("Enter number: ");
    scanf("%d", &a);

    const char *result = (a % 2 == 0) ? "Even" : "Odd";
       
    printf("%s", result);

    return 0;
}