#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pointertest.h>

using namespace std;

int pointerMain()
{
    //simplePointer();

    structPointer();

    //arrayAlloc();

    //badAlloc();

    return 0;
}

void changeVar(int* pVar, int value) {
    *pVar = value;
}

void inintArray(int* arr, int arrSize) {
    //int arrSize = sizeof(arr)/sizeof(arr[0]);
    //cout << "arrSize2 = " << arrSize << endl;
   //cout << "inintArray arrSize = " << *arrSize << endl;

    for (int i = 0; i < arrSize; i++) {
        //arr[i] = rand()%arrSize;
        //*(arr + i) = rand()%arrSize;
        *(&arr[0] + i) = 10 + rand()%arrSize;
    }
}

void printArray(int* arr, int arrSize) {
    cout << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << "[" << i << "] = " << arr[i] << endl;
    }
}

int* createArr(int* arrSize) {
    int _size = 7;

    if (*arrSize == 0) {
        *arrSize = _size;
    }
    //int arr[arrSize];
    int* arr = (int*) malloc(*arrSize * sizeof(int));

    inintArray(arr, *arrSize);

    return arr;
}

int getMax(int* inputArr, int arrSize) {
    //int* arr = (int*) malloc(sizeof(int));
    int maxVal = inputArr[0];

    for(int i = 1; i < arrSize; i++ ) {
        if (maxVal < inputArr[i])
            maxVal = inputArr[i];
    }

    cout << "maxVal = " << maxVal << endl;
    return maxVal;
}

int* removeMax(int* inputArr, int arrSize, int maxVal, int* newArrSize) {
    int newSize = 0;

    for(int i = 0; i < arrSize; i++ ) {
        if (maxVal != inputArr[i]) {
                newSize++;
        }
    }
//cout << "newSize = " << newSize << endl;
    int* arr = (int*) calloc(newSize, sizeof(int));
    if (*arr == NULL) {
        cout << "arr is null "  << endl;
    }
    int j = 0;
    for(int i = 0; i < arrSize; i++ ) {
           // cout << "inputArr[" <<i <<"] = " << inputArr[i] << endl;
        if (maxVal != inputArr[i]) {
            arr[j] = inputArr[i];
            //cout << "arr[" <<j <<"] = " << arr[j] << endl;
            j++;
        }
    }

    cout << "newSize = " << newSize << endl;
    *newArrSize = newSize;
    return arr;
}

int simplePointer()
{
    cout << endl << "--simplePointer()--" << endl;

    int a = 10;
    int* pA = &a;

    double d;
    double * pd = nullptr;
    pd = new double; //выделить память
    if (pd != nullptr){
        *pd = 10.89; // записать значения
        d = *pd; // d = 10.89 - использование в программе
        cout << "before: " << "d = " << d << ", " << "*pd = " << *pd << endl;
        // освободить память
        delete pd;
    }
    cout << "after: " << "d = " << d << ", " << "*pd = " << *pd << endl << endl;

    cout << "pA = " << pA << endl;
    cout << "&pA = " << &pA << endl;
    cout << "*pA = " << *pA << endl;

    *pA = 11;
    cout << "*pA = " << *pA << endl;
    cout << "a = " << a << endl;

    int b = 13;
    pA = &b;
    cout << "*pA = " << *pA << endl;
    cout << "a = " << a << endl;

    changeVar(&b, 100);
    cout << "b = " << b << endl;

    int* pB = pA;
    changeVar(pB, 101);
    cout << "b = " << b << endl;

    float* pF;

    try {
        pF = new float(34.45);
    } catch (bad_alloc ba) {
        cout << "Исключительная ситуация. Память не выделена" << endl;
        cout << ba.what() << endl;
        return -1;
    }

    // если память выделена, то использование указателей pF, pI, pC
    float f = *pF; // f = 3.88
    cout << endl << "*pF = " << f << endl;
    delete pF;

    cout << "----------" << endl;
    return 0;
}

int structPointer()
{
    cout << endl << "--structPointer()--" << endl;

    // выделение памяти для структурной переменной оператором new
    struct Date* pd0; // указатель на struct Date
    MyDate* pd;

    try {
        pd0 = new struct Date; // попытка выделить память
        pd = new MyDate; // попытка выделить память
    } catch (bad_alloc ba) {
        cout << "Память не выделена" << endl;
        return -1;
    }

    // если память выделена, то
    // использование pd в программе,
    // установить дату 11.02.2029
    pd->day = 11;
    pd->month = 2;
    pd->year = 2029;

    pd0->year = pd->year;

    cout << pd->month << endl;
    cout << &(pd->month) << endl;
    cout << pd0->year << endl;
    cout << &(pd0->year) << endl;

    cout << "&pd: " << &pd << " pd: " << pd << " &pd->day: " << &pd->day << " pd->day: " << pd->day << endl;

    MyDate* pd2 /*= NULL*/;
    bool isNull = pd2 == nullptr;

/*     *pd2 = *pd;*/ // error. no memory
    pd2 = pd; // ссылаютя на один MyDate
    //delete pd; // pd2->day непонятное значение
    //delete pd2; // будет ошибка в delete pd;

    cout << "pd2 == nullptr: " << isNull << endl;
    cout << "&pd2: " << &pd2 << " pd2: " << pd2 << " &pd2->day: " << &pd2->day << " pd2->day: " << pd2->day <<  endl;

    // освободить память использованную под переменную pd
    delete pd0;
    delete pd;
    //delete pd2;//ошибка. delete pd уже удалил MyDate

    cout << "----------" << endl;
    pd = new MyDate;
    pd->day = 21;
    cout << "&pd: " << &pd << " pd: " << pd << " &pd->day: " << &pd->day << " pd->day: " << pd->day << endl;

    pd2 = new MyDate;
    pd2->day = 5;
    cout << "&pd2: " << &pd2 << " pd2: " << pd2 << " &pd2->day: " << &pd2->day << " pd2->day: " << pd2->day <<  endl;

    *pd2 = *pd;
    cout << "&pd2: " << &pd2 << " pd2: " << pd2 << " &pd2->day: " << &pd2->day << " pd2->day: " << pd2->day <<  endl;

    cout << "----------" << endl;
    return 0;
}

int arrayAlloc()
{
    cout << endl << "--arrayAlloc()--" << endl;

    int arrA[10];
   // cout << "arrSize1 = " << sizeof(arrA)/sizeof(int) << endl;
   // inintArray(arrA, 10);
   // printArray(arrA, 10);

    int arrBSize = 10;
    int* arrB = createArr(&arrBSize);
    //printArray(arrB, arrBSize);

    arrBSize = 20;
    arrB = (int*) realloc(arrB, 15*sizeof(int));
    //inintArray(arrB, arrBSize);
    //printArray(arrB, arrBSize);

    arrB = (int*) realloc(arrB, 20*sizeof(int));
    inintArray(arrB, arrBSize);
    printArray(arrB, arrBSize);
    free(arrB);

    arrB = (int*) calloc(10, sizeof(int));
    inintArray(arrB, 10);
    if (*arrB == NULL) {
        cout << "arr is null "  << endl;
    }

    int maxx = getMax(arrB, arrBSize);
    int newSize = 0;
    int* arrC = removeMax(arrB, arrBSize, maxx, &newSize);
    cout << "newSize = " << newSize << endl;
    printArray(arrC, newSize);

    free(arrB);
    free(arrC);

    cout << "----------" << endl;
    return 0;
}

int badAlloc()
{
    cout << endl << "--badAlloc()--" << endl;

    // объявить массив указателей на float
    float * ptrArray;

    try
    {
        // попробовать выделить память для 10 элементов типа float
        ptrArray = new float[10];
    }
    catch (bad_alloc ba)
    {
        cout << "Исключительная ситуация. Память не выделена" << endl;
        cout << ba.what() << endl;
        return -1; // выход из функции
    }

    // если все в порядке, то использовать массив
    for (int i = 0; i < 10; i++)
        ptrArray[i] = i * i + 3;

    int d = ptrArray[5];
    cout << d << endl;

    delete[] ptrArray; // освободить память, выделенную под массив

    cout << "----------" << endl;
    return 0;
}
