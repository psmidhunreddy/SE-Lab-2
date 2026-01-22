#ifndef VALIDATION_H
#define VALIDATION_H
#include "student.h"
int validate_studentID(char id[]);
int is_duplicate(struct Student *stu[], int count, char id[]);
int validate_name(char name[]);
int valid_marks(int minor,int major);
#endif
