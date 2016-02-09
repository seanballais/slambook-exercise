#include "slambook_funcs.h"

void
printEntry(info personInfo)
{
    printf("Name: %s\n", personInfo.name);
    printf("Nickname: %s\n", personInfo.nickname);
    printf("Age: %s\n", personInfo.age);
    printf("Facts\n");
    printf("1) %s\n", personInfo.fact.fact1);
    printf("2) %s\n", personInfo.fact.fact2);
    printf("3) %s\n", personInfo.fact.fact3);
    printf("===\n");
}

void
getInput(info *personInfo)
{
    printf("New Entry\n");

    printf("Name: ");
    fgets(personInfo->name, sizeof(personInfo->name), stdin);
    _removeNewline(personInfo->name);

    printf("Nickname: ");
    fgets(personInfo->nickname, sizeof(personInfo->nickname), stdin);
    _removeNewline(personInfo->nickname);

    printf("Age: ");
    fgets(personInfo->age, sizeof(personInfo->age), stdin);
    _removeNewline(personInfo->age);

    printf("Facts\n");

    printf("Fact 1: ");
    fgets(personInfo->fact.fact1, sizeof(personInfo->fact.fact1), stdin);
    _removeNewline(personInfo->fact.fact1);

    printf("Fact 2: ");
    fgets(personInfo->fact.fact2, sizeof(personInfo->fact.fact2), stdin);
    _removeNewline(personInfo->fact.fact2);

    printf("Fact 3: ");
    fgets(personInfo->fact.fact3, sizeof(personInfo->fact.fact3), stdin);
    _removeNewline(personInfo->fact.fact3);

    printf("Data entered successfully.\n");
}

void
_removeNewline(char* input)
{
    char *pos;
    if ((pos = strchr(input, "\n")) != NULL) {
        *pos = '\0';
    }
}

void
printMenu(roles role)
{
    printf("SLAMBOOK Menu\n");

    int optionNum = 0;
    if (role != FOLLOWER) {
        optionNum++;
        printf("    %d) Add\n", optionNum);
    }

    if (role == ADMIN || role == EDITOR) {
        optionNum++;
        printf("    %d) Update\n", optionNum);
    }

    if (role == ADMIN) {
        optionNum++;
        printf("    %d) Delete\n", optionNum);
    }

    optionNum++;
    printf("    %d) Display\n", optionNum);

    optionNum++;
    printf("    %d) Exit\n", optionNum);
    printf("Input: ");
}
