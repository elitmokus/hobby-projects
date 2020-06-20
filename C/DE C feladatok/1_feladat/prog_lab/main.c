#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void first_exercise() {
    int a , b;
    printf("Integer value of variable a: ");
    scanf("%d", &a);
    printf("Integer value of variable b: ");
    scanf("%d", &b);
    if(a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("Value of variable a = %d \nValue of variable b = %d", a, b);
}

void second_exercise() {
    int max_point, earned_point;
    printf("Set the max point for the exam: ");
    scanf("%d", &max_point);
    printf("Set the earned point for the exam: ");
    scanf("%d", &earned_point);
    int result = (100*earned_point) / max_point;
    printf("Result in percentage: %d\n", result);
    if(result >= 60) {
        printf("Exam passed!");
    } else {
        printf("Exam failed!");
    }
}

void third_exercise() {
    int year;
    printf("Set the year: ");
    scanf("%d", &year);
    if( (year%4==0 && year%100!=0) || year%400==0) {
        printf("%d is leap year!", year);
    } else {
        printf("%d is not leap year!", year);
    }
}

void fourth_exercise() {
    //beállítja a lokalitásnak megfelelõ nyelvet
    setlocale(LC_ALL, "");
    int year;
    printf("Adj meg egy évszámot: ");
    scanf("%d", &year);
    if( (year%4==0 && year%100!=0) || year%400==0) {
        printf("%d szökõév!", year);
    } else {
        printf("%d nem szökõév!", year);
    }
}

void fifth_exercise() {
    float a,b,c;
    printf("Set the length of a:");
    scanf("%f", &a);
    printf("Set the length of b:");
    scanf("%ff", &b);
    printf("Set the length of c:");
    scanf("%f", &c);
    if(a+b > c && a+c > b && b+c > a) {
        printf("You can draw this triangle!\n");
        float s = (a+b+c)/2; // semiperimeter
        float area = sqrt(s*(s-a)*(s-b)*(s-c)); // Heron's formula
        printf("Area of the given triangle: %.2f", area);
    } else {
        printf("You can't draw this triangle!");
    }
}

void sixth_exercise() {
    setlocale(LC_ALL, "");
    int point_of_exam;
    printf("Írd be a vizsgán szerzett pontot: ");
    scanf("%d", &point_of_exam);
    if(point_of_exam <= 42) {
        printf("Elégtelen");
    } else if (point_of_exam <= 57) {
        printf("Elégséges");
    } else if (point_of_exam <= 72) {
        printf("Közepes");
    } else if (point_of_exam <= 87) {
        printf("Jó");
    } else if (point_of_exam <= 100) {
        printf("Jeles");
    }
}

void seventh_exercise() {
    //a*x^2 + b*x + c = 0
    //D = b^2 - 4*a*c
    //result1,2 = (-b +- sqrt(D)) / 2

    float a,b,c;
    printf("Set the value of a: ");
    scanf("%f", &a);
    printf("Set the value of b: ");
    scanf("%f", &b);
    printf("Set the value of c: ");
    scanf("%f", &c);

    float D = b*b - 4*a*c;
    if(D >= 0) {
        float result_1 = (-1*b + sqrt(D))/2;
        float result_2 = (-1*b - sqrt(D))/2;
        printf("Result of the equation:\nX1: %f\nX2: %f", result_1, result_2);
    } else {
        printf("There is no result for this equation.");
    }
}

void eighth_exercise() {
    int number_of_month;
    printf("Enter the number of month: ");
    scanf("%d", &number_of_month);
    switch(number_of_month) {
        case 1 : printf("January"); break;
        case 2 : printf("February"); break;
        case 3 : printf("March"); break;
        case 4 : printf("April"); break;
        case 5 : printf("May"); break;
        case 6 : printf("June"); break;
        case 7 : printf("Jule"); break;
        case 8 : printf("August"); break;
        case 9 : printf("September"); break;
        case 10 : printf("October"); break;
        case 11 : printf("November"); break;
        case 12 : printf("December"); break;
        default : printf("There is no month with this number.");
    }
}

int main()
{
    //first_exercise();
    //second_exercise();
    //third_exercise();
    //fourth_exercise();
    //fifth_exercise();
    //sixth_exercise();
    //seventh_exercise();
    eighth_exercise();
    return 0;
}
