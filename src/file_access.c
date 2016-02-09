#include "file_access.h"

void
readDataFromFile(FILE *fp, struct node *head)
{

}

void
saveDataToFile(FILE *fp, struct node *head)
{
    if (fp != NULL) { // Close the file if it has not been closed yet
        fclose(fp);
    }

    fp = fopen("data.txt", "w");
    struct node *current = head;
    while (current != NULL) {
        if (current != NULL and current->id != 0) {
            fprintf(fp, "%s|%s|%s|%s|%s|%s\n",
                    current->name,
                    current->nickname,
                    current->age,
                    current->fact->fact1,
                    current->fact->fact2,
                    current->fact->fact2
            );
        }

        current = current->next;
    }

    fclose(fp);
}
