#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_SIZE 5

typedef struct 
{
    char fName[10];
    char lName[10];
} Name;
typedef struct 
{
    Name name;
    int studentID;
    float grades[5];
} Student;

Student *populate(int *);
float calculateAverage(float []);
void updateStudentGrades(Student *, int, int, float []);
void readStudents(Student *, int);

int main(void)
{
    int size;          // Variable to hold the current number of students
    int arraySize = 5; // Fixed array size for demonstration purposes
    Student *list = populate(&size);
    float newG[] = {88.00, 90.00, 85.50,87.00, 89.00};
    
    printf("Students in the system:\n");
    
    readStudents(list, size);
    updateStudentGrades(list, size, arraySize, newG);
    printf("After updating Bob's grades:\n");
    readStudents(list, size);
    
}
Student *populate(int *size)
{
    Student stud[] = {
        {{"Alice", "Johnson"}, 101, {85.00, 90.00, 78.50, 88.00, 92.50}},
        {{"Bob", "Smith"}, 102, {70.00, 75.00, 80.00, 82.00, 79.00}},
        {{"Carol", "Davis"}, 103, {95.00, 93.50, 97.00, 91.00, 89.50}}
    };

    int l = sizeof(stud) / sizeof(stud[0]);
    *size = l;

    Student *newA = malloc(sizeof(Student) * l);
    if (newA != NULL)
    {
        memcpy(newA, stud, sizeof(Student) * l);
    }

    return newA;
}
float calculateAverage(float grades[])
{
    float total = 0;
    int i;
    for (i = 0; i < NUM_SIZE; i++)
    {
        total += grades[i];
    }

    float avg = total / i;
    
    return avg;
}
void updateStudentGrades(Student *stud, int size, int arrS, float nwG[])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        if (!strcmp(stud[i].name.fName, "Bob"))
        {
            for (j = 0; j < arrS; j++)
            {
                stud[i].grades[j] = nwG[j];
            }
        }
    }
}
void readStudents(Student *stud, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Student %d: Name: %s %s, ID = %d, Grades = %.2f %.2f %.2f %.2f %.2f Average = %.2f\n",
            i + 1, stud[i].name.fName, stud[i].name.lName, stud[i].studentID, stud[i].grades[0], stud[i].grades[1],
            stud[i].grades[2], stud[i].grades[3], stud[i].grades[4], calculateAverage(stud[i].grades)
        );
    }
}
