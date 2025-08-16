#include <stdio.h>   // Standard I/O library for printf, scanf
#include <stdlib.h>  // Standard library for malloc, free

// Define structure of a Node
struct Node {
    int data;              // Stores data value of the node
    struct Node* next;     // Stores address of the next node
};

// ================= INSERTION FUNCTIONS =================

// Insert a node at the beginning
void insertLeft(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate memory for new node
    newNode->data = data;                                            // store data in new node
    newNode->next = *head;                                           // point new node to current head
    *head = newNode;                                                 // update head to new node
}

// Insert a node at the end
void insertRight(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    newNode->data = data;                                            // assign data
    newNode->next = NULL;                                            // last node always points to NULL

    if (*head == NULL) {                                             // if list is empty
        *head = newNode;                                             // new node becomes head
        return;
    }

    struct Node* temp = *head;                                       // start from head
    while (temp->next != NULL)                                       // traverse to last node
        temp = temp->next;

    temp->next = newNode;                                            // link last node to new node
}

// Insert at a given position (1-based index)
void insertAtPos(struct Node **head, int data, int pos) {
    if (pos <= 1) {                       // position 1 means insert at beginning
        insertLeft(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // new node creation
    newNode->data = data;

    struct Node* temp = *head;             // start traversal from head
    for (int i = 1; i < pos - 1 && temp != NULL; i++)  // move to (pos-1)th node
        temp = temp->next;

    if (temp == NULL) {                   // if position exceeds list length
        printf("Position out of range.\n");
        free(newNode);                    // free unused node
        return;
    }

    newNode->next = temp->next;           // link new node to next node
    temp->next = newNode;                 // link previous node to new node
}

// ================= DELETION FUNCTIONS =================

// Delete first node
void deleteLeft(struct Node **head) {
    if (*head == NULL) {                      // if list is empty
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;                // store current head
    *head = (*head)->next;                    // move head to next node
    free(temp);                               // free old head
}

// Delete last node
void deleteRight(struct Node **head) {
    if (*head == NULL) {                      // empty list check
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {              // if only one node exists
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;                // traverse to second last node
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);                         // free last node
    temp->next = NULL;                        // mark new end
}

// Delete node at a given position
void deleteAtPos(struct Node **head, int pos) {
    if (pos <= 1) {                           // position 1 means delete first node
        deleteLeft(head);
        return;
    }

    struct Node* temp = *head;                // start from head
    for (int i = 1; i < pos - 1 && temp != NULL; i++)  // move to (pos-1)th node
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) { // if position invalid
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;        // node to delete
    temp->next = delNode->next;               // bypass delNode
    free(delNode);                            // free memory
}

// ================= OTHER OPERATIONS =================

// Display linked list
void display(struct Node *head) {
    if (head == NULL) {                       // empty list check
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;                 // start from head
    while (temp != NULL) {                    // traverse till end
        printf("%d -> ", temp->data);         // print data
        temp = temp->next;                    // move forward
    }
    printf("NULL\n");                         // mark end of list
}

// Print reverse order (using recursion)
void printReverse(struct Node* temp) {
    if (temp == NULL) return;                 // base case: end of list
    printReverse(temp->next);                 // recursive call
    printf("%d -> ", temp->data);             // print after recursive call (reverse order)
}

// Search element in linked list
void searchElement(struct Node* head, int key) {
    struct Node* temp = head;                 // start from head
    int pos = 1;                              // position counter

    while (temp != NULL) {
        if (temp->data == key) {              // check if data matches key
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;                    // move forward
        pos++;
    }
    printf("Element %d not found.\n", key);   // if not found
}

// Insert after a given element (key)
void insertAfterElement(struct Node **head, int key, int data) {
    struct Node* temp = *head;                // start from head

    while (temp != NULL && temp->data != key) // search for key
        temp = temp->next;

    if (temp == NULL) {                       // if key not found
        printf("Element %d not found.\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // create new node
    newNode->data = data;
    newNode->next = temp->next;               // link new node after key node
    temp->next = newNode;
}
