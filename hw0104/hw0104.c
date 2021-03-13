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
    
    printf("Please enter JSON string:\n");
    fgets(jsonString, 2049, stdin);
    
    JsonObj *JsonObjArray[1024]; //array of JsonObj struct
    size_t arrayCounter = 0;
    
    for(char *i = jsonString; i != 0; i++) {
        if(*i == '{') {
            level++;
        } else if(*i == '}') {
            level--;
        }
        
        
        
    }
    
    
    //free all of the JsonObj pointers
    for(size_t i; i < 1024; i++) {
        free(JsonObjArray[i]);
    }
    
    return 0;
}
