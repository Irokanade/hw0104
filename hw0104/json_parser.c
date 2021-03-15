//
//  json_parser.c
//  hw0104
//
//  Created by Michael Leong on 2021/3/12.
//

#include "json_parser.h"
#include <string.h>

JsonObj *initializeJsonObj(unsigned long level) {
    JsonObj *JsonObj1 = (JsonObj*)malloc(sizeof(JsonObj1));
    JsonObj1->key = NULL;
    JsonObj1->data = NULL;
    JsonObj1->level = level;
    JsonObj1->haveSubset = 0;
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
            //printf("str: %p\n", *str);
            *secondDoubleQuote = 0;
            *str = firstDoubleQuote;
            //printf("str: %p\n", *str);
            //printf("str: %s\n", *str);
            return;
        }
    }
    
    //else clear any symbol character
    removeSymbols(*str);
}

void removeSymbols(char *s) {
    const char* d = s;
    do {
        while (*d == ' ' || *d == '{' || *d == '}' || *d == '\"' || *d == ',' || *d == ':') {
            ++d;
        }
    } while (*s++ = *d++);
}

void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

//file is stdin
char *input(char *string, int len) {
    char *str;
    
    str = fgets(string, len, stdin);
    for(char *i = string; *i != 0; i++) {
        if(*i == '\n') {
            *i = 0;
        }
    }
    
    return str;
}

char *searchKey(char *key, JsonObj *jsonArray[]) {
    for(size_t i = 0; i < 1024; i++) {
        if(strncmp(key, jsonArray[i]->key, strlen(key)) == 0) {
            return jsonArray[i]->data;
        }
    }
    
    return NULL;
}
