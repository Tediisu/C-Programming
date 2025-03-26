#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 10

typedef char String[32];
typedef struct 
{
    String fname;
    String lname;
} Name;

typedef struct 
{
    Name name;
    int age;
    char sex;
    String address;
} Person;

void createPerson(Person *);
Name createName(String fname, String lname);
bool addPerson(Person [], int *, Person);
void display(Person []);
void pause(void);

int main()
{
    Person list[MAX];
    int count = 0;

    do 
    {
        Person p;
        createPerson(&p);

        p.name = createName(p.name.fname, p.name.lname);
        if (addPerson(list, &count, p))
        {
            printf("Person Added Successfulyl!\n");
        }
        else
        {
            printf("Person Added Unsuccessfully\n");
        }
        pause();
    } while (count < MAX);

    pause();
    display(list);

    return 0;
}

void createPerson(Person *p)
{
    fflush(stdin);
    printf("Enter First Name: ");
    fgets(p->name.fname, 32, stdin);
    fflush(stdin);
    printf("Enter Last Name: ");
    fgets(p->name.lname, 32, stdin);
    fflush(stdin);
    printf("Enter age: ");
    scanf(" %d", &p->age);
    fflush(stdin);
    printf("Enter sex: ");
    scanf(" %c", &p->sex);
    fflush(stdin);
    printf("Enter address: ");
    fgets(p->address, 32, stdin);   
    fflush(stdin);
}
Name createName(String fname, String lname)
{
    Name name;

    strcpy(name.fname, fname);
    strcpy(name.lname, lname);

    return name;
}
bool addPerson(Person A[], int *count, Person person)
{
    if (*count < MAX)
    {
        A[(*count)++] = person;

        return 1;
    }

    return 0;
}
void display(Person A[])
{
    int i;
    printf("\n%-15s %-15s %-5s %-3s %-20s\n", "FName", "LName", "Age", "Sex", "Address");
    for (i = 0; i < MAX; i++)
    {
        printf("%-15s %-15s %-4d %-3c %-20s\n", 
               A[i].name.fname,
               A[i].name.lname,
               A[i].age,
               A[i].sex,
               A[i].address);
    }
}
void pause(void)
{
    printf("\n\nEnter a key to continue...");
    _getch();
    system("CLS");
}