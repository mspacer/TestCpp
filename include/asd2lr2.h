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
        cout << "назва шаблону: " << name
            << " кумедність: " << funy
            << " кількість вподобайок: " << countLike  << endl;
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

    int push_back(HashNode hashNode); //додавання елементу в кінець
    HashNode pop_back(); //зчитування та видалення елементу з кінця
    HashNode get(int n); //зчитування n-го елементу
    int sizeList(); //знаходження кількості елементів
    void print(); //виведення всіх елементів з даними, що зберігаються
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

    int hash(llong key); // знаходnження хеш-функції від ключа
    bool insert(llong key, TMem value); // додавання значення під відповідним ключем (заміна у випадку існування ключа)
    TMem find(llong key); //знаходження значення під відповідним ключем, функція повертає вказівник на знайдений елемент або NULL
    bool erase(llong key); //видалення значення під відповідним ключем
    int size(); //знаходження кількості елементів в хеш-таблиці
};

int asd2Lr2Main();
llong generateLongLong(int length);

#endif // ASD2LR2_H_INCLUDED
