#ifndef ASD2LR1_H_INCLUDED
#define ASD2LR1_H_INCLUDED

using namespace std;

struct MyTest {
    int count; //������� �������
    int maxMark; //����������� ������
    bool isCheating; //��������� ����������

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
        cout << "������� �������: " << count
            << " ����������� ������: " << maxMark
            << " ��������� ����������: " << isCheating  << endl;
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

    int push_back(MyTest test); //��������� �������� �
    MyTest pop_back(); //���������� �� ��������� �������� � ����
    MyTest get(int n); //���������� n-�� ��������
    int sizeElement(); //����������� ������� ��������
    void print();//��������� ��� �������� � ������, �� �����������
    int push_front(MyTest test); //��������� �������� � �������
    MyTest pop_front(); //���������� �� ��������� �������� � �������
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

    int push_front(MyTest test); //��������� �������� � �������
    int push_back(MyTest test); //��������� �������� � �����
    MyTest get(int n); //���������� n-�� ��������
    MyTest pop_front(); //���������� �� ��������� �������� � �������
    MyTest pop_back(); //���������� �� ��������� �������� � ����
    int sizeList(); //����������� ������� ��������
    void print(); //��������� ��� �������� � ������, �� �����������
    void deleteNodes();
};

int asd2Lr1Main();

#endif // ASD2LR1_H_INCLUDED
