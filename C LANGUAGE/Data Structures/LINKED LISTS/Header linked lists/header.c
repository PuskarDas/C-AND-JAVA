#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int newData);

// Inserts a node into the linked list.
void insert(struct Node* header, int x) 
{

    struct Node* curr = header;
    while (curr->next !=NULL)
        curr = curr->next;

    struct Node* newNode = createNode(x);
    curr->next = newNode;
}

void printList(struct Node* header) 
{
    struct Node* curr = header->next;
    while (curr != NULL) 
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node* createNode(int newData) {
    struct Node* node = 
    (struct Node*)malloc(sizeof(struct Node));
    node->data = newData;
    node->next = NULL;
    return node;
}
int main() 
{
    // Create a hard-coded header linked list:
    // header -> 1 -> 2 -> 3 -> 4
    struct Node* header = createNode(0);
    insert(header, 1);
    insert(header, 2);
    insert(header, 3);
    insert(header, 4);

    printList(header);
    return 0;
}