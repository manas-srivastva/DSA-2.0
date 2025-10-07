#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node *head,*second,*third;

    // allocate memory for nodes in the linked list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));


    // link first and second nodes
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    // link second and third nodes
    second->data = 2; // assign data to second node
    second->next = third;
    // terminate the list at the third node

    third->data = 3; // assign data to third node
    third->next = NULL;


        // Traversing the linked list
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}