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
        printf("Enter row, column and value for element %d: ",i);
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
void AddMatrtix(term s1[],term s2[],term result[])
{
    int i=1,j=1,k=1;
    result[0].row=s1[0].row;
    result[0].col=s1[0].col;

    while(i<=s1[0].value && j<=s2[0].value) 
    {
        if(s1[i].row<s2[j].row || (s1[i].row==s2[j].row && s1[i].col<s2[j].col)) 
            result[k++]=s1[i++];
        else if(s2[j].row<s1[i].row || (s2[j].row==s1[i].row && s2[j].col<s1[i].col))
            result[k++]=s2[j++];
        else               
        {
            result[k].row=s1[i].row;
            result[k].col=s1[i].col;
            result[k].value=s1[i].value+s2[j].value;
            k++;
            i++;
            j++;
        }
    }
    while(i<=s1[0].value)          // Copy remaining elements from sm1, if any
        result[k++]=s1[i++];
    while(j<=s2[0].value)         // Copy remaining elements from sm2, if any
        result[k++]=s2[j++];

    result[0].value=k-1;  
}
int main()
{
    term m1[100],m2[100],result[200];
    printf("Enter details for the first sparse matrix:- ");
    TupleFormat(m1,NULL);
    printf("\nEnter details for the second sparse matrix:- ");
    TupleFormat(m2,NULL);

    printf("\nFirst Sparse Matrix:- \n");
    PrintMatrix(m1);
    printf("\nSecond Sparse Matrix:- \n");
    PrintMatrix(m2);

    AddMatrtix(m1,m2,result);

    printf("\nResultant Sparse Matrix(Addition):- \n");
    PrintMatrix(result);
    return 0;
}