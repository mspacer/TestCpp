#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include <asd2lr2.h>

using namespace std;

int asd2Lr2Main()
{
    TMem *mem1 = new TMem();
    //cout << mem1->name << " " << mem1->funy << " " << mem1->countLike << endl;

    llong p = generateLongLong(11);
    llong p1 = generateLongLong(11);
    llong p2 = generateLongLong(11);
    cout << p << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    //cout << p%10000 << endl;

    HLinkedList* pList = new HLinkedList;
    HashNode node1(p, mem1);
    pList->push_back(node1);
    HashNode node2(p1, mem1);
    pList->push_back(node2);

    pList->print();

    HashTable hHable;
    cout << hHable.hash(p) << endl;
    cout << hHable.hash(p1) << endl;
    cout << hHable.hash(p2) << endl;

    return 0;
}

llong generateLongLong(int length) {
    string s = "";

    for(int i = 0; i <= length;) {
        int r = rand()%10;
        if (!(i == 0 && r == 0)) {
            s += to_string(r);
            i++;
        }
    }

    llong p = stoll(s);
    return p;
}

//---------------------HashTable-----------------------------------------------------------------------------------------------------
// знаходnження хеш-функції від ключа
int HashTable::hash(llong key) {
    int a = rand()%10 + 1;
    int b = rand()%10 + 1 + a;
    llong p = 9149658775000477;

    int i = ((a * key + b) % p) % m;
    return i;
}

// додавання значення під відповідним ключем (заміна у випадку існування ключа)
bool HashTable::insert(llong key, TMem value) {

    return 1;
}

//знаходження значення під відповідним ключем, функція повертає вказівник на знайдений елемент або NULL
TMem HashTable::find(llong key) {

}

//видалення значення під відповідним ключем
bool HashTable::erase(llong key) {

    return 1;
}

//знаходження кількості елементів в хеш-таблиці
int HashTable::size() {
    return count;
}

//----------------------LinkedList----------------------------------------------------------------------------------------------------
int HLinkedList::push_back(HashNode hashNode){
    //додавання елементу в кінець
    HNode* nextNode = new HNode();
    nextNode->hashNode = hashNode;

    if (node != NULL) {
        HNode* prevNode = node;
        HNode* prevNodeNext = prevNode->next;
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

HashNode HLinkedList::pop_back() {
    //зчитування та видалення елементу з кінця
    if (size == 0) {
        cout << "list empty" << endl;
        return {};
    }

    HNode* prevNode = node;
    HNode* prevNodeNext = prevNode->next;
    while (prevNodeNext != nullptr) {
        prevNode = prevNodeNext;
        prevNodeNext = prevNode->next;
    }

    HashNode hashNode = prevNode->hashNode;
    delete prevNode;
    size--;
    return hashNode;
}

HashNode HLinkedList::get(int n) {
    //зчитування n-го елементу
    if (n > size - 1 || size == 0) {
        cout << "no such element:" << n << endl;
        return {};
    }

    if (n == 0) {
        return node->hashNode;
    }

    int i = 1;
    HNode* prevNode = node;
    HNode* nodeNext = node;
    do {
        nodeNext = nodeNext->next;
        if (nodeNext != nullptr) {
            prevNode = nodeNext;
        }
    } while(++i <= n);

    if (nodeNext != NULL) {
        return nodeNext->hashNode;
    }
    return prevNode->hashNode;
}


int HLinkedList::sizeList() {
    //знаходження кількості елементів
    return size;
}

void HLinkedList::print() {
    //виведення всіх елементів з даними, що зберігаються
    if (size > 0) {
        cout << endl << "1)";
        node->hashNode.print();

        HNode* ptr = node->next;
        for (int i = 1; i < size; i++) {
            if (ptr != NULL) {
                cout << (i + 1) << ") ";
                ptr->hashNode.print();
                ptr = ptr->next;
            }
        }
        cout << endl;
    }
}

