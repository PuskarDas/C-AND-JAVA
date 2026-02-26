#include <stdio.h>
struct Student
{
    int rollno;
    char name[50];
    char gender;
    int m1,m2,m3;
    int total;
};
int main()
{
    int n;
    printf("\nEnter the number of students:");
    scanf("%d",&n);

    struct Student stud[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the student %d data",i+1);
        printf("\nEnter name:");
        scanf("%s",&stud[i].name);
        printf("\nEnter Roll No:");
        scanf("%d",&stud[i].rollno);
        printf("\nEnter Gender:");
        stud[i].gender=getch();
        printf("\nMarks in SUBJECT 1:");
        scanf("%d",&stud[i].m1);
        printf("\nMarks in SUBJECT 2:");
        scanf("%d",&stud[i].m2);
        printf("\nMarks in SUBJECT 3:");
        scanf("%d",&stud[i].m3);
        stud[i].total=stud[i].m1+stud[i].m2+stud[i].m3;
        printf("\n");
    }
    printf("\nRollno.\tName\tGender\tSub1\tSub2\tSub3\tTotal");
    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("%d\t",stud[i].rollno);
        printf("%s\t",stud[i].name);
        printf("%c\t",stud[i].gender);
        printf("%d\t",stud[i].m1);
        printf("%d\t",stud[i].m2);
        printf("%d\t",stud[i].m3);
        printf("%d\t",stud[i].total);
    } 

    printf("\n\nStudent failed in Sub1 is:");
    for(int i=0;i<n;i++)
    {
        if(stud[i].m1<40)
        {
            printf("%s",stud[i].name);
            printf("\t");
        }        
    }
    printf("\n\nStudent failed in Sub2 is:");
    for(int i=0;i<n;i++)
    {
        if(stud[i].m2<40)
        {
            printf("%s",stud[i].name);
            printf("\t");
        }        
    }
    printf("\n\nStudent failed in Sub3 is:");
    for(int i=0;i<n;i++)
    {
        if(stud[i].m3<40)
        {
            printf("%s",stud[i].name);
            printf("\t");
        }        
    }
    return 0;
}