#include "linked_list.h"

void
addNode(struct node *head, int *currIndex)
{
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));
    current->next->id = ++(*currIndex);
    getInput(&current->next->val);
    current->next->next = NULL;
}

void
addNodeFromArray(struct node *head, char str[][256], int *currIndex)
{
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));
    current->next->id = ++(*currIndex);
    strcpy(current->next->val.name, str[0]);
    strcpy(current->next->val.nickname, str[1]);
    strcpy(current->next->val.age, str[2]);
    strcpy(current->next->val.fact.fact1, str[3]);
    strcpy(current->next->val.fact.fact2, str[4]);
    strcpy(current->next->val.fact.fact3, str[5]);
    current->next->next = NULL;
}

void
deleteNode(struct node *head, int index)
{
    struct node *current = head;
    while (current->next != NULL) {
        if (current->next->id == index) {
            printf("Deleted index %d...\n", current->next->id);
            free(current->next);
            current->next = current->next->next;
            break;
        }

        current = current->next;
    }
}

void
updateNode(struct node *head, int index)
{
    struct node *current = head;
    while (current->next != NULL) {
        if (current->next->id == index) {
            getInput(&current->next->val);
            break;
        }

        current = current->next;
    }
}

void
displayNodes(struct node *head)
{
    struct node *current = head;
    while (current != NULL) {
        if (current != NULL && current->id != 0) {
            printf("ID: %d\n", current->id);
            printEntry(current->val);
        }

        current = current->next;
    }
}

void
freeList(struct node *head)
{
    struct node *current = head;
    struct node *tmpNode;
    while (current != NULL) {
        tmpNode = current;
        current = current->next;
        free(tmpNode);
    }
    head = NULL;
}
