#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "student.h"

int read_students(FILE *input_file,FILE *error_file,struct Student *stu[],int max_students);

#endif
