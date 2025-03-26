#include <stdio.h>
/*
    Eligibility for Voting
    Create a program that checks if a person is eligible to vote. If the age is 18 or above, 
    print "Eligible", otherwise print "Not Eligible" using a ternary operator.
*/
int main(void)
{
    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    const char *result = (age >= 18) ? "Eligible" : "Not Eligible";

    printf("You are %s for voting", result);

    return 0;
}