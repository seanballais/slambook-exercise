#include <stdio.h>
#include <stdlib.h>

#include "slambook_info.h"
#include "slambook_funcs.h"

void
printEntry(info personInfo)
{
    printf("Name: %s", personInfo.name);
    printf("Nickname: %s", personInfo.nickname);
    printf("Age: %s", personInfo.age);
    printf("Facts\n");
    printf("1) %s", personInfo.fact.fact1);
    printf("2) %s", personInfo.fact.fact2);
    printf("3) %s", personInfo.fact.fact3);
    printf("===\n");
}

void
getInput(info *personInfo)
{
    printf("New Entry\n");

    printf("Name: ");
    fgets(personInfo->name, sizeof(personInfo->name), stdin);

    printf("Nickname: ");
    fgets(personInfo->nickname, sizeof(personInfo->nickname), stdin);

    printf("Age: ");
    fgets(personInfo->age, sizeof(personInfo->age), stdin);

    printf("Facts\n");

    printf("Fact 1: ");
    fgets(personInfo->fact.fact1, sizeof(personInfo->fact.fact1), stdin);

    printf("Fact 2: ");
    fgets(personInfo->fact.fact2, sizeof(personInfo->fact.fact2), stdin);

    printf("Fact 3: ");
    fgets(personInfo->fact.fact3, sizeof(personInfo->fact.fact3), stdin);

    printf("Data entered successfully.\n");
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
