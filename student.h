#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    char name[50];
    char father_name[50];
    char mother_name[50];
    int id;
    char session[20];
    char department[30];
    char email[100];
    char phone[20];
    float cgpa;
};

void AddStudent();
int IDExists(int id);
void ViewAll();
void Search();
void Update();
void Delete();

#endif