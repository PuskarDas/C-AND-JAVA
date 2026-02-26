#include <stdio.h>
#include <stdlib.h>
struct Employee 
{
    int id;
    char name[100];
    int salary;
};
int main()
{
    int n,max=0;
    printf("\nEnter no.of employees:");
    scanf("%d",&n);
    struct Employee *emp;
    emp=(struct Employee *)malloc(n*sizeof(struct Employee));

    for(int i=0;i<n;i++)
    {
        printf("\nEnter id:");
        scanf("%d",emp[i].id);
        printf("Enter Name:");
        scanf("%s",emp[i].name);
        printf("Enter salary:");
        scanf("%d",emp[i].salary);
        fflush(stdin);
    }
    for(int i=0;i<n;i++)
    {
        if(emp[i].salary>emp[max].salary)
            max=i;
    }
    
    printf("\nHighest salaried employee:-\n");
    printf("ID: %d\n", emp[max].id);
    printf("Name: %s\n", emp[max].name);
    printf("Salary: %d\n", emp[max].salary);
    return 0;
}

