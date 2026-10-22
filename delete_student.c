#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void Delete()
{
    struct Student s;
    int delete_id, flag=0;

    FILE *fp=fopen("student.dat", "rb");
    if(!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    FILE *temp=fopen("temp.dat", "wb");
    if(!temp)
    {
        printf("Error opening file!\n");
        fclose(fp);
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &delete_id);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id==delete_id)
        {
            flag=1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if(flag==0)
    {
        printf("Student %d not found.\n", delete_id);
        remove("temp.dat");
    }
    else
    {
        if(remove("student.dat")!=0)
        {
            printf("Error removing original file!\n");
            return;
        }
        if(rename("temp.dat", "student.dat")!=0)
        {
            printf("Error renaming temporary file!\n");
            return;
        }
        printf("Student with ID %d deleted successfully!\n", delete_id);
    }
}