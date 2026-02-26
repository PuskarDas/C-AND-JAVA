/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

bool compareLists(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

bool isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head, *prev_slow = head;
    struct Node *second_half, *midnode = NULL;
    bool result = true;

    if (head != NULL && head->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            midnode = slow;
            slow = slow->next;
        }

        second_half = slow;
        prev_slow->next = NULL;
        reverse(&second_half);
        result = compareLists(head, second_half);
        reverse(&second_half);

        if (midnode != NULL) {
            prev_slow->next = midnode;
            midnode->next = second_half;
        } else {
            prev_slow->next = second_half;
        }
    }
    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 1);

    printList(head);
    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int a;
    struct Node *next;
};
struct Node *start;
struct Node *start1;
struct Node *reverse;
void Addfront(struct Node **start,int x)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->a=x;
    newNode->next=*start;
    *start=newNode;
}
struct Node *Reverse(struct Node *st1)
{
    struct Node *rev=NULL;
    while(st1!=NULL)
    {
        
        struct Node *newNode;
        newNode=malloc(sizeof(struct Node));
        newNode->a=st1->a;
        newNode->next=rev;
        rev=newNode;
        st1=st1->next;
    }
    return rev;
}
bool Compare(struct Node *s1, struct Node *s2)
{
    bool same=true;
    while(s1!=NULL && s2!=NULL)
    {
        if(s1->a!=s2->a)
        {
            same=false;
        }
        s1=s1->next;
        s2=s2->next;
    }
    if(s1!=NULL || s2!=NULL)
    {
        same=false;
        printf("\nDifferent length");
    }
    return same;
}
void Printlist(struct Node *st)
{
    int c=0;
    while(st!=NULL)
    {
        printf("\n%d",st->a);
        st=st->next;
        c++;
    }
    //printf("\nNo.of nodes: %d",c);
}

int main()
{
    bool x;
    struct Node *list1=NULL;
    struct Node *list2=NULL;    
    Addfront(&list1,1);
    Addfront(&list1,2);
    Addfront(&list1,4);
    Addfront(&list1,2);
    Addfront(&list1,1);

    list2=Reverse(list1);
    Printlist(list2);
    x=Compare(list1,list2);
    if(x==true)
        printf("\nIt is Pallindrome");
    else
        printf("\nIt is not Pallindrome");    
    return 0;
}
