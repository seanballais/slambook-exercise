#include "file_access.h"

void
readDataFromFile(FILE *fp, struct node *head, int *currIndex)
{
    if (fp != NULL) { // Close the file if it has not been closed yet
        fclose(fp);
    }

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        return;
    } else {
        char line[897];
        while (fgets(line, sizeof(line), fp)) { // Read the line
            // Tokenize the string now and place the info in an array
            char *token = strtok(line, "|");
            char info[6][256];
            int index = 0;
            while (token != NULL) {
                strcpy(info[index], token);

                token = strtok(NULL, "|");
                index++;
            }

            addNodeFromArray(head, info, currIndex);
        }

        fclose(fp);
        fp = NULL;

    }
}

void
saveDataToFile(FILE *fp, struct node *head)
{
    if (fp != NULL) { // Close the file if it has not been closed yet
        fclose(fp);
    }

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        return;
    } else {
        struct node *current = head;
        while (current != NULL) {
            if (current != NULL && current->id != 0) {
                fprintf(fp, "%s|%s|%s|%s|%s|%s\n",
                        current->val.name,
                        current->val.nickname,
                        current->val.age,
                        current->val.fact.fact1,
                        current->val.fact.fact2,
                        current->val.fact.fact2
                        );
            }

            current = current->next;
        }
    }

    fclose(fp);
    fp = NULL;
}
