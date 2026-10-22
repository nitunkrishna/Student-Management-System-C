#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void ViewAll()
{
    struct Student s;

    FILE *fp=fopen("student.dat", "rb");
    if(!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\tAll Students\n");
    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        printf("Name.        : %s\n", s.name);
        printf("Father's Name: %s\n", s.father_name);
        printf("Mother's Name: %s\n", s.mother_name);
        printf("ID.          : %d\n", s.id);
        printf("Session.     : %s\n", s.session);
        printf("Department.  : %s\n", s.department);
        printf("E-mail.      : %s\n", s.email);
        printf("Phone Number : %s\n", s.phone);
        printf("CGPA.        : %.2f\n", s.cgpa);
    }
    fclose(fp);
}