#include<stdio.h>   
#include<stdlib.h>  
typedef struct  
{
    int row;
    int col;
    int value;
}term;
void TupleFormat(term t[],int *size)
{
    int rows,cols,nonZero;
    printf("\nNo.of rows and columns: ");  
    scanf("%d %d",&rows,&cols);   
    printf("\nNo.of non zero elements: ");  
    scanf("%d",&nonZero);

    t[0].row=rows;
    t[0].col=cols;
    t[0].value=nonZero;

    for(int i=1;i<=nonZero;i++) 
    {
        printf("Enter row,column,and value for element %d: ",i);
        scanf("%d %d %d",&t[i].row,&t[i].col,&t[i].value);
    }
}
void PrintMatrix(term t[])
{
    int n=t[0].value+1;
    printf("\nRow\tColumn\tValue\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].value);
}
int main()
{
    term m[100];
    printf("\nEnter the non-zero elements for the sparse matrix:-");
    TupleFormat(m,NULL);
    printf("\n3 Tuple Format:- ");
    PrintMatrix(m);
    return 0;
}