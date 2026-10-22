#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void Search()
{
    struct Student s;
    int search_id, flag=0;

    FILE *fp=fopen("student.dat", "rb");
    if(!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    int c;
    do
    {
        printf("Enter Student ID: ");
        if(scanf("%d", &search_id)!=1) search_id = -1;
        while((c=getchar())!='\n' && c!=EOF);
        if(search_id<=0) printf("Invalid ID! Try again.\n");
    } while(search_id<=0);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id==search_id)
        {
            flag=1;
            printf("\nStudent Found!\n");
            printf("Name.        : %s\n", s.name);
            printf("Father's Name: %s\n", s.father_name);
            printf("Mother's Name: %s\n", s.mother_name);
            printf("ID.          : %d\n", s.id);
            printf("Session.     : %s\n", s.session);
            printf("Department.  : %s\n", s.department);
            printf("E-mail.      : %s\n", s.email);
            printf("Phone Number : %s\n", s.phone);
            printf("CGPA.        : %.2f\n", s.cgpa);
            break;
        }
    }

    if(flag==0)
        printf("Student %d not found.\n", search_id);

    fclose(fp);
}