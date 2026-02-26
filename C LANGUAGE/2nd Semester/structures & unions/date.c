#include <stdio.h>
typedef struct DATE
{
    int dd,mm,yy;
};

void input(struct DATE *d)
{
    fflush(stdin);
    printf("\nEnter day:");
    scanf("%d",d->dd);
    printf("\nEnter month:");
    scanf("%d",d->mm);
    fflush(stdin);
    printf("\nEnter year:");
    scanf("%d",d->yy);
}

void display(struct DATE *d)
{
    printf("\nEntered date is %d/%d/%d",d->dd,d->mm,d->yy);
}
int main()
{
    struct DATE dob,today;
    printf("\nEnter today's date:-");
    input(&today);
    fflush(stdin);
    printf("\nEnter your DOB:-");
    input(&dob);
    return 0;
}