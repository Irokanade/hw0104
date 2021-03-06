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

JsonObj *initializeJsonObj(unsigned long level);
void cleanString(char **str);
void removeSymbols(char *s);
void remove_spaces(char *s);
char *input(char *string, int len);
char *searchKey(char *key, JsonObj *jsonArray[]);

#endif /* json_parser_h */
