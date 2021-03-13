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
    char key[2049];
    char data[2049];
    size_t level; //level should start from 1
    int haveSubset; // if 1, it has a subset
    struct _JsonObj *subset; //may have another subset
} JsonObj;

JsonObj *initializeJsonObj() {
    JsonObj *JsonObj1 = (JsonObj*)malloc(sizeof(JsonObj1));
    return JsonObj1;
}

#endif /* json_parser_h */
