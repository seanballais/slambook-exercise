#include <stdio.h>
#include <stdlib.h>

#include "slambook_info.h"
#include "linked_list.h"
#include "slambook_funcs.h"

int
main(int argc, char **argv)
{
    char throwaway = 'a';
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;

    // Read data from text file
    /*FILE *fp;
    fp = fopen("data.txt", "a+");
    while (getc(fp) != EOF) { // Loop through whole file until EOF
        char str_buff[256];
        while (getc(fp) != '\n') { // Loop through whole line until newline
            strcat(str_buff, getc(fp));
        }
    }*/

    printf("SLAMBOOK!\n");
    printf("Choose role\n");
    printf("    1) ADMIN\n");
    printf("    2) EDITOR\n");
    printf("    3) AUTHOR\n");
    printf("    4) FOLLOWER\n");
    printf("Input: ");

    int role = 0;
    scanf("%d", &role);
    scanf("%c", &throwaway);
    if (role < 1 || role > 4) {
        printf("Invalid input.\n");
        return 0;
    }

    // Menu
    int idx = 0;
    int opt = 0;
    while (1) {
        printMenu(role);
        scanf("%d", &opt);
        scanf("%c", &throwaway);
        if ((role == ADMIN && (opt < 1 || opt > 5))  ||
            (role == EDITOR && (opt < 1 || opt > 4)) ||
            (role == AUTHOR && (opt < 1 || opt > 3)) ||
            (role == FOLLOWER && (opt < 1 || opt > 2))) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (role) {
            case ADMIN:
                if (opt == 2 || opt == 3) {
                    printf("Choose index: ");
                    scanf("%d", &idx);
                    scanf("%c", &throwaway);
                }

                if (opt == 1) {
                    addNode(head);
                } else if (opt == 2) {
                    displayNodes(head);
                    updateNode(head, idx);
                } else if (opt == 3) {
                    displayNodes(head);
                    deleteNode(head, idx);
                } else if (opt == 4) {
                    displayNodes(head);
                } else if (opt == 5) {
                    return 0;
                }

                break;
            case EDITOR:
                if (opt == 1) {
                    addNode(head);
                } else if (opt == 2) {
                    displayNodes(head);
                    printf("Choose index: ");
                    scanf("%d", &idx);
                    scanf("%c", &throwaway);
                    updateNode(head, idx);
                } else if (opt == 3) {
                    displayNodes(head);
                } else if (opt == 4) {
                    return 0;
                }

                break;
            case AUTHOR:
                if (opt == 1) {
                    addNode(head);
                } else if (opt == 2) {
                    displayNodes(head);
                } else if (opt == 3) {
                    return 0;
                }

                break;
            case FOLLOWER:
                if (opt == 1) {
                    displayNodes(head);
                } else if (opt == 2) {
                    return 0;
                }

                break;
        }
    }

    return 0;
}
