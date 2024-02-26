#ifndef ASD2LR2_H_INCLUDED
#define ASD2LR2_H_INCLUDED

#include <cstdlib>

using namespace std;
typedef unsigned long long llong;

typedef struct Mem {
    string name;
    int funy;
    int countLike;

    Mem() {
        name = "template_" + to_string(rand()%100);
        funy = rand()%10;
        countLike = rand()%1000000;
    }

    void print() {
        cout << "����� �������: " << name
            << " ���������: " << funy
            << " ������� ����������: " << countLike  << endl;
    }

} TMem;

struct HashNode {
    llong key;
    TMem *mem;

    HashNode() {
        key = -1;
        mem = NULL;
    }
    HashNode(llong k, TMem *m) {
        key = k;
        mem = m;
    }

    void print() {
        cout << "key: " << key
            << ", Mem: " ;
        mem->print();
    }
};

struct HNode {
  HashNode hashNode;
  HNode* next;
};

struct HLinkedList {
    HNode* node;
    int size;

    HLinkedList(){
        size = 0;
        node = NULL;
    }

    int push_back(HashNode hashNode); //��������� �������� � �����
    HashNode pop_back(); //���������� �� ��������� �������� � ����
    HashNode get(int n); //���������� n-�� ��������
    int sizeList(); //����������� ������� ��������
    void print(); //��������� ��� �������� � ������, �� �����������
};

struct HashTable {
    int m;
    HLinkedList *bucketsArray;
    int count;

    HashTable() {
        m = 10000;
        bucketsArray = (HLinkedList*) malloc(m*sizeof(HLinkedList));
        count = 0;
    }

    int hash(llong key); // ������n����� ���-������� �� �����
    bool insert(llong key, TMem value); // ��������� �������� �� ��������� ������ (����� � ������� ��������� �����)
    TMem find(llong key); //����������� �������� �� ��������� ������, ������� ������� �������� �� ��������� ������� ��� NULL
    bool erase(llong key); //��������� �������� �� ��������� ������
    int size(); //����������� ������� �������� � ���-�������
};

int asd2Lr2Main();
llong generateLongLong(int length);

#endif // ASD2LR2_H_INCLUDED
