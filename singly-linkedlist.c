#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNewNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning
struct Node* insertNode_infront(struct Node* head, int newData) {
    struct Node* newNode = createNewNode(newData);
    newNode->next = head;
    return newNode;
}

// Insert a node after a specific key
struct Node* insertNode_afterkey(struct Node* head, int newData, int key) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found.\n");
        return head;
    }

    struct Node* newNode = createNewNode(newData);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Insert a node at a specific position
struct Node* insertNode_atposition(struct Node* head, int newData, int position) {
    struct Node* newNode = createNewNode(newData);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position not available.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Insert a node at the end
struct Node* insertNode_atlast(struct Node* head, int newData) {
    struct Node* newNode = createNewNode(newData);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

// Delete the first node
struct Node* deleteNode_infront(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a node at a specific position
struct Node* deleteNode_atposition(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }

    if (position == 1) {
        return deleteNode_infront(head);
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int i;
    for (i = 1; i < position && current != NULL; ++i) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position not available.\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

// Delete the last node
struct Node* deleteNode_last(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    free(second_last->next);
    second_last->next = NULL;

    return head;
}

// Print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    
    struct Node* head = createNewNode(2);
    head->next = createNewNode(3);
    head->next->next = createNewNode(4);
    head->next->next->next = createNewNode(5);
    int newData;
    int position;
    int var1;
    int var2;
    int var;

    do {
        printf("\nEnter 1 to display linked list.");
        printf("\nEnter 2 to insert an element.");
        printf("\nEnter 3 to delete an element.");
        printf("\nEnter 4 to exit\n");
        scanf("%d", &var);

        switch (var) {
            case 1:
                printf("\nThe list is: ");
                printList(head);
                break;

            case 2:
                printf("\nEnter 1 to insert node at the beginning.");
                printf("\nEnter 2 to insert node at the end.");
                printf("\nEnter 3 to insert node at a specific position.");
                printf("\nEnter 4 to insert node after a specific position.");
                printf("\nEnter 5 to exit\n");
                scanf("%d", &var1);

                switch (var1) {
                    case 1:
                        printf("Enter the new data to be entered: ");
                        scanf("%d", &newData);
                        head = insertNode_infront(head, newData);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;

                    case 2:
                        printf("Enter the new data to be entered: ");
                        scanf("%d", &newData);
                        head = insertNode_atlast(head, newData);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;

                    case 3:
                        printf("Enter the new data to be entered: ");
                        scanf("%d", &newData);
                        printf("Enter the position where new data is to be entered: ");
                        scanf("%d", &position);
                        head = insertNode_atposition(head, newData, position);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;
                  
                    case 4:
                          printf("Enter the new data to be entered: ");
                          scanf("%d", &newData);
                          printf("Enter the position after which new data is to be entered: ");
                          scanf("%d", &position);
                          head = insertNode_afterkey(head, newData, position);
                          printf("\nThe updated list is: ");
                          printList(head);
                          break;

                    case 5:
                        printf("\nExiting the program.\n");
                        return 0;

                    default:
                        printf("Wrong Option\n");
                        break;
                }
                break;

            case 3:
                printf("\nEnter 1 to delete node at the beginning.");
                printf("\nEnter 2 to delete node at the end.");
                printf("\nEnter 3 to delete node at a specific position.");
                printf("\nEnter 4 to exit\n");
                scanf("%d", &var2);

                switch (var2) {
                    case 1:
                        head = deleteNode_infront(head);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;

                    case 2:
                        head = deleteNode_last(head);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;

                    case 3:
                        printf("Enter the position where new data is to be entered: ");
                        scanf("%d", &position);
                        head = deleteNode_atposition(head, position);
                        printf("\nThe updated list is: ");
                        printList(head);
                        break;

                    case 4:
                        printf("\nExiting the program.\n");
                        return 0;

                    default:
                        printf("Wrong Option\n");
                        break;
                }
                break;

            case 4:
                printf("\nExiting the program.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue? Enter 1 for yes and 0 for no: ");
        scanf("%d", &var);

    } while (var != 0);

    return 0;
}
