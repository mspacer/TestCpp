#ifndef POINTERTEST_H_INCLUDED
#define POINTERTEST_H_INCLUDED

int pointerMain();
void changeVar(int* pVar, int value);
void inintArray(int arr[], int arrSize);
void printArray(int* arr, int arrSize);
int* createArr(int* arrSize);
int getMax(int* inputArr, int arrSize);
int* removeMax(int* inputArr, int arrSize, int maxVal, int* newArrSize);
int simplePointer();
int arrayAlloc();
int badAlloc();
int structPointer();

typedef struct Date
{
    int day;
    int month;
    int year;
} MyDate;

#endif // POINTERTEST_H_INCLUDED
