#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, c;

void print_student_information(char names[][20], float grades[], int ages[], int i);

int main () {
    // ---- function call stack ----
    printf("---- Function call stack ----\n");

    char names[3][20] = {
        "Alice",
        "Bob",
        "Eve"
    };
    float grades[3] = {4.0, 2.5, 3.5};
    int ages[3] = {22, 19, 20};
    int student_count = sizeof(ages) / sizeof(int);

    print_student_information(names, grades, ages, student_count - 1);

    // ---- malloc ----
    printf("---- Malloc ----\n");

    int *A = malloc(sizeof(int) * 5);
    int *B = malloc(sizeof(int) * 5);
    int *C = malloc(sizeof(int) * 5);

    printf("A's addr: %p\n", A);
    printf("B's addr: %p\n", B);
    printf("C's addr: %p\n", C); 

    // ---- global variables ----
    printf("---- Global variables ----\n");
 
    printf("a's addr: %p\n", &a);
    printf("b's addr: %p\n", &b);
    printf("c's addr: %p\n", &c); 

    // ---- free memory ----
    free(A);
    free(B);
    free(C);

    return 0;
}

void print_student_information(char names[][20], float grades[], int ages[], int i) {
    if (i == -1) return ;

    char name[20];
    strcpy(name, names[i]);
    float grade = grades[i];
    int age = ages[i];

    printf("name: %s, grade: %.1f, age: %d\n", name, grade, age);
    printf("name's addr: %p\n", &name);
    printf("grade's addr: %p\n", &grade); 
    printf("age's addr: %p\n", &age); 

    print_student_information(names , grades, ages, i - 1);
}