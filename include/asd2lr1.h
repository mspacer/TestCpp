#ifndef ASD2LR1_H_INCLUDED
#define ASD2LR1_H_INCLUDED

using namespace std;

struct MyTest {
    int count; //к≥льк≥сть завдань
    int maxMark; //максимальна оц≥нка
    bool isCheating; //ймов≥рн≥сть списуванн€

    MyTest() {
        count = -1;
        maxMark = -1;
        isCheating = 0;
    }

    MyTest(int cnt, int mxmr, bool cht){
        count = cnt;
        maxMark = mxmr;
        isCheating = cht;
    }

    void print() {
        cout << "к≥льк≥сть завдань: " << count
            << " максимальна оц≥нка: " << maxMark
            << " ймов≥рн≥сть списуванн€: " << isCheating  << endl;
    }

    int isEvaliable() {
        return maxMark != -1;
    }
};

const int DEFAULT_CAPACITY = 3;

struct DynamicTestArray {
    MyTest* tests;
    int capacity, size;

    DynamicTestArray(){
        capacity = DEFAULT_CAPACITY;
        size = 0;
        tests = (MyTest*) malloc(DEFAULT_CAPACITY * sizeof(MyTest));
    }

    int push_back(MyTest test); //додаванн€ елементу в
    MyTest pop_back(); //зчитуванн€ та видаленн€ елементу з к≥нц€
    MyTest get(int n); //зчитуванн€ n-го елементу
    int sizeElement(); //знаходженн€ к≥лькост≥ елемент≥в
    void print();//виведенн€ вс≥х елемент≥в з даними, що збер≥гаютьс€
    int push_front(MyTest test); //додаванн€ елементу в початок
    MyTest pop_front(); //зчитуванн€ та видаленн€ елементу з початку
    int growCapacity();
};

typedef struct Node {
  MyTest test;
  Node* next;
} Node;

struct LinkedList {
    Node* node;
    int size;

    LinkedList(){
        size = 0;
        node = NULL;
    }

    int push_front(MyTest test); //додаванн€ елементу в початок
    int push_back(MyTest test); //додаванн€ елементу в к≥нець
    MyTest get(int n); //зчитуванн€ n-го елементу
    MyTest pop_front(); //зчитуванн€ та видаленн€ елементу з початку
    MyTest pop_back(); //зчитуванн€ та видаленн€ елементу з к≥нц€
    int sizeList(); //знаходженн€ к≥лькост≥ елемент≥в
    void print(); //виведенн€ вс≥х елемент≥в з даними, що збер≥гаютьс€
    void deleteNodes();
};

int asd2Lr1Main();

#endif // ASD2LR1_H_INCLUDED
