#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Employee
{
    char name[50];
    char gender[10];
    char designation[50];
    char department[20];
    float basic_pay;
    float gross_pay;
};

int main()
{
    int n,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    struct Employee *emp;
    emp=(struct Employee *)malloc(n*sizeof(struct Employee));
    for(i=0;i<n;i++)
    {
        printf("Enter Name: ");
        scanf("%s",&emp[i].name);
        printf("Enter Gender(M/F): ");
        scanf("%s",&emp[i].gender);
        printf("Enter Designation: ");
        scanf("%s",&emp[i].designation);
        printf("Enter Department: ");
        scanf("%s",&emp[i].department);
        printf("Enter Basic_pay: ");
        scanf("%f",&emp[i].basic_pay);
    
        float hr=0.25*emp[i].basic_pay;
        float da=0.50*emp[i].basic_pay;
        emp[i].gross_pay = emp[i].basic_pay + hr + da;
    }

    printf("\nGROSS SALARY:-");
    for(i=0;i<n;i++)
    {
        //printf("Name: %d\n",emp[i].name);
        printf("\n%s: %.2f\n",emp[i].name,emp[i].gross_pay);
    }
    free(emp);
    return 0;
}
