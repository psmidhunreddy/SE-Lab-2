#include <string.h>
#include <ctype.h>
#include "validation.h"

int validate_studentID(char id[]){
    for(int i = 0; id[i] != '\0'; i++){
        if(!isalnum(id[i]))
            return 0;
    }
    return 1;
}

int valid_marks(int minor,int major){
    if (minor<0 ||minor>40)
        return 0;
    if(major<0 ||major>60)
        return 0;
    return 1;
}
int is_duplicate(struct Student *stu[], int count, char id[]){
    for(int i = 0; i < count; i++){
        if(strcmp(stu[i]->student_id, id) == 0)
            return 1;
    }
    return 0;
}

int validate_name(char name[]){
    for(int i = 0; name[i] != '\0'; i++){
        if(!isalpha(name[i]))
            return 0;
    }
    return 1;
}
