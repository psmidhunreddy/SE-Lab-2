#include <string.h>
#include "report.h"
#include "grading.h"

void generate_report(struct Student *stu[], int valid_count, FILE *output_file){
    int grade_count[8] = {0};
    float highest = 0, lowest = 1000, total_percentage = 0;

    fprintf(output_file,"Student ID\tName\tSubject 1\tSubject 2\tSubject 3\tSubject 4\tSubject 5\tTotal Marks\tPercentage\tCGPA\n");
    fprintf(output_file,"--------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < valid_count; i++){
        fprintf(output_file, "%s\t%s\t", stu[i]->student_id, stu[i]->student_name);

        int student_total = 0;
        for(int j = 0; j < 5; j++){
            int marks = stu[i]->minor_marks[j] + stu[i]->major_marks[j];
            student_total += marks;
            char *grade = compute_grade(marks);
            fprintf(output_file, "%s\t\t", grade);
            if(strcmp(grade,"O")==0) grade_count[0]++;
            else if(strcmp(grade,"A+")==0) grade_count[1]++;
            else if(strcmp(grade,"A")==0) grade_count[2]++;
            else if(strcmp(grade,"B+")==0) grade_count[3]++;
            else if(strcmp(grade,"B")==0) grade_count[4]++;
            else if(strcmp(grade,"C")==0) grade_count[5]++;
            else if(strcmp(grade,"D")==0) grade_count[6]++;
            else grade_count[7]++;
        }

        stu[i]->total_marks = student_total;
        float percentage = student_total / 5.0;
        total_percentage += percentage;

        if(percentage > highest) highest = percentage;
        if(percentage < lowest) lowest = percentage;

        fprintf(output_file, "%d\t\t%.2f\t\t%.2f\n",student_total, percentage, percentage / 10.0);
    }

    fprintf(output_file, "\nClass Average Percentage: %.2f\n",valid_count ? total_percentage / valid_count : 0);
    fprintf(output_file, "Highest Percentage: %.2f\n", highest);
    fprintf(output_file, "Lowest Percentage: %.2f\n", lowest);

    fprintf(output_file,"\nDistribution of Grades:\n""O: %d\nA+: %d\nA: %d\nB+: %d\nB: %d\nC: %d\nD: %d\nF: %d\n",
        grade_count[0], grade_count[1], grade_count[2], grade_count[3],grade_count[4], grade_count[5], grade_count[6], grade_count[7]);
}
