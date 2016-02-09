#ifndef SLAMBOOK_INFO_H
#define SLAMBOOK_INFO_H

    typedef enum { ADMIN = 1, EDITOR, AUTHOR, FOLLOWER } roles;

    typedef struct {
        char fact1[256];
        char fact2[256];
        char fact3[256];
    } facts;

    typedef struct {
        char name[64];
        char nickname[32];
        char age[32];
        facts fact;
    } info;
    
#endif
