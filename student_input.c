#include <stdlib.h>
#include "student_input.h"
#include "validation.h"
#include "file_utils.h"

int read_students(FILE *input_file,FILE *error_file,struct Student *stu[],int max_students)
{
    int valid_count = 0;
    for(int i = 0; i < max_students; i++){
        stu[valid_count] = malloc(sizeof(struct Student));
        if(stu[valid_count] == NULL)
            break;
        fscanf(input_file, "%s", stu[valid_count]->student_id);
        if(!validate_studentID(stu[valid_count]->student_id)){
            fprintf(error_file, "Student ID %s is Invalid\n",stu[valid_count]->student_id);
            free(stu[valid_count]);
            skip_line(input_file);
            continue;
        }

        if(is_duplicate(stu, valid_count, stu[valid_count]->student_id)){
            fprintf(error_file,"Duplicate Student ID %s found (First occurrence considered)\n",stu[valid_count]->student_id);
            free(stu[valid_count]);
            skip_line(input_file);
            continue;
        }

        fscanf(input_file, "%s", stu[valid_count]->student_name);

        if(!validate_name(stu[valid_count]->student_name)){
            fprintf(error_file, "Student Name %s is Invalid\n",stu[valid_count]->student_name);
            free(stu[valid_count]);
            skip_line(input_file);
            continue;
        }

        int mark_error = 0;
        stu[valid_count]->total_marks = 0;

        for(int j = 0; j < 5; j++){
            fscanf(input_file, "%d %d",&stu[valid_count]->minor_marks[j],&stu[valid_count]->major_marks[j]);
            if(!valid_marks(stu[valid_count]->minor_marks[j],stu[valid_count]->major_marks[j])){
                fprintf(error_file,"Marks out of range for Student ID: %s\n",stu[valid_count]->student_id);
                mark_error = 1;
                break;
            }
        }

        if(mark_error){
            free(stu[valid_count]);
            skip_line(input_file);
            continue;
        }
        valid_count++;
    }
    return valid_count;
}
