#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

int main()
{
    int n,c;
    while(1)
    {
        printf("1. Add Student\n");
        printf("2. View All\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        do
        {
            printf("Enter your choice (1-6): ");
            if(scanf("%d", &n)!=1) n=0;
            while((c=getchar())!='\n' && c!=EOF);
            if(n<1 || n>6) printf("Invalid choice! Try again.\n");
        } while(n<1 || n>6);
        printf("\n");
        switch(n)
        {
            case 1:
                AddStudent();
                break;
            case 2:
                ViewAll();
                break;
            case 3:
                Search();
                break;
            case 4:
                Update();
                break;
            case 5:
                Delete();
                break;
            case 6:
                printf("Quiting Student Management System\n");
                printf("------------THANK YOU------------\n");
                exit(0);
                break;
            default: 
                printf("Enter valid number\n");
        }
    }
}