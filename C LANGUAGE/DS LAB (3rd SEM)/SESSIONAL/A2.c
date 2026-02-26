#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* interleaveLists(struct Node* head1, struct Node* head2) 
{
    struct Node* dummy = createNode(0); 
    struct Node* tail = dummy;

    while (head1 && head2) 
    {
        tail->next = head1;
        head1 = head1->next;
        tail = tail->next;

        tail->next = head2;
        head2 = head2->next;
        tail = tail->next;
    }

    struct Node* result = dummy->next;
    free(dummy);
    return result;
}
void printList(struct Node* head) 
{
    while (head) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    struct Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    struct Node* merged = interleaveLists(head1, head2);
    printList(merged);
    return 0;
}