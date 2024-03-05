#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#include <stringExample.h>

using namespace std;

int mainStringExample() {
    char str[20] = "string 1";
    char* str2 = "str2";

    char* newStr =  strcatBegin(str, str2);
    cout << "newStr: " << newStr << endl;

    strcatBegin2(str, str2);
    cout << "str: " << str << endl;

    delete newStr;
    return 0;
}

char* removeSpaceC(char* src) {
    int i, j;
    char* dest = (char*) malloc(strlen(src)*sizeof(char));
    for(i = j = 0; src[i] != '\0'; i++) {
        if(src[i] != ' ') {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
    //cout << "strlen(src): " << strlen(src) << ", strlen(dest): " << strlen(dest) << endl;

    return dest;
}

bool isEmptyStr(char* src) {
    char* dest = removeSpaceC(src);
    int len = strlen(dest);
    delete dest;
    //cout << "len: " << len << endl;
    return len <= 1;
}

char* strcatBegin(char* src, char* add) {
    int size = strlen(src) + strlen(add) + 1;
    char* newStr = (char*) malloc(size*sizeof(char));

    for (int i = 0; i < strlen(add); i++) {
        if (add[i] != '\0')
            newStr[i] = add[i];
    }
    for (int i = 0; i < strlen(src); i++) {
        if (src[i] != '\0')
            newStr[i + strlen(add)] = src[i];
    }
    newStr[size - 1] = '\0';
    return newStr;
}

void strcatBegin2(char* src, char* add) {
    int size = strlen(src) + strlen(add) + 1;

    for (int i = strlen(add) - 1; i >=0; i--) {
        if (add[i] != '\0') {
            memmove(src + 1, src, strlen(src) );
            memset(src, add[i], 1);
        }
    }
    src[size - 1] = '\0';
}
