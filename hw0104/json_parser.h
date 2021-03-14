//
//  json_parser.h
//  hw0104
//
//  Created by Michael Leong on 2021/3/12.
//

#ifndef json_parser_h
#define json_parser_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _JsonObj {
    char *key;
    char *data;
    size_t level; //level should start from 1
    int haveSubset; // if 1, it has a subset
    struct _JsonObj *subset[1024]; //may have another subset
} JsonObj;

JsonObj *initializeJsonObj(void);
void clearString(char *str);

#endif /* json_parser_h */
