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
    size_t keyCounter = 0;
    size_t jsonObjPtrArr = 0;
    int choice = -1;
    char inputKey[1025] = {0};
    
    for(char *i = jsonString; *i != 0; i++) {
        //printf("*i = %c\n", *i);
        if(*i == '{') {
            level++;
            //printf("level: %ld\n", level);
        } else if(*i == '}') {
            level--;
            keyCounter = 0;
            jsonObjPtrArr = 0;
            //printf("level: %ld\n", level);
        }
        
        if(*i == ':' && lastReadChar != ':') {
            JsonObjArray[arrayCounter] = initializeJsonObj(level);
            *i = 0;
            keyTemp = lastKey;
            cleanString(&keyTemp);
            //printf("keyTemp: %p\n", keyTemp);
            //printf("keyTemp: %s\n", keyTemp);
            JsonObjArray[arrayCounter]->key = keyTemp;
            //printf("key: %s\n", JsonObjArray[arrayCounter]->key);
            lastKey = i+1;
            lastReadChar = ':';
            //printf("lastkey: %s\n", lastKey);
            if(level > 1) {
                JsonObjArray[keyCounter]->subset[JsonObjArray[keyCounter]->haveSubset] = JsonObjArray[arrayCounter];
                JsonObjArray[keyCounter]->haveSubset++;
            }
        } else if((*i == ',' || *i == '}') && level <= 1 && lastReadChar == ':') {
            *i = 0;
            keyTemp = lastKey;
            cleanString(&keyTemp);
            JsonObjArray[arrayCounter]->data = keyTemp;
            lastKey = i+1;
            lastReadChar = ',';
            arrayCounter++;
        } else if(*i == ':' && lastReadChar == ':') {
            JsonObjArray[arrayCounter]->haveSubset++;
            keyCounter = arrayCounter;
            arrayCounter++;
            JsonObjArray[arrayCounter] = initializeJsonObj(level);
            *i = 0;
            keyTemp = lastKey;
            cleanString(&keyTemp);
            JsonObjArray[arrayCounter]->key = keyTemp;
            lastKey = i+1;
            lastReadChar = ':';
        }
        
    }
    
    /*for(size_t i = 0; i < 4; i++) {
        printf("key: %s\n", JsonObjArray[i]->key);
        printf("data: %s\n", JsonObjArray[i]->data);
    }*/
    
    while(1) {
        printf("Choice (0:Exit,1:Get)\n");
        scanf("%d", &choice);
        if(choice == 0) {
            return 1;
        }
        fflush(stdin);
        printf("Key:\n");
        input(inputKey, 1024);
        printf("Value:\n");
        //if()
        printf("%s\n", searchKey(inputKey, &JsonObjArray));
    }
    
    
    printf("free pointers yay!\n");
    //free all of the JsonObj pointers
    for(size_t i = 0; i < 1024; i++) {
        free(JsonObjArray[i]);
    }
    
    return 0;
}
