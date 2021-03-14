//
//  hw0104.c
//  hw0104
//
//  Created by Michael Leong on 2021/3/6.
//

#include <stdio.h>
#include "json_parser.h"

int main() {
    char jsonString[2049] = {0};
    size_t level = 0;
    char *lastResult = NULL;
    char *lastKey = NULL;
    
    printf("Please enter JSON string:\n");
    fgets(jsonString, 2049, stdin);
    
    lastResult = jsonString;
    lastKey = jsonString;
    JsonObj *JsonObjArray[1024]; //array of JsonObj struct
    size_t arrayCounter = 0;
    char *keyTemp;
    char lastReadChar = 0;
    
    for(char *i = jsonString; *i != 0; i++) {
        printf("*i = %c\n", *i);
        if(*i == '{') {
            level++;
        } else if(*i == '}') {
            level--;
        }
        
        if(*i == ':' && level == 1 && lastReadChar != ':') {
            JsonObjArray[arrayCounter] = initializeJsonObj();
            *i = 0;
            keyTemp = lastKey;
            cleanString(&keyTemp);
            //printf("keyTemp: %p\n", keyTemp);
            //printf("keyTemp: %s\n", keyTemp);
            JsonObjArray[arrayCounter]->key = keyTemp;
            //printf("key: %s\n", JsonObjArray[arrayCounter]->key);
            lastKey = ++i;
            lastReadChar = ':';
            //printf("lastkey: %s\n", lastKey);
        } else if((*i == ',' || *i == '}') && level == 1 && lastReadChar == ':') {
            *i = 0;
            keyTemp = lastKey;
            cleanString(&keyTemp);
            //printf("keyTemp: %s\n", keyTemp);
            JsonObjArray[arrayCounter]->data = keyTemp;
            //printf("data: %s\n", JsonObjArray[arrayCounter]->data);
            lastKey = ++i;
            lastReadChar = ',';
        }
        
        
    }
    
    printf("key: %s\n", JsonObjArray[0]->key);
    printf("data: %s\n", JsonObjArray[0]->data);
    
    printf("free pointers yay!\n");
    //free all of the JsonObj pointers
    for(size_t i = 0; i < 1024; i++) {
        free(JsonObjArray[i]);
    }
    
    return 0;
}
