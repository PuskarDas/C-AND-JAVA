#include <stdio.h>
void display(int num,int sub,int marks[num][sub])
{
    int *ptr=&marks[0][0];
    printf("\nMARKS TABLE:-");
    for(int i=0;i<num;i++)
    {
        printf("\nStudent %d:-",i+1);
        for (int j=0;j<sub;j++) 
            printf("%d ",*ptr++);
    }
}

void average(int num,int sub,int marks[num][sub])
{
    int *ptr=&marks[0][0];
    printf("Average Marks of Each Student:-\n");
    for (int i=0; i<num;i++) 
    {
        int sum=0;
        float average;
        for (int j=0;j<sub;j++) 
            sum+= *ptr++;
        average=(float)sum/sub;
        printf("Student %d:-%.2f\n ",i+1,average);
    }
}

int main()
{
    int marks,n,s;
    printf("\nEnter number of students: ");
    scanf("%d",&n);
    printf("\nEnter number of subjects: ");
    scanf("%d",&s);

    int m[n][s];
    printf("\nEnter marks for each student:-\n");
    for (int i=0;i<n;i++) 
    {
        printf("\nStudent %d:-",i+1);
        for (int j=0;j<s;j++) 
        {
            printf("\nSubject %d: ",j+1);
            scanf("%d",&m[i][j]);
        }
    }

    display(n,s,m);
    average(n,s,m);
    return 0;
}