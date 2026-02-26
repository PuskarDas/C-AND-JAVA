#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBegin(int data) {
    Node *newNode = createNode(data);
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    Node *newNode = createNode(data);
    if (!head) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        Node *tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = head->prev = newNode;
    }
}

// Insert at specific position
void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBegin(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    Node *newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBegin() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    Node *tail = head->prev;
    Node *temp = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if (!head) return;
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    Node *tail = head->prev;
    tail->prev->next = head;
    head->prev = tail->prev;
    free(tail);
}

// Delete at specific position
void deleteAtPosition(int pos) {
    if (!head) return;
    if (pos == 1) {
        deleteAtBegin();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Delete by key
void deleteByKey(int key) {
    if (!head) return;
    Node *temp = head;
    do {
        if (temp->data == key) {
            if (temp == head)
                deleteAtBegin();
            else if (temp->next == head)
                deleteAtEnd();
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Search by key
int search(int key) {
    if (!head) return -1;
    Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

// Bubble sort
void bubbleSort() 
{
    if (!head || head->next == head) 
        return;
    int swapped;
    Node *ptr1, *lptr = NULL;
    do 
    {
        swapped = 0;
        ptr1 = head;
        do {
            Node *next = ptr1->next;
            if (next != head && ptr1->data > next->data) {
                int temp = ptr1->data;
                ptr1->data = next->data;
                next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != lptr && ptr1->next != head);
        lptr = ptr1;
    } while (swapped);
}

// Traverse list
void traverse() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Reverse list
void reverse() {
    if (!head || head->next == head) return;
    Node *current = head, *temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = head->next;
}

// Main function for testing
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBegin(5);
    insertAtPosition(15, 3);
    traverse(); // 5 10 15 20

    deleteAtBegin();
    deleteAtEnd();
    deleteAtPosition(2);
    traverse(); // 10

    insertAtEnd(30);
    insertAtEnd(25);
    traverse(); // 10 30 25

    bubbleSort();
    traverse(); // 10 25 30

    reverse();
    traverse(); // 30 25 10

    int key = 25;
    int pos = search(key);
    if (pos != -1)
        printf("Key %d found at position %d\n", key, pos);
    else
        printf("Key %d not found\n", key);

    deleteByKey(25);
    traverse(); // 30 10

    return 0;
}