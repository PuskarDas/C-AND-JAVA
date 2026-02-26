#include <stdio.h>
void ADDMATRIX(int r,int c , int p[r][c], int q[r][c], int sum[r][c])
{
    for(int i=0;i<r;i++)   /*sum of both arrays*/
    {
        for(int j=0;j<c;j++)
        {
            sum[i][j]=p[i][j]+q[i][j];
        }
    }
}
void main()
{
    int m,n;
    printf("\nEnter no.of rows:");
    scanf("%d",&m);
    printf("\nEnter no.of columns:");
    scanf("%d",&n);
    int a[m][n],b[m][n],sum[m][n];;
    for(int i=0;i<m;i++)       /*input first array*/
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter 1st array elements: ");
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<m;i++)   /*input second array*/
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter 2nd array elements: ");
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nThe sum of arrays is:\n");
    ADDMATRIX(m,n,a,b,sum);
    for(int i=0;i<m;i++)   
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",sum);  
        }
        printf("\n");
    }
}

/*#include <stdio.h>
void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() 
{
    int rows, cols;
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    addMatrix(rows, cols, matrix1, matrix2, result);

    printf("\nResultant Matrix after Addition:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/