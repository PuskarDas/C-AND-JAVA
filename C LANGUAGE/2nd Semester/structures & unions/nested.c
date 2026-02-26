#include <stdio.h>
struct address
{
    char city[20];
    int pin;
    char phone[12];
}add;
struct employee
{
   char name[20];
   struct address add;
}emp;

void main()
{
    struct employee emp;
    printf("\nEnter name:");
    gets(emp.name);
    printf("\nEnter city:");
    gets(emp.add.city);
    printf("\nEnter pin:");
    scanf("%d",&emp.add.pin);
    fflush(stdin);
    printf("\nEnter phone:");
    gets(emp.add.phone);
    printf("\n");

    printf("\nThe employee name is %s",emp.name);
    printf("\nThe employee city is %s",emp.add.city);
    printf("\nThe city PIN is %d",emp.add.pin);
    printf("\nThe employee phone is %s",emp.add.phone);
}
