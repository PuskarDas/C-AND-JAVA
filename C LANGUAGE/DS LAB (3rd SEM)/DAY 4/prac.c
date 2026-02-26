#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function Prototypes
void traverseForward();
void traverseBackward();
void insertFirst(int data);
void insertLast(int data);
void insertAtPosition(int data, int position);
void deleteFirst();
void deleteLast();
void deleteAtPosition(int position);
void deleteByKey(int key);
int countNodes();
int searchElement(int key);
int isEmpty();

// Traverse forward
void traverseForward() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward Traversal: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse backward
void traverseBackward() {
    struct Node* temp = head;
    if (!temp) {
        printf("List is empty.\n");
        return;
    }
    while (temp->next)
        temp = temp->next;

    printf("Backward Traversal: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Insert at beginning
void insertFirst(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertLast(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at specific position
void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertFirst(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 1; temp && i < position - 1; i++)
        temp = temp->next;

    if (!temp) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete first node
void deleteFirst() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

// Delete at specific position
void deleteAtPosition(int position) {
    if (position == 1) {
        deleteFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp && i < position; i++)
        temp = temp->next;

    if (!temp) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

// Delete by key
void deleteByKey(int key) {
    struct Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        printf("Key not found.\n");
        return;
    }

    if (temp == head)
        head = temp->next;
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

// Count nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search element
int searchElement(int key) {
    int position = 1;
    struct Node* temp = head;
    while (temp) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

// Check if list is empty
int isEmpty() {
    return head == NULL;
}

// Main method
int main() {
    int choice, data, position, key;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Traverse Forward\n");
        printf("2. Traverse Backward\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete First\n");
        printf("7. Delete Last\n");
        printf("8. Delete at Position\n");
        printf("9. Delete by Key\n");
        printf("10. Count Nodes\n");
        printf("11. Search Element\n");
        printf("12. Check if Empty\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseForward();
                break;
            case 2:
                traverseBackward();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFirst(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertLast(data);
                break;
            case 5:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteLast();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 9:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(key);
                break;
            case 10:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 11:
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(key);
                if (position != -1)
                    printf("Element found at position %d\n", position);
                else
                    printf("Element not found.\n");
                break;
            case 12:
                if (isEmpty())
                    printf("List is empty.\n");
                else
                    printf("List is not empty.\n");
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 13);

    return 0;
}