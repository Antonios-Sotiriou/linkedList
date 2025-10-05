#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void printList(Node* root);
void prependList(Node **root, int value);
void appendList(Node **root, int value);
void insertAfter(Node **root, int index, int value);
void insertSorted(Node** root, int value);
void deallocList(Node **root);

int main() {

    int input;
    Node *root = { 0 };

    while(1) {
        printf("Enter a number: ");
        scanf("%d", &input);
        if (input < 1) {
            break;
        }

        //int index = 0;
        //printf("Enter index: ");
        //scanf("%d", &index);

        // add node to list
        //addNode(&ls, input);
        //prependList(&root, input);
        //appendList(&root, input);
        //insertAfter(&root, index, input);
        insertSorted(&root, input);

        // print list
        printList(root);
    }

    deallocList(&root);
    return 0;
}
void printList(Node *root) {
    if (root != 0) {
        printf("%d->", root->value);
        printList(root->next);
    } else {
        printf("NULL\n");
    }
}
void prependList(Node **root, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;

    if (*root == NULL) {
        printf("Null Starting pointer\n");
        *root = new_node;
        new_node->next = NULL;
        return;
    }

    new_node->next = *root;
    *root = new_node;
}
void appendList(Node **root, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (*root == NULL) {
        printf("Null Starting pointer\n");
        *root = new_node;
        return;
    }

    Node *curr = *root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}
void insertAfter(Node **root, int index, int value) {

    if (*root != NULL) {
        for (Node *curr = *root; curr != NULL; curr = curr->next) {

            if (curr->value == index) {
                Node *new_node = malloc(sizeof(Node));

                new_node->value = value;
                new_node->next = curr->next;
                curr->next = new_node;
                return;
            }
        }
    } else {
        Node *new_node = malloc(sizeof(Node));

        new_node->value = value;
        new_node->next = NULL;
        *root = new_node;
        return;
    }
    printf("Index not found!\n");
}
void insertSorted(Node **root, int value) {
    if ((*root == NULL) || ((*root)->value >= value)) {
        prependList(root, value);
        return;
    }

    Node *curr;
    for (curr = *root; curr->next != NULL; curr = curr->next) {
        if (curr->next->value >= value) {
            break;
        }
    }
    insertAfter(root, curr->value, value);
}
void deallocList(Node **root) {
    Node *curr = *root;
    while(curr != NULL) {
        Node *temp = curr;

        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}


