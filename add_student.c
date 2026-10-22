#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void AddStudent()
{
    struct Student s;

    FILE *fp=fopen("student.dat", "ab");
    if(!fp)
    {
        printf("Error opening file!\n");
        return;
    }
    int c;

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")]=0;
    printf("Enter Student's Father Name: ");
    fgets(s.father_name, sizeof(s.father_name), stdin);
    s.father_name[strcspn(s.father_name, "\n")]=0;
    printf("Enter Student's Mother Name: ");
    fgets(s.mother_name, sizeof(s.mother_name), stdin);
    s.mother_name[strcspn(s.mother_name, "\n")]=0;
    printf("Enter id: ");
    scanf("%d", &s.id);
    getchar();
    if(IDExists(s.id))
    {
        printf("Student ID already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter Session: ");
    fgets(s.session, sizeof(s.session), stdin);
    s.session[strcspn(s.session, "\n")]=0;
    printf("Enter Department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")]=0;
    printf("Enter Student e-mail: ");
    fgets(s.email, sizeof(s.email), stdin);
    s.email[strcspn(s.email, "\n")]=0;
    printf("Enter Student Phone Number: ");
    fgets(s.phone, sizeof(s.phone), stdin);
    s.phone[strcspn(s.phone, "\n")]=0;
    do
    {
        printf("Enter CGPA (0.00 - 4.00): ");
        if(scanf("%f", &s.cgpa)!=1) s.cgpa=-1;
        while((c=getchar())!='\n' && c!=EOF);
        if(s.cgpa<0.0 || s.cgpa>4.0) printf("Invalid CGPA! Try again.\n");
    } while(s.cgpa<0.0 || s.cgpa>4.0);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

int IDExists(int id)
{
    struct Student s;
    FILE *fp=fopen("student.dat", "rb");
    if(fp==NULL) return 0;
    while(fread(&s, sizeof(s), 1, fp)==1)
    {
        if(s.id==id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}