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
    pd = new double; //�������� ������
    if (pd != nullptr){
        *pd = 10.89; // �������� ��������
        d = *pd; // d = 10.89 - ������������� � ���������
        cout << "before: " << "d = " << d << ", " << "*pd = " << *pd << endl;
        // ���������� ������
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
        cout << "�������������� ��������. ������ �� ��������" << endl;
        cout << ba.what() << endl;
        return -1;
    }

    // ���� ������ ��������, �� ������������� ���������� pF, pI, pC
    float f = *pF; // f = 3.88
    cout << endl << "*pF = " << f << endl;
    delete pF;

    cout << "----------" << endl;
    return 0;
}

int structPointer()
{
    cout << endl << "--structPointer()--" << endl;

    // ��������� ������ ��� ����������� ���������� ���������� new
    struct Date* pd0; // ��������� �� struct Date
    MyDate* pd;

    try {
        pd0 = new struct Date; // ������� �������� ������
        pd = new MyDate; // ������� �������� ������
    } catch (bad_alloc ba) {
        cout << "������ �� ��������" << endl;
        return -1;
    }

    // ���� ������ ��������, ��
    // ������������� pd � ���������,
    // ���������� ���� 11.02.2029
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
    pd2 = pd; // �������� �� ���� MyDate
    //delete pd; // pd2->day ���������� ��������
    //delete pd2; // ����� ������ � delete pd;

    cout << "pd2 == nullptr: " << isNull << endl;
    cout << "&pd2: " << &pd2 << " pd2: " << pd2 << " &pd2->day: " << &pd2->day << " pd2->day: " << pd2->day <<  endl;

    // ���������� ������ �������������� ��� ���������� pd
    delete pd0;
    delete pd;
    //delete pd2;//������. delete pd ��� ������ MyDate

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

    // �������� ������ ���������� �� float
    float * ptrArray;

    try
    {
        // ����������� �������� ������ ��� 10 ��������� ���� float
        ptrArray = new float[10];
    }
    catch (bad_alloc ba)
    {
        cout << "�������������� ��������. ������ �� ��������" << endl;
        cout << ba.what() << endl;
        return -1; // ����� �� �������
    }

    // ���� ��� � �������, �� ������������ ������
    for (int i = 0; i < 10; i++)
        ptrArray[i] = i * i + 3;

    int d = ptrArray[5];
    cout << d << endl;

    delete[] ptrArray; // ���������� ������, ���������� ��� ������

    cout << "----------" << endl;
    return 0;
}
