#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//user defined data types
typedef char String[30];
typedef struct{
    String fName;
    char mi;
    String lName;
}name;

typedef struct{
    float midtermGrade;
    float finalGrade;
    float ismisGrade;
}grades;

typedef struct{
    String idNumber;
    name studName;
    char gender;
    grades studGrades;
    float allowancePerWeek;
}studRec;

studRec* getRichStuds(studRec S[], int size, float threshold)
{
    int i, richCtr;
    studRec temp[size];
    studRec* richStuds;
    
    for(i = richCtr= 0; i < size; i++){
        if(S[i].allowancePerWeek >= threshold){
            temp[richCtr] = S[i];
            richCtr++;
        }
    }
    
    richStuds = malloc(sizeof(studRec) * (richCtr + 1));
    if(richStuds != NULL){
        memcpy(richStuds, temp, sizeof(studRec) * richCtr);
        richStuds[richCtr].allowancePerWeek = -1;
    }
    
    return richStuds;
}

/*
    Write the code for the function calcIsmisGrade. The function will go through each record in S, and update their ismisGrade
    to be their correct value, by getting the sum of 40% of the midtermGrade and 60% of the finalGrade.

*/
void calcIsmisGrade(studRec S[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        S[i].studGrades.ismisGrade = (S[i].studGrades.midtermGrade * .40) + (S[i].studGrades.finalGrade * .60);
    }
}

/*
    Write the code for the function removeFailedStudents. The function will go through each record in S, and check if their
    ismisGrade is that of a passing grade (a passing grade is any grade 3.0 or above). Delete all the students who failed,
    and return an array of names of the failed students. Let the last record of the array of names contain a fName of "XXX"
    to represent the end of the list.
*/
name* removeFailedStudents(studRec S[], int* size)
{   
    name *newA = malloc(sizeof(name) * sizeof(*size + 1));
    int index = 0;

    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (S[i].studGrades.ismisGrade < 3.0)
        {
            newA[index++] = S[i].studName;
            
            for (j = i; j < *size; j++)
            {
                S[j] = S[j + 1];
            }
            (*size)--;
            i--;
        }
    }
    
    strcpy(S[*size].studName.fName, "XXX");
    strcpy(newA[index].fName, "XXX");

    return newA;
}

/*
    Write the code for the function displayStudents. Partial code is provided.
*/
void displayStudents(studRec S[], int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("ID: %s\t| Student: %s %c. %s\t| Grades: %.2f\n", S[i].idNumber, S[i].studName.fName, 
            S[i].studName.mi, S[i].studName.lName, S[i].studGrades.ismisGrade);
    }
    printf("\n\n");
}

/*
    Write the code for the function displayFailedNames(). Partial code is provided.
*/
void displayNames(name N[])
{
    int i;
    for(i = 0; strcmp(N[i].fName, "XXX") != 0; i++){
        printf("Student: %s %c. %s\n", N[i].fName, N[i].mi, N[i].lName);
    }
}



int main(void)
{
    studRec students[20] = {
        {"23104259", {"SHEEN", 'I', "PRADO"}, 'F', {2.0, 2.8, 0.0}, 6400.0},
        {"19103705", {"LUIS", 'M', "BAGUIO"}, 'M', {2.9, 4.1, 0.0}, 6200.0},
        {"23102863", {"FRENZTER", 'N', "PADAL"}, 'M', {2.5, 4.3, 0.0}, 6200.0},
        {"23103156", {"RONALD", 'R', "PADERANGA JR."}, 'M', {2.8, 3.5, 0.0}, 6800.0},
        {"23101874", {"LEX", 'H', "PISCO"}, 'M', {1.8, 2.4, 0.0}, 5000.0},
        {"22102839", {"JAN", 'C', "CABANTOC"}, 'M', {2.8, 3.3, 0.0}, 5700.0},
        {"23103200", {"RANZ", 'A', "BAGUIO"}, 'M', {3.1, 3.9, 0.0}, 5400.0},
        {"21104097", {"VIN", 'M', "SAGARINO"}, 'M', {1.8, 2.2, 0.0}, 5900.0},
        {"23101451", {"SIOBHAN", 'B', "LEONOR"}, 'F', {2.9, 4.0, 0.0}, 6000.0},
        {"23103612", {"NEIL", 'F', "GABISAY"}, 'M', {3.0, 4.5, 0.0}, 9000.0},
        {"22100168", {"JUSTIN", 'W', "RAMO"}, 'M', {2.1, 2.6, 0.0}, 5100.0},
        {"19800010", {"FRANCIS", 'J', "ABORDO"}, 'M', {3.2, 4.0, 0.0}, 7500.0},
        {"23103104", {"VINZEM", 'B', "ACABO"}, 'M', {3.5, 4.2, 0.0}, 6800.0},
        {"21103576", {"EDGIZA", 'K', "LABASTIDA"}, 'F', {3.2, 3.6, 0.0}, 5300.0},
        {"23030013", {"GABRIEL", 'M', "SABANG"}, 'M', {1.9, 2.8, 0.0}, 5200.0},
        {"23104016", {"CHELSEA", 'J', "PIMENTEL"}, 'F', {2.6, 3.2, 0.0}, 5500.0},
        {"19103448", {"ZYLEIKA", 'N', "INVENTO"}, 'F', {2.7, 3.4, 0.0}, 5100.0},
        {"22101303", {"ATHENA", 'J', "UY"}, 'F', {3.0, 3.2, 0.0}, 6000.0},
        {"23104087", {"WARREN", 'V', "RUFILA"}, 'M', {1.7, 2.5, 0.0}, 4800.0},
        {"23101206", {"KEANNE", 'C', "SOCO"}, 'F', {2.0, 2.5, 0.0}, 5300.0}
    };
    int studSize = sizeof(students)/sizeof(studRec);   
    // studRec* richest = getRichStuds(students, studSize, 7500);
    calcIsmisGrade(students, studSize);
    displayStudents(students, studSize);

    name *failedStuds = removeFailedStudents(students, &studSize);
    displayStudents(students, studSize);
    displayNames(failedStuds);
    
    
    return 0;
}