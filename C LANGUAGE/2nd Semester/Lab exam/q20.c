#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 5
#define MAX_NAME_LENGTH 10
#define MAX_ORDERS 50

typedef struct 
{
    int item_code;
    int quantity;
}Item;
typedef struct 
{
    char name[MAX_NAME_LENGTH+1];
    Item items[MAX_ITEMS];
    int num_items;
}Order;

Order order_list[MAX_ORDERS];
int num_orders=0;

void take_order() 
{
    if(num_orders>=MAX_ORDERS) 
    {
        printf("Maximum number of orders reached.\n");
        return;
    }
    Order new_order;
    
    printf("Enter customer name (up to %d characters): ", MAX_NAME_LENGTH);
    if(scanf("%10s",new_order.name)!=1) 
    {
        printf("Invalid input for name.\n");

        while (getchar()!='\n');
        return;
    }
    printf("Enter the number of items (up to %d): ", MAX_ITEMS);
    if(scanf("%d",&new_order.num_items)!=1 || new_order.num_items<0 || new_order.num_items>MAX_ITEMS) 
    {
        printf("Invalid number of items.\n");

        while (getchar()!='\n');
        return ;
    }
    printf("Enter item codes (1-20) and quantities for each item:\n");
    for(int i=0;i<new_order.num_items;i++) 
    {
        printf("Item %d code: ",i+1);
        if(scanf("%d", &new_order.items[i].item_code)!=1 || new_order.items[i].item_code<1 || new_order.items[i].item_code>20) 
        {
            printf("Invalid item code. Please enter a code between 1 and 20.\n");
        
            while (getchar()!='\n');
            return;
        }
        printf("Item %d quantity: ",i+1);
        if(scanf("%d", &new_order.items[i].quantity)!=1 || new_order.items[i].quantity<=0) 
        {            printf("Invalid quantity.\n");

            while (getchar()!='\n');
            return;
        }
    }
    order_list[num_orders++]=new_order;
    printf("Order added successfully.\n");
}
void print_orders() 
{
    if(num_orders==0) 
    {
        printf("No orders have been placed yet.\n");
        return;
    }

    printf("\n--- All Orders ---\n");
    for(int i=0;i<num_orders;i++) 
    {
        printf("Order %d:\n",i+1);
        printf("Customer Name: %s\n",order_list[i].name);
        printf("Items Ordered:\n");
        for (int j=0;j<order_list[i].num_items;j++) 
            printf("Item Code: %d, Quantity: %d\n",order_list[i].items[j].item_code,order_list[i].items[j].quantity);
        printf("\n");
    }
    printf("------------------\n");
}

int main() 
{
    char choice;

    printf("    Restaurant Order Processing System    \n");

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Take New Order\n");
        printf("2. Print All Orders\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%c",&choice)!=1) 
        {
            printf("Invalid input. Please try again.\n");
            while (getchar()!='\n');
            continue;
        }
        switch(choice) 
        {
            case '1':
                take_order();
                break;
            case '2':
                print_orders();
                break;
            case 'e':
            case 'E':
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}