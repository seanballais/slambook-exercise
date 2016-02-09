#ifndef SLAMBOOK_FUNCS_H
#define SLAMBOOK_FUNCS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "slambook_info.h"

    void printEntry(info personInfo);
    void getInput(info *personInfo);
    void _removeNewline(char* input);
    void printMenu(roles role);

#endif
