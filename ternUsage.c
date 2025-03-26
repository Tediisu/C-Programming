#include <stdio.h>
/*
    Basic Ternary Usage
    Write a program that takes an integer input and outputs whether the number is 
    "Positive", "Negative", or "Zero" using ternary oerpator 
*/
int main(void)
{
    int a; // user input

    printf("Enter a number: ");
    scanf("%d", &a);

    const char *result = (a > 0) ? "Positve" : (a < 0) ? "Negative" : "Zero";

    printf("%s", result);

    return 0;
}
/*
    Why const char* ?
    1. Avoids Unnecessary Memory ALlocation:
        The strings "Postive", "Negative", and "Zero" are strings literals. These are stored in read-
        only memory and don't need to be copied into a new array. By using a const char*. This
        directly point to the string liberal without duplicating it.

        - Using "char result[]"" would require copying the string literal into the array, which is 
        unnecessary and inefficient.

    2. Efficiency:
        Assigning pointers is faster than copying entire strings. When you use const char*, this just
        store the memory address of the string not the actual content.

    3. Read-Only Strings:
        The "const" ensures that the string literal cannot be modifed accidentally. This protects against
        bugs, as string litrals are not meant to be altered

    Why Not char result?
    1. Incorrect Type:
        A "char" variable can only store a single character(e.g., 'P', 'N'), not a string like "Positive".
        If you tried "char result", you'd get a compiler error.
    
    Why Not char result[]?
    1. Extra Work:
        If you declare "chare result[], you would need to manually copy the appropriate string using
        "strcpy" or similar functions. which is more code and unnecessary.
    2. Memory Overhead:
        Declaring "char result[10]" for storing small strings like "Positive" is wasteful because the
        string literals are already stored in the program's memory
*/