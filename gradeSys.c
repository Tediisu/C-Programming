#include <stdio.h>
/*
    Grading System
    Given a student's score, print the grade using the following criteria:

    Score ≥ 90: "A"
    Score ≥ 80: "B"
    Score ≥ 70: "C"
    Score ≥ 60: "D"
    Otherwise: "F"
    Use nested ternary operators.
*/
int main(void)
{
    int grade;

    printf("Enter your grade: ");
    scanf("%d", &grade);

    char result = (grade >= 90) ? 'A' : 
                    (grade >= 80) ? 'B' : 
                    (grade >= 70) ? 'C' :
                    (grade >= 60) ? 'D' : 'F';

    printf("Your grade is %c", result);

    return 0;
}