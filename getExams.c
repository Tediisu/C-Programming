#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fName[32];
	char mi;
	char lName[16];
}fullName;

typedef struct{
	int score;			//Score of the student.
	int totalScore;		//Total score of the exam.
}exam;

typedef struct{
	exam exams[4];
	int numExams;
}grades;

typedef struct{
	fullName name;
	char idNum[9];
	char course[5];
	char gender;
	grades examScores;
}student;

typedef struct{
	char idNum[9];
	int index;
}studIndex;

studIndex* getExamPassers(student*, int, int);
void display(student *, studIndex *, int);

int main(void)
{
	student students[10] = {
	    {{"Alice", 'B', "Johnson"}, "22101234", "BSCS", 'F', {{{85, 100}, {75, 100}, {60, 100}, {90, 100}}, 4 }},
	    {{"Bob", 'C', "Smith"}, "21102345", "BSIT", 'M', {{{45, 100}, {70, 100}, {80, 100}, {65, 100}}, 4 }},
	    {{"Charlie", 'D', "Brown"}, "20103456", "BSIS", 'M', {{{78, 100}, {60, 100}, {85, 100}, {55, 100}}, 4 }},
	    {{"Diana", 'E', "Clark"}, "19104567", "BSCS", 'F', {{{60, 100}, {62, 100}, {90, 100}, {50, 100}}, 4 }},
	    {{"Ethan", 'F', "Lewis"}, "18105678", "BSIT", 'M', {{{70, 100}, {80, 100}, {90, 100}, {30, 100}}, 4 }},
	    {{"Fiona", 'G', "Martinez"}, "22106789", "BSIS", 'F', {{{85, 100}, {88, 100}, {90, 100}, {40, 100}}, 4 }},
	    {{"George", 'H', "Wilson"}, "21107890", "BSCS", 'M', {{{67, 100}, {75, 100}, {80, 100}, {90, 100}}, 4 }},
	    {{"Hannah", 'I', "Moore"}, "20108901", "BSIT", 'F', {{{55, 100}, {60, 100}, {85, 100}, {95, 100}}, 4 }},
	    {{"Ian", 'J', "Taylor"}, "19109012", "BSIS", 'M', {{{30, 100}, {40, 100}, {60, 100}, {70, 100}}, 4 }},
	    {{"Julia", 'K', "Anderson"}, "18101234", "BSCS", 'F', {{{90, 100}, {85, 100}, {70, 100}, {40, 100}}, 4 }}
	};
	int numStuds = sizeof(students) / sizeof(student);
    
	studIndex* exam1Passers = getExamPassers(students, numStuds, 0);
	studIndex* exam2Passers = getExamPassers(students, numStuds, 1);
	studIndex* exam3Passers = getExamPassers(students, numStuds, 2);
	studIndex* exam4Passers = getExamPassers(students, numStuds, 3);
	// studIndex* exam5Passers = getExamPassers(students, numStuds, 5);
	
    display(students, exam1Passers, 1);
    display(students, exam1Passers, 2);
    display(students, exam1Passers, 3);
    display(students, exam1Passers, 4);
    // display(students, exam1Passers, 5);





	return 0;
}

studIndex *getExamPassers(student *stud, int size, int type)
{
    studIndex temp[size];
    int i, j;
    for (i = j = 0; i < size; i++)
    {
        if (stud[i].examScores.exams[type].score >= 60)
        {
            strcpy(temp[j].idNum, stud[i].idNum);
            temp[j].index = i;
            j++;
        }
    }

    studIndex *newA = malloc(sizeof(studIndex) * (j + 1));
    if (newA != NULL)
    {
        memcpy(newA, temp, sizeof(studIndex) * j);
        newA[j].index = -1;
    }

    return newA;
}
void display(student *stud, studIndex *index, int type)
{
    printf("Exam Number: %d\n", type);
    int i, j;
    for (i = 0; index[i].index != -1; i++)
    {
        j = index[i].index;
        printf("ID: %s | Name: %s %c %s | Program: %s | Scores: %d\n",
            stud[j].idNum, stud[j].name.fName, stud[j].name.mi, stud[j].name.lName, stud[j].course,
            stud[j].examScores.exams[type - 1].score
        );
    }
}