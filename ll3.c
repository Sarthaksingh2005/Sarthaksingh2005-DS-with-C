//3 remove nth node from the end
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*createnode(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node*removenthnodefromtheend(struct node*head,int n)
{
  struct node*dummy=createnode(0);
  dummy->next=head;

  struct node*fast=dummy;
  struct node*slow=dummy;
  for(int i=0;i<n;i++)
  {
    if(fast==NULL) return head;
    fast=fast->next;
  }
  while(fast!=NULL)
  {
    fast=fast->next;
    slow=slow->next;
  }
  struct node*del=slow->next;
  slow->next=del->next;
  free(del);

  struct node* newHead = dummy->next;
    free(dummy);
    return newHead;
}
void printlist(struct node*head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}
void freelist(struct node*head)
{
    struct node*temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    struct node*head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);

    printf("original list");
    printlist(head);

    struct node*result=removenthnodefromtheend(head,2);
    printf("updated list");
    printlist(result);

    free(head);


}