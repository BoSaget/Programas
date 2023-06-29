#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int* calificaciones, int estudiantes, char genero)
{
    int inicio;
    int suma;

    inicio = 0;
    suma = 0;

    if(genero == 'g')
    {
        inicio = 1;
    }

    for(int i = inicio; i < estudiantes; i+=2)
    {
        suma = calificaciones[i] + suma;
    }

return suma;
}


int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}