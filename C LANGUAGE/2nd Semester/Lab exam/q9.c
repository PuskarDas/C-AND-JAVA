#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct books
{
    char title[200];
    char author[100];
    char publication[100];
    int price;
};
int main()
{
    int n,max=0,min=30000;
    char a1[30],t1[30],p1[30];
    char a2[30],t2[30],p2[30];
    printf("\nEnter no.of Books:");
    scanf("%d",&n);
    struct books *b;
    b=(struct book *)malloc(n*sizeof(struct books));

    //struct books b[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter title:");
        scanf("%s",b[i].title);
        printf("\nEnter author:");
        scanf("%s",b[i].author);
        printf("\nEnter publication:");
        scanf("%s",b[i].publication);
        printf("\nEnter price:");
        scanf("%d",b[i].price);
        printf("\n");
    }
    for(int i=1;i<n;i++)
    {
        if(b->price>max)
        {
            max=i;
            strcpy(t1,b->title);
            strcpy(a1,b->author);
            strcpy(p1,b->publication);
        }
        if(b->price<min)
        {
            min=i;
            strcpy(t2,b->title);
            strcpy(a2,b->author);
            strcpy(p2,b->publication);
        }
    }
    
    printf("\nMost Expensive Book:-\n");
    printf("Title: %s\n",t1);
    printf("Author: %s\n",a1);
    printf("Publication: %s\n",p1);
    printf("Price: %d\n",max);

    printf("\nLowest Priced Book:-\n");
    printf("Title: %s\n",t2);
    printf("Author: %s\n",a2);
    printf("Publication: %s\n",p2);
    printf("Price: %d\n",min);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book 
{
    char title[100];
    char author[100];
    char publication[100];
    float price;
};

int main() 
{
    int n,i,maxIndex=0,minIndex=0;

    printf("Enter the number of books:");
    scanf("%d",&n);
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));

    if (books == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
    {
        printf("\nEnter details for book %d:\n", i + 1);

        printf("Title: ");
        scanf(" %[^\n]%*c", books[i].title);

        printf("Author: ");
        scanf(" %[^\n]%*c", books[i].author);

        printf("Publication: ");
        scanf(" %[^\n]%*c", books[i].publication);

        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    for (i = 1; i < n; i++) 
    {
        if (books[i].price > books[maxIndex].price) 
        {
            maxIndex = i;
        }
        if (books[i].price < books[minIndex].price) 
        {
            minIndex = i;
        }
    }

    printf("\nMost Expensive Book:\n");
    printf("Title: %s\n", books[maxIndex].title);
    printf("Author: %s\n", books[maxIndex].author);
    printf("Publication: %s\n", books[maxIndex].publication);
    printf("Price: %.2f\n", books[maxIndex].price);

    printf("\nLowest Priced Book:\n");
    printf("Title: %s\n", books[minIndex].title);
    printf("Author: %s\n", books[minIndex].author);
    printf("Publication: %s\n", books[minIndex].publication);
    printf("Price: %.2f\n", books[minIndex].price);

    free(books);
    return 0;
}*/
    
