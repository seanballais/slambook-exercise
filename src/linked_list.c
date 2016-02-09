#include "linked_list.h"

void
addNode(struct node *head)
{
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));
    current->next->id = /*++currIndex*/ 1;
    getInput(&current->next->val);
    current->next->next = NULL;
}

void
deleteNode(struct node *head, int index)
{
    struct node *current = head;
    while (current->next != NULL) {
        if (current->next->id == index) {
            printf("Deleting index %d...\n", current->next->id);
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
