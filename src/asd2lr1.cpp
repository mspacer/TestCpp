#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <asd2lr1.h>

using namespace std;

int asd2Lr1Main()
{
    cout << "--- АСД2 ЛР-1 ----" << endl;

    MyTest test1(10, 100, false);

    DynamicTestArray dta;
    int isPush = dta.push_back(test1);

    MyTest test2(11, 101, true);
    dta.push_front(test2);
    MyTest test3(12, 102, true);
    dta.push_back(test3);
    MyTest test4(13, 103, true);
    dta.push_back(test4);
    dta.print();

    MyTest test5 = dta.pop_back();
    cout << "after pop_back test5: " << &test5.count << " " << &test5.maxMark << " " << &test5.isCheating << endl;
    cout << "test5: ";  test5.print(); cout << endl;

    MyTest* pTest = dta.pop_front();
    //pTest = &test5;
    cout << "after pop_front pTest: " << &pTest << " " << pTest << " " << &pTest->count << " " << &pTest->maxMark << " " << &pTest->isCheating << endl;
    cout << "pTest: "; pTest->print(); cout << endl;

    test5 = dta.get(0);
    if (test5.isEvaliable()) {
        test5.print();
    }
    test5 = dta.get(10);
    if (test5.isEvaliable()) {
        test5.print();
    }

    dta.print();
    delete dta.tests;
    delete pTest;

    cout << endl << "variant with pointers" << endl;
    DynamicTestArray* pDta = new DynamicTestArray;
    pDta->push_front(test2);
    pDta->push_back(test3);
    pDta->push_back(test4);
    pDta->push_front(test1);

    pDta->print();

    delete pDta->tests;
    delete pDta;

    cout << endl << "--------LinkedList----------" << endl;

    LinkedList* pList = new LinkedList;
    pList->push_back(test1);
    pList->push_back(test2);
    pList->push_front(test3);

    pList->print();

    MyTest test6 = pList->get(2);
    test6.print();

    test6 = pList->pop_front();
    test6.print();
    pList->print();

    test6 = pList->pop_back();
    test6.print();
    pList->print();

    delete pList;

    cout << "------------------" << endl;
    return 0;
}

//------------- DynamicTestArray---------------------------------------------------------------------------------------------------------
int DynamicTestArray::push_front(MyTest test) {
    //додавання елементу в початок
    if (size == capacity) {
        cout << "size == capacity" << endl;
        int isGrow = growCapacity();
        if (!isGrow) {
            return 0;
        }
    }

    for(int i = size; i > 0; i--) {
        tests[i] = tests[i-1];
    }

    tests[0] = test;
    size++;
    return 1;
}
int DynamicTestArray::push_back(MyTest test) {
    //додавання елементу в кінець
    if (size == capacity) {
        cout << "size == capacity" << endl;
        int isGrow = growCapacity();
        if (!isGrow) {
            return 0;
        }
    }

    tests[size++] = test;
    return 1;
};

MyTest* DynamicTestArray::pop_front() {
    //зчитування та видалення елементу з початку
    if (size == 0) {
        cout << "size = 0" << endl;
    }

    cout << "pop_front tests[0]: " << &tests[0].count << " " << &tests[0].maxMark << " " << &tests[0].isCheating << endl;

    //MyTest test = tests[0];
    //cout << "pop_front test: " << &test.count << " " << &test.maxMark << " " << &test.isCheating << endl;
    //cout << "pop_front tests[0].print: "; tests[0].print();
    MyTest* test = new MyTest(tests[0].count, tests[0].maxMark, tests[0].isCheating);
    cout << "pop_front test: " << &test << " " << test << " " << &test->count << " " << &test->maxMark << " " << &test->isCheating << endl;
   // cout << "pop_front test.print: "; test->print();

    for(int i = 1; i < size; i++) {
        tests[i-1] = tests[i];
    }
    tests[--size] = {};
    //cout << "pop_front2 tests[0]: " << &tests[0].count << " " << &tests[0].maxMark << " " << &tests[0].isCheating << endl;
    //cout << "pop_front2 tests[0].print: ";  tests[0].print();

    //return &tests[0];
    //return &test;
    return test;
}

MyTest DynamicTestArray::pop_back() {
    //зчитування та видалення елементу з кінця
    if (size == 0) {
        cout << "size = 0" << endl;
    }

    size--;
    MyTest test(tests[size].count, tests[size].maxMark, tests[size].isCheating);
    //MyTest test = tests[size];
    cout << "pop_back tests[size]: " << &tests[size] << " " << &tests[size].count << " " << &tests[size].maxMark << " " << &tests[size].isCheating << endl;
    cout << "pop_back2 test: " << &test << " " << &test.count << " " << &test.maxMark << " " << &test.isCheating << endl;
    tests[size] = {};
    return test;
}

MyTest DynamicTestArray::get(int n) {
    //зчитування n-го елементу
    if (n > size - 1 || size == 0) {
        cout << "no such element:" << n << endl;
        return {};
    }

    return tests[n];
}

int DynamicTestArray::sizeElement() {
    //знаходження кількості елементів
    return size;
}

void DynamicTestArray::print() {
    //виведення всіх елементів з даними, що зберігаються
    cout << "Elements:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ")";
        tests[i].print();
    }
}

int DynamicTestArray::growCapacity() {
    capacity += DEFAULT_CAPACITY;
    tests = (MyTest*) realloc(tests, capacity*sizeof(MyTest));
    if (tests == nullptr) {
        return 0;
    }
    cout << "new capacity = " << capacity << endl;
    return 1;
}

//----------------------LinkedList----------------------------------------------------------------------------------------------------

int LinkedList::push_front(MyTest test) {
    //додавання елементу в початок
    Node* firstNode = new Node();
    firstNode->test = test;

    if (node != NULL) {
        firstNode->next = node;
        node = firstNode;
    } else {
        node = firstNode;
    }

    size++;
    return 1;
}

int LinkedList::push_back(MyTest test){
    //додавання елементу в кінець
    Node* nextNode = new Node();
    nextNode->test = test;

    if (node != NULL) {
        Node* prevNode = node;
        Node* prevNodeNext = prevNode->next;
        while (prevNodeNext != nullptr) {
            prevNode = prevNodeNext;
            prevNodeNext = prevNode->next;
        }
        prevNode->next = nextNode;
    } else {
        node = nextNode;
    }

    size++;
    return 1;
}

MyTest LinkedList::pop_front() {
    //зчитування та видалення елементу з початку
    if (size == 0) {
        cout << "list empty" << endl;
        return {};
    }

    Node* nodeNext = node->next;
    MyTest test = node->test;
    delete node;
    node = nodeNext;
    size--;
    return test;
}

MyTest LinkedList::pop_back() {
    //зчитування та видалення елементу з кінця
    if (size == 0) {
        cout << "list empty" << endl;
        return {};
    }

    Node* prevNode = node;
    Node* prevNodeNext = prevNode->next;
    while (prevNodeNext != nullptr) {
        prevNode = prevNodeNext;
        prevNodeNext = prevNode->next;
    }

    MyTest test = prevNode->test;
    delete prevNode;
    size--;
    return test;
}

MyTest LinkedList::get(int n) {
    //зчитування n-го елементу
    if (n > size - 1 || size == 0) {
        cout << "no such element:" << n << endl;
        return {};
    }

    if (n == 0) {
        return node->test;
    }

    int i = 1;
    Node* prevNode = node;
    Node* nodeNext = node;
    do {
        nodeNext = nodeNext->next;
        if (nodeNext != nullptr) {
            prevNode = nodeNext;
        }
    } while(++i <= n);

    if (nodeNext != NULL) {
        return nodeNext->test;
    }
    return prevNode->test;
}


int LinkedList::sizeList() {
    //знаходження кількості елементів
    return size;
}

void LinkedList::print() {
    //виведення всіх елементів з даними, що зберігаються
    if (size > 0) {
        cout << endl << "1)";
        node->test.print();

        Node* ptr = node->next;
        for (int i = 1; i < size; i++) {
            if (ptr != NULL) {
                cout << (i + 1) << ")";
                ptr->test.print();
                ptr = ptr->next;
            }
        }
        cout << endl;
    }
}

void LinkedList::deleteNodes() {
    Node* ptr = node;
    while (ptr != NULL) {
        ptr->test.print();
        ptr = ptr->next;
    }
}
