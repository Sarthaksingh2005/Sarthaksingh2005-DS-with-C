#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* removenthnode(struct node* head, int pos) {
    if (head == NULL) return NULL;

    
    if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

 
    struct node* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

 
    if (temp == NULL || temp->next == NULL) return head;

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
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
    struct node* head = createnode(0);
    head->next = createnode(1);
    head->next->next = createnode(2);
    head->next->next->next = createnode(3);

    printf("Original list: ");
    printlist(head);

    head = removenthnode(head, 2);

    printf("Updated list: ");
    printlist(head);

    freelist(head);
    return 0;
}
