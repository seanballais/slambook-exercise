#ifndef LINKED_LIST_H
#define LINKED_LIST_H

    #include <stdio.h>
    #include <stdlib.h>

    #include "slambook_info.h"
    #include "slambook_funcs.h"

    struct node {
        int id;
        info val;
        struct node *next;
    };

    void addNode(struct node *head);
    void deleteNode(struct node *head, int index);
    void updateNode(struct node *head, int index);
    void displayNodes(struct node *head);

#endif
