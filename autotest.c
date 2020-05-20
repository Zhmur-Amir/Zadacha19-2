#include "wh.h"
int Autotest(void){
    FILE* input_file;
    Student* Stud_array;
    int number_of_students = 0;
    char count_temp[512];
    int test;

    input_file = fopen("test.txt", "r");
    if (!input_file){
        printf("Error: cannot open file\n");
        exit(-1);
    }

    while (fgets(count_temp, sizeof(count_temp), input_file) != NULL){
        number_of_students++;
    }
    fseek(input_file, 0, 0);
    Stud_array = (Student*)malloc(number_of_students*sizeof(Student));
    Input(Stud_array, input_file, number_of_students);
    Otchislyator_3000(Stud_array, &number_of_students, 2);
    if (number_of_students==1)
    {
     return 1;
    }
    else
        {
            return 0;
        }
}

