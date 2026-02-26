#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node 
{
    char *key;
    int value;
    struct Node *next;
}Node;
typedef struct HashTable 
{
    int size;
    Node **table;
}HashTable;
int hash(char *key,int size) 
{
    int hash=0;
    for(int i=0;key[i]!='\0';i++) 
        hash=(hash*31+key[i])%size;
    return hash;
}
Node *createNode(char *key,int value) 
{
    Node *newNode=(Node*)malloc(sizeof(Node)); 
    newNode->key=strdup(key);
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
}
HashTable *createHashTable(int size) 
{
    HashTable *ht=(HashTable *)malloc(sizeof(HashTable));
    if(ht==NULL) 
        return NULL;
    ht->size=size;
    ht->table=(Node **)calloc(size,sizeof(Node *));
    if(ht->table==NULL) 
    {
        free(ht);
        return NULL;
    }
    return ht;
}
void insert(HashTable *ht,char *key,int value) 
{
    int index=hash(key,ht->size);
    Node *newNode=createNode(key,value);
    newNode->next=ht->table[index];
    ht->table[index]=newNode;
}
Node *search(HashTable *ht,char *key) 
{
    int index=hash(key,ht->size);
    Node *current=ht->table[index];
    while(current!=NULL) 
    {
        if(strcmp(current->key,key)==0) 
                return current;
        current=current->next;
    }
    return NULL;
}
void freeHashTable(HashTable *ht) 
{
    if(ht==NULL) 
        return;
    for(int i=0;i<ht->size;i++) 
    {
        Node *current=ht->table[i];
        while(current!=NULL) 
        {
            Node *temp=current;
            current=current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() 
{
    HashTable *ht=createHashTable(10);
    if (ht == NULL) 
    {
        printf("Failed to create hash table\n");
        return 1;
    }

    insert(ht, "apple",1);
    insert(ht, "banana",2);
    insert(ht, "grape",3);
    insert(ht, "cherry",4);
    insert(ht, "mango",5);
    insert(ht, "guava",6);
    insert(ht, "pineapple",7);
    insert(ht, "lemon",8);
    insert(ht, "orange",9);
    insert(ht, "kiwi",10);

    // Check for banana in the hash table
    Node *found=search(ht,"banana");
    if (found!=NULL) 
        printf("Value for banana: %d\n",found->value);
    else 
        printf("banana not found\n");
    printf("\n");

    // Check for grape in the hash table
    found=search(ht,"grape");
    if (found!=NULL) 
        printf("Value for grape: %d\n",found->value);
    else 
        printf("grape not found\n");
    printf("\n");
    
    // Check for orange in the hash table
    found=search(ht,"orange");
    if (found!=NULL) 
        printf("Value for orange: %d\n",found->value);
    else 
        printf("orange not found\n");
    printf("\n");
    
    // Check for pomegranate in the hash table
    found=search(ht,"pomegranate");
    if (found!=NULL) 
        printf("Value for pomegranante: %d\n",found->value);
    else 
        printf("pomegranate not found\n");
    
    freeHashTable(ht);
    return 0;
}
