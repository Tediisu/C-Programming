#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 10

typedef struct 
{
    int elems[MAX];
    int count;
} ArrayList;

void initList(ArrayList *);
void displayChoices();
void insertFirst(ArrayList *, int);
void insertAt(ArrayList *, int, int);
void insertLast(ArrayList *, int);
void insertSorted(ArrayList *, int);
void removeFirst(ArrayList *);
void removeAt(ArrayList *, int);
void removeLast(ArrayList *);
void display(ArrayList);
void pause();

int main(void)
{
    int choice, num, index;

    ArrayList list;
    initList(&list);

    do 
    {
        displayChoices();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter number to insert at the beginning: ");
                scanf("%d", &num);
                insertFirst(&list, num);
                break;

            case 2:
                printf("Enter index and number to insert: ");
                scanf("%d %d", &index, &num);
                insertAt(&list, index, num);
                break;

            case 3:
                printf("Enter number to insert at the end: ");
                scanf("%d", &num);
                insertLast(&list, num);
                break;

            case 4:
                printf("Enter number to insert in sorted order: ");
                scanf("%d", &num);
                insertSorted(&list, num);
                break;

            case 5:
                removeFirst(&list);
                break;

            case 6:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                removeAt(&list, index);
                break;

            case 7:
                removeLast(&list);
                break;

            case 8:
                display(list);
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 9);



    return 0;
}
void initList(ArrayList *L)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        L->elems[i] = 0;
    }
    L->count = 0;
}
void displayChoices()
{
    const char *arr[] = {"Insert First", "Insert At", "Insert Last", "Insert Sorted",
                    "Remove First", "Remove At", "Remove Last", "Display Array", "Exit"};
    int size = sizeof(arr) / sizeof(arr[0]);

    int i;
    for (i = 0; i < size; i++)
    {
        printf("[%d] %s\n", i + 1, arr[i]);
    }
}
void insertFirst(ArrayList *L, int num)
{
    if (L->count < MAX)
    {
        memmove(L->elems + 1, L->elems, sizeof(int) * L->count);
        L->elems[0] = num;
        (L->count)++;
    }
}               
void insertAt(ArrayList *L, int index, int num) 
{
    if (index >= 0 && index <= L->count && L->count < MAX)
    {
        memmove(L->elems + index + 1, L->elems + index, sizeof(int) * (L->count - index));
        L->elems[index] = num;
        (L->count)++;
    }
}

void insertLast(ArrayList *L, int num)
{
    if (L->count < MAX)
    {
        L->elems[(L->count)++] = num;
    }
}
void insertSorted(ArrayList *L, int num)
{   
    int i;

    if (L->count < MAX)
    {
        for (i = 0; i < L->count && L->elems[i] < num; i++){}
        memcpy(L->elems + i + 1, L->elems + i, sizeof(int) * (L->count - i));
        L->elems[i] = num;
        (L->count)++;
    }
}
void removeFirst(ArrayList *L)
{
    if (L->count > 0)
    {
        memcpy(L->elems + 0, L->elems + 1, sizeof(int) * (L->count - 1));
        (L->count)--;
    }
}
void removeAt(ArrayList *L, int index)
{
    if (L->count > 0)
    {
        memcpy(L->elems + index, L->elems + index + 1, sizeof(int) * (L->count + 1));
        (L->count)--;
    }
}
void removeLast(ArrayList *L)
{
    if (L->count > 0)
    {
        (L->count)--;
    }
}
void display(ArrayList L)
{
    int i;

    printf("\n\nArray List:\n");
    for (i = 0; i < MAX ; i++)
    {
        printf("[%d] = %d\n", i, L.elems[i]);
    }
    pause();

}
void pause()
{
    printf("\n\nPress any key to continue...");
    _getch();
    system("CLS");
}