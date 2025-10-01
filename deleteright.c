#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void deleteright(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);   
    temp->next = NULL;  
}

void printlist(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);  
        head = head->next;
    }
    printf("\n"); 
}

void freelist(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);

    printf("Original list: ");
    printlist(head);

    deleteleft(&head);

    printf("Updated list: ");
    printlist(head);

    freelist(head);
    return 0;
}
