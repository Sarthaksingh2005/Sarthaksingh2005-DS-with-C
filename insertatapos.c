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

void insertatpos(struct node**headref,int pos,int data)
{
    struct node* newnode=createnode(data);
    struct node*temp=*headref;
    for(int i=0;i<pos-1&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("pos out of range");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
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

    insertatpos(&head,3,0);

    printf("Updated list: ");
    printlist(head);

    freelist(head);
    return 0;
}
