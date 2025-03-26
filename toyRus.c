#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTOYS 50

typedef struct{
    char toyName[32];
    char toyColor;
    float weight;
}toyRecord;

typedef struct{
    toyRecord toys[MAXTOYS];
    int lastToy;
}toyList;

/* Write the code of insertToyByColor. The function will insert the toy into the toyList
   based on its color. It will insert the toy at the front of the color group.
 */

void initToyList(toyList *l)
{
    l->lastToy = -1;
}

void insertToyByColor(toyList* TL, toyRecord T) // to review
{
    //insert something
    if (TL->lastToy < MAXTOYS)
    {
        int i;
        for (i = 0; i <= TL->lastToy && TL->toys[i].toyColor != T.toyColor; i++){}
        TL->lastToy++;
        memcpy(TL->toys + i + 1, TL->toys + i, sizeof(toyRecord) * (TL->lastToy - i));
        TL->toys[i] = T;
    }
}

void populateToyList(toyList* TL, toyRecord T[], int numToys)
{
    int i;
    for (i = 0; i < numToys; i++) insertToyByColor(TL, T[i]);
}
void printList(toyList L)
{
    for (int i = 0; i <= L.lastToy; i++)
    {
        printf("%s\t%c\t%.1f\n", L.toys[i].toyName, L.toys[i].toyColor, L.toys[i].weight);
    }
}

int main(void)
{
    toyList Liz;
    initToyList(&Liz);
    toyRecord toyarray[] = {
        {"Snake", 'G', 1.5}, {"Train", 'P', 5.0}, {"Gun", 'B', 3.0},
                            {"Car", 'V', 6.5}, {"Teddy", 'P', 2.5}, {"Lego", 'G', 1.5}
    };
    int length = sizeof(toyarray) / sizeof(toyRecord);
    
    //Declare and initialize a toyList.
    //Populate the toyList using populateToyList().     
    populateToyList(&Liz, toyarray, length);          
    printList(Liz);
}