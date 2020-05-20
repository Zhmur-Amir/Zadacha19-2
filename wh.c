#include "wh.h"

int Input(Student* Stud_array, FILE* file, int number_of_students){
    Student Tmp_student;
    int temp_group = -1;
    float temp_rating = -0.5;
    char temp_name[256];

    for (int i = 0; i  < number_of_students; i++){
        temp_name[0] = '_';
        temp_rating = -0.5;
        temp_group = -1;
        fscanf(file, "%s", &temp_name);
        fscanf(file, "%d", &temp_group);
        fscanf(file, "%g", &temp_rating);
        if ((temp_name[0] == '_') || (temp_group == -1) || (temp_rating == -0.5)){
            printf("Error: wrong input\n");
            exit(-2);
        }
        Stud_array[i].group = temp_group;
        Stud_array[i].rating = temp_rating;
        strcpy(Stud_array[i].name, temp_name);

    }
    return 0;
}

int Output(Student* Stud_array, int number_of_students){
    for (int i = 0; i < number_of_students; i++){
        printf("%s  %d  %g\n", Stud_array[i].name, Stud_array[i].group, Stud_array[i].rating);
    }
    return 0;
}

int Otchislyator_3000(Student* Stud_array, int* number_of_students, int const expel){
    Student Temp_student;
    for (int i = 0; i < *number_of_students; i++){
        for (int j = 0; j < *number_of_students - 1; j++){
            if (Stud_array[j].rating < Stud_array[j+1].rating){
                Temp_student = Stud_array[j];
                Stud_array[j] = Stud_array[j+1];
                Stud_array[j+1] = Temp_student;
            }
        }
    }
    *number_of_students = *number_of_students - expel;
    Stud_array = (Student*)realloc(Stud_array, *number_of_students*sizeof(Student));
    if (Stud_array==NULL)
    {
        printf("Error! Cannot allocate memory...\n");
        return 1;
    }


    return 0;
}

