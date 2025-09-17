#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void appendList(Node **root, int value);
void printList(Node *root);
void deallocList(Node **root);
//int initList();
//int addNode();

int main() {

    int input;
    Node *root = { 0 };

    while(1) {
        printf("Enter a number: ");
        scanf("%d", &input);
        if (input < 1) {
            break;
        }

        // add node to list
        //addNode(&ls, input);
        appendList(&root, input);

        // print list
        printList(root);

//        for (Node *curr = &root; curr != NULL; curr = curr->next) {
//            printf("%d->", curr->value);
//            if (curr->next == NULL) {
//                printf("%s","NULL");
//            }
//        }
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
void deallocList(Node **root) {
    Node *curr = *root;
    while(curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}
//int initList() {
//    return 0;
//}
//int addNode() {
//    return 0;
//}
























