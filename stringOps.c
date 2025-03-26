#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAXINPUT 64

int countChar(char *);
void pause(void);

int main()
{
    char str[MAXINPUT];

    printf("Enter a string: ");
    fgets(str, MAXINPUT, stdin);
    
    int numOfLetters = countChar(str);
    printf("%d", numOfLetters);

    return 0; 
}   
int countChar(char *S)
{
    int i;
    int count = 0;

    for (i = 0; i < MAXINPUT; i++)
    {
        if (isalpha(S[i])) count++;
    }

    return count;
}
void pause(void)
{
    printf("\n\nPress any key to continue...");
    _getch();
    system("CLS");
}