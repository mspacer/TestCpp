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
        name = "template_";// to_string(rand()%100);
        funy = rand()%10;
        countLike = rand()%1000000;
    }

    void print() {
        cout << "address: " << &name
            << " назва шаблону: " << name
            << " кумедність: " << funy
            << " кількість вподобайок: " << countLike  << endl;
    }

} TMem;

struct HashNode {
    llong key;
    TMem *mem;

    HashNode() {
        key = -1;
        mem = new TMem();
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
  HashNode *hashNode;
  HNode* next;
  HNode() {
      hashNode = new HashNode();
      next = NULL;
  }
};

struct HLinkedList {
    HNode* node;
    int size;

    HLinkedList(){
        cout << "HLinkedList()" << endl;
        size = 0;
        node = NULL;
    }

    int push_back(HashNode *hashNode); //додавання елементу в кінець
    HashNode* get(int n); //зчитування n-го елементу
    int sizeList(); //знаходження кількості елементів
    void print(); //виведення всіх елементів з даними, що зберігаються
    bool remove(llong key);
};

const int M_BUCKETS = 1000;

struct HashTable {
    HLinkedList *bucketsArray;
    //HLinkedList singleBucketsArray;
    int count;
    int capacity;
    float loadFactor;

    HashTable() {
        cout << "HashTable()" << endl;
        capacity = M_BUCKETS;
        bucketsArray = (HLinkedList*) malloc(M_BUCKETS*sizeof(HLinkedList));
        for (int i = 0; i < M_BUCKETS; i++) {
            bucketsArray[i].size = 0;
            bucketsArray[i].node = nullptr;
        }
        count = 0;
        loadFactor = 8.5;
    }

    int hash(llong key); // знаходnження хеш-функції від ключа
    bool insert(llong key, TMem *value); // додавання значення під відповідним ключем (заміна у випадку існування ключа)
    TMem* find(llong key); //знаходження значення під відповідним ключем, функція повертає вказівник на знайдений елемент або NULL
    bool erase(llong key); //видалення значення під відповідним ключем
    int size(); //знаходження кількості елементів в хеш-таблиці
    int search(int i, llong key);
    void checkLoadFactor();
    int deleteBucketsArray();
    void print();
};

int asd2Lr2Main();
llong generateRandLong();
llong generateRandLong1();
bool testHashTable();

#endif // ASD2LR2_H_INCLUDED
