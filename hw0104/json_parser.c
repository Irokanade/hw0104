//
//  json_parser.c
//  hw0104
//
//  Created by Michael Leong on 2021/3/12.
//

#include "json_parser.h"

JsonObj *initializeJsonObj() {
    JsonObj *JsonObj1 = (JsonObj*)malloc(sizeof(JsonObj1));
    JsonObj1->key = NULL;
    JsonObj1->data = NULL;
    JsonObj1->level = 0;
    for(size_t i = 0; i < 1024; i++) {
        JsonObj1->subset[i] = NULL;
    }
    return JsonObj1;
}

void clearString(char *str) {
    for(char *i = str; i != 0; i++) {
        
    }
}
