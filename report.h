#ifndef REPORT_H
#define REPORT_H

#include "student.h"
#include <stdio.h>

void generate_report(struct Student *stu[], int valid_count, FILE *output_file);

#endif
