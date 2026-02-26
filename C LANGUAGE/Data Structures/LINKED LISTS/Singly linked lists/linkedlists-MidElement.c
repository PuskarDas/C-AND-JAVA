#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* isMiddle(struct Node* head) 
{
    if (head == NULL) 
        return NULL;
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct Node* newNode(int data) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head;
    head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(10);
    head->next->next->next = newNode(42);
    head->next->next->next->next = newNode(7);

    printf("Linked list: ");
    printList(head);
    
    struct Node* middle = isMiddle(head);
    if (middle != NULL) 
        printf("Middle element: %d\n", middle->data);
    else 
        printf("List is empty.\n");
    return 0;
}