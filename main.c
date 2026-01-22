#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "student_input.h"
#include "report.h"
int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Provide name of Input file\n");
        return 1;
    }
    FILE *input_file=fopen(argv[1], "r");
    FILE *output_file=fopen("output.txt", "w");
    FILE *error_file =fopen("error.txt", "w");
    if(input_file==NULL|| output_file==NULL||error_file==NULL){
        printf("Error opening file(s)\n");
        return 0;
    }
    int n;
    fscanf(input_file,"%d",&n);
    struct Student *stu[n];
    int valid_count=read_students(input_file,error_file,stu,n);
    fclose(input_file);
    generate_report(stu, valid_count, output_file);
    for(int i=0; i < valid_count; i++)
        free(stu[i]);
    fclose(output_file);
    fclose(error_file);
    return 0;
}
