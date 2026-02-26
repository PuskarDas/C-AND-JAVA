#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter gift card values: ");
    scanf("%d",&n);
    int gift[n];
    printf("\nEnter %d gift card values: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&gift[i]);
    }                                                         
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //if(!used[i] && !used[j])
            {
                int sum=gift[i]+gift[j];
                for(int k=i;k<n;k++)
                {
                    if(k!=i && k!=j && gift[k]==sum)
                    {
                        count++;
                        printf("\n%d->%d",i,gift[i]);
                        printf("\n%d->%d",j,gift[j]);
                        printf("\n%d->%d",k,gift[k]);
                        printf("\n");
                    }
                }
            }
        }
    }
    printf("\nNo.of valid card combinations: %d",count/2);
    return 0;
}