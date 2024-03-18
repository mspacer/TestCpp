#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <windows.h>

#include <stringTest.h>

using namespace std;

int stringTestMain() {
    char str1[30]="STRING ARRAY";
    char *str2;
    char *str3;
    //char *str4 = (char*) malloc(8);
    //char str4[8];

    str2 = str1;
    str3 = "STRING POINTER";

    printf("Length of the string str1 is => %ld\n",strlen(str1));
    printf("Length of the string str2 is => %ld\n",strlen(str2));
    printf("Length of the string str3 is => %ld\n",strlen(str3));
    printf("Length of the string 'STRING LITERALS' is => %ld\n", strlen("STRING LITERALS"));

    char str4[11] = "qwertyuiop";
    for(int i = 0; i < strlen(str4); i++) {
        str4[i] = str1[i];
    }
    for(int i = 0; i < strlen(str4); i++) {
        cout << str4[i];
    }
    cout << endl;

    printf("Length of the string str4 is => %ld\n", strlen(str4));

    return 0;
}
