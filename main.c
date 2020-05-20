#include "wh.h"

int main(void){
    FILE* input_file;
    Student* Stud_array;
    int number_of_students = 0;
    char count_temp[512];
    int test, expel, m;

    input_file = fopen("data.txt", "r");
    if (!input_file){
        printf("Error: cannot open file\n");
        exit(-1);
    }

    while (fgets(count_temp, sizeof(count_temp), input_file) != NULL){
        number_of_students++;
    }
    fseek(input_file, 0, 0);
    Stud_array = (Student*)malloc(number_of_students*sizeof(Student));
    if (Stud_array==NULL)
    {
        printf("Error! Cannot allocate memory...\n");
        return 1;
    }

    Input(Stud_array, input_file, number_of_students);
    Output(Stud_array, number_of_students);
    printf("\n---------\n\n");
    printf("Enter number of students to expel: ");
    if ((scanf("%d", &expel) != 1) || (expel > number_of_students) || expel<0){
        printf("Error: wrong input\n");
        exit(-2);
    }
    printf("\n");
    m=Otchislyator_3000(Stud_array, &number_of_students, expel);
    if(m!=0)
        {
            return 1;
        }
    if (number_of_students == 0){
        printf("All students were expeled :( \n");
    }
    Output(Stud_array, number_of_students);
    free(Stud_array);
    printf("\n---------\n\n");
    printf("Autotest:\n");
    test=Autotest();
    if (test==1)
        {
            printf("Autotest passed... Respect+\n");
        }
    else
        {
            printf("Autotest failed\n");
        }
    return 0;

}
