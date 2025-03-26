#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *extractChars(char a[], char q);
void printArr(int a[]);

int main()
{
    char text[] = "APPLICATION";
    char get = 'A';

    int *gotchu = extractChars(text, get);
    printArr(gotchu);

    return 0;
}
int *extractChars(char a[], char q)
{   
    int len = strlen(a);
    int *jug = malloc(sizeof(int) * (len + 1));
    int temp = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 'A')
        {
            jug[temp++] = i;
        }
    }

    jug[temp++] = -1;

    return jug;
}
void printArr(int a[])
{   
    int i;

    printf("Output {");
    for (i = 0; a[i] != -1; i++)
    {
        printf("%d ", a[i]);
        if (i != -1) printf(", ");
    }
    printf("%d", a[i]);
    printf("}");
}