#include "grading.h"

char* compute_grade(int marks){
    if(marks >= 90)
        return "O";
    else if(marks >= 85)
        return "A+";
    else if(marks >= 75)
        return "A";
    else if(marks >= 65)
        return "B+";
    else if(marks >= 60)
        return "B";
    else if(marks >= 55)
        return "C";
    else if(marks >= 50)
        return "D";
    else
        return "F";
}
