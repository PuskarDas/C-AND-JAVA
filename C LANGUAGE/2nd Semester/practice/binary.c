#include <stdio.h>
void findBinary(int num,int binary[]) 
{
    int i=0;
    while(num>0) 
    {
        binary[i]=num%2;
        num=num/2;
        i++;
    }

    for(int j=i-1;j>=0;j--) 
    {
        printf("%d",binary[j]);
    }
    printf("\n");
}

int main() 
{
    int num;
    int binary[32];
    printf("Enter a number: ");
    scanf("%d", &num);

    findBinary(num, binary);
    return 0;
}
