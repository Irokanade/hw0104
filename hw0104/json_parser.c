//
//  json_parser.c
//  hw0104
//
//  Created by Michael Leong on 2021/3/12.
//

#include "json_parser.h"
#include <string.h>

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

void cleanString(char **str) {
    char *firstDoubleQuote = strchr(*str, '\"');
    if(firstDoubleQuote != NULL) {
        char *secondDoubleQuote = strchr(++firstDoubleQuote, '\"');
        if(secondDoubleQuote != NULL) {
            printf("str: %p\n", *str);
            *secondDoubleQuote = 0;
            *str = firstDoubleQuote;
            printf("str: %p\n", *str);
            printf("str: %s\n", *str);
            return;
        }
    }
    
    //else clear any symbol character
    const char *d = *str;
    do {
        while (*d == ' ' || *d == '{' || *d == '}' || *d == '\"' || *d == ',' || *d == ':') {
            ++d;
        }
    } while (**str++ = *d++);
}

void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
