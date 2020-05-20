#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef
struct Student_{
    char name[256];
    int group;
    float rating;
}Student;
int Input(Student* Stud_array, FILE* file, int number_of_students);
int Output(Student* Stud_array, int number_of_students);
int Otchislyator_3000(Student* Stud_array, int* number_of_students, int const expel);
int Autotest(void);
