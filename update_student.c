#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void Update()
{
    struct Student s;
    int update_id, flag=0;
    int mail_update, num_update, cgpa_update;

    FILE *fp=fopen("student.dat", "rb+");
    if(!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID to update: ");
    scanf("%d", &update_id);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id==update_id)
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

            printf("\n\nUpdating begins here\n\n");

            printf("Update Student e-mail?\n1. YES\n2. NO\n");
            scanf("%d", &mail_update);
            getchar();
            if(mail_update==1)
            {
                printf("Update Student e-mail: ");
                fgets(s.email, sizeof(s.email), stdin);
                s.email[strcspn(s.email, "\n")]=0;
            }

            printf("Update Student Phone Number?\n1. YES\n2. NO\n");
            scanf("%d", &num_update);
            getchar();
            if(num_update==1)
            {
                printf("Update Student Phone Number: ");
                fgets(s.phone, sizeof(s.phone), stdin);
                s.phone[strcspn(s.phone, "\n")]=0;
            }

            printf("Update Student CGPA?\n1. YES\n2. NO\n");
            scanf("%d", &cgpa_update);
            getchar();
            if(cgpa_update==1)
            {
                printf("Enter CGPA: ");
                scanf("%f", &s.cgpa);
                getchar();
            }

            if(fseek(fp, -(long)sizeof(s), SEEK_CUR)==0)
            {
                if(fwrite(&s, sizeof(s), 1, fp)==1)
                    printf("Student updated successfully!\n");
                else
                    printf("Error updating student!\n");
            }
            else
                printf("Error seeking student record!\n");
            break;
        }
    }

    if(flag==0)
        printf("Student %d not found.\n", update_id);

    fclose(fp);
}