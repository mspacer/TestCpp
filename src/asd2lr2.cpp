#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include <asd2lr2.h>
#include <unordered_map>
#include <ctime>
#include <algorithm>

using namespace std;

const int COUNT_DATA = 20;
int insertedCount = 0;
int replacedCount = 0;
int erasedCount = 0;

int asd2Lr2Main()
{
/*    for(int i = 0; i < COUNT_DATA; i++) {
        int numDigits = rand() % 19 + 10;
        cout << numDigits << ", ";
    }
    cout << endl;
*/

    TMem *mems = new TMem[COUNT_DATA];
    llong *keys = new llong[COUNT_DATA];
    HashTable hHable;

    for(int i = 0; i < COUNT_DATA; i++) {
        mems[i].name += to_string(i);
        keys[i] = generateRandLong();
    }
    for(int i = 0; i < COUNT_DATA; i++) {
        cout <<  &mems[i].name << " " << mems[i].name << " " << mems[i].funy << " " << mems[i].countLike << endl;
    }
    for(int i = 0; i < COUNT_DATA; i++) {
        //cout << "key: "<< keys[i] << " hash(key): " << hHable.hash(keys[i]) << endl;
    }

  /*  HLinkedList* pList = new HLinkedList;
    HashNode node(keys[0], &mems[0]);
    pList->push_back(&node);
    HashNode node1(keys[1], &mems[1]);
    pList->push_back(&node1);
    pList->print();
*/

    for(int i = 0; i < COUNT_DATA; i++) {
        hHable.insert(keys[i], mems + i);
    }

    cout << endl << "-------mems2 -------- " << endl;

    TMem mems2[COUNT_DATA];
    for(int i = 0; i < COUNT_DATA; i++) {
        //TMem *mem = new TMem(to_string(i);
        mems2[i].name += to_string(i);
        mems2[i].funy = i + 10;
        mems2[i].countLike = i + 100;
        cout <<  &mems2[i].name << " " << mems2[i].name << " " << mems2[i].funy << " " << mems2[i].countLike << endl;
    }

    for(int i = 0; i < COUNT_DATA; i++) {
        if (i%2)
            hHable.insert(keys[i], &mems2[i]);
    }

    cout << endl << "-------find -------- " << endl;
    TMem* mem0 = hHable.find(keys[1]);
    mem0->print();
    cout <<  &mem0->name << endl;

    cout << endl << "-------erase -------- " << endl;
    hHable.print();
    hHable.erase(keys[18]);

    //delete pList;
    cout << endl << "-------HASH PRINT -------- " << endl;
    hHable.print();
    cout << "hHable.size: " << hHable.size() << endl;
    hHable.deleteBucketsArray();
    return 0;
}

llong generateRandLong() {
    string s = "";
    int length = 11;

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

llong generateRandLong1() {
    int numDigits = rand() % 19 + 10; // Random number of digits between 10 and 19
    unsigned long long num = rand() % 9 + 1; // Random non-zero first digit
    for (int i = 1; i < numDigits; i++) {
        unsigned long long digit = rand() % 10;
        num = num * 10 + digit;
    }
    return num % (unsigned long long)(pow(10, 18));
}

//---------------------HashTable-----------------------------------------------------------------------------------------------------
// знаходnження хеш-функції від ключа
int HashTable::hash(llong key) {
    int a = 1;
    int b = 7;
    llong p = 9149658775000477;

    int i = ((a * key + b) % p) % M_BUCKETS;
    return i;
     //return key % M_BUCKETS;
}

// додавання значення під відповідним ключем (заміна у випадку існування ключа)
bool HashTable::insert(llong key, TMem *value) {
    int i = hash(key);
   // cout << endl << "insert key = " << key << " name: " << value->name << "  i = " << i << " bucketsArray[i].size = " << bucketsArray[i].size << endl; ;
    //int pos = search(i, key);
    //cout <<  " pos = " << pos << endl;
    TMem* mem = nullptr;

    if (bucketsArray[i].size > 0) {
       mem = find(key);
    }

    if (bucketsArray[i].size == 0 || mem == nullptr) {
        HashNode* node = new HashNode(key, value);
        bucketsArray[i].push_front(node);
        count++;
        insertedCount++;
    } else {
            //cout <<  " key exists" << endl;
            //HashNode *hashNode = bucketsArray[i].get(pos);
            mem->name = value->name;
            mem->funy = value->funy;
            mem->countLike = value->countLike;
            replacedCount++;
    }

    checkLoadFactor();
    return 1;
}

//знаходження значення під відповідним ключем, функція повертає вказівник на знайдений елемент або NULL
TMem* HashTable::find(llong key) {
    int i = hash(key);
    HNode* node = bucketsArray[i].node;

    while(node != nullptr) {
        if (node->hashNode->key == key) {
            return node->hashNode->mem;
        }
        node = node->next;
    }

    return nullptr;
}

//видалення значення під відповідним ключем
bool HashTable::erase(llong key) {
    int i = hash(key);
    if (bucketsArray[i].remove(key)) {
        count--;
    }
    return 0;
}

//знаходження кількості елементів в хеш-таблиці
int HashTable::size() {
    return count;
}
/*int HashTable::size() {
    int _count = 0;
    int _count2 = 0;
    for(int i = 0; i < capacity; i++) {
        HNode* node = bucketsArray[i].node;
        _count2 += bucketsArray[i].size;
        if (node != nullptr) {
            _count++;
            HNode* ptr = node->next;
            while (ptr != nullptr) {
                _count++;
                ptr = ptr->next;
            }
        }
    }
    cout << "count: " << count << endl;
    cout << "_count2: " << _count2 << endl;
    return _count;
}*/

//not used
int HashTable::search(int i, llong key) {
    for(int j = 0; j < bucketsArray[i].size; j++) {
        HashNode* hashNode = bucketsArray[i].get(j);
        if (hashNode->key == key) {
            return j;
        }
    }
    return -1;
}

void HashTable::checkLoadFactor() {
    float factor = count/capacity;
    if (factor > loadFactor) {
        capacity = capacity*2;
        cout << "capacity: " << capacity << endl;
        bucketsArray = (HLinkedList*) realloc(bucketsArray, capacity*sizeof(HLinkedList));
        //bucketsArrayTmp = (HLinkedList*) malloc(bucketsArray, capacity*sizeof(HLinkedList));
    }
}

int HashTable::deleteBucketsArray() {
    delete bucketsArray;
}

void HashTable::print() {
    for(int i = 0; i < capacity; i++) {
        if (bucketsArray[i].size > 0) {
            cout << "bucketsArray[" << i << "]: " << endl;
            bucketsArray[i].print();
        }
        /*for(int j = 0; j < bucketsArray[i].size; j++) {
            bucketsArray[i].get(j)->print();
        }*/
        cout << endl;
    }

}

//----------------------LinkedList----------------------------------------------------------------------------------------------------
int HLinkedList::push_front(HashNode *hashNode) {
    //додавання елементу в початок
    HNode* firstNode = new HNode();
    firstNode->hashNode = hashNode;

    if (node != NULL) {
        firstNode->next = node;
        node = firstNode;
    } else {
        node = firstNode;
    }

    size++;
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int HLinkedList::push_back(HashNode *hashNode){
    //додавання елементу в кінець
    HNode* newNode = new HNode();
    newNode->hashNode = hashNode;
    newNode->next = nullptr;
//    cout << "&newNode: " << &newNode << " newNode: " << newNode << " &hashNode: " << &newNode->hashNode
//    << " &next: " << &newNode->next << " next: " << newNode->next
//    << ", key: " << newNode->hashNode->key << ", key: " << &newNode->hashNode->key << endl ;

    if (node != nullptr) {
        HNode* prevNode = node;
        //HNode* prevNodeNext = prevNode->next;
        HNode* nextNode = node->next;
//        cout << " &nextNode: " << &nextNode << " &node: " << &node << " &node->next: " << &node->next
//        << " &prevNode: " << &prevNode << endl ;
        while (nextNode != nullptr) {
//           cout << "&nextNode: " << nextNode << endl ;
           prevNode = nextNode;
           nextNode = nextNode->next;
        }
        prevNode->next = newNode;
    } else {
        node = newNode;
    }

    size++;
    return 1;
}

HashNode* HLinkedList::get(int n) {
    //зчитування n-го елементу
    if (n > size - 1 || size == 0) {
        cout << "no such element:" << n << endl;
        return NULL;
    }

    int i = 0;
    HNode* currentNode = node;
    while(i++ < n) {
        currentNode = currentNode->next;
    }
   // cout << "get(int " << n << "): " << currentNode << endl;
    //currentNode->hashNode->print();
    return currentNode->hashNode;
}

bool HLinkedList::remove(llong key) {
    if (node == nullptr || size == 0) {
        //cout << "error index" << endl;
        return 0;
    }
    HNode* nextNode = node->next;
    if (node->hashNode->key == key) {
        //удаляется первая нода
        HNode* temp = node;
        node = nextNode;
        size--;
        erasedCount++;
        delete temp;
        return 1;
    } else {
        HNode* prevNode = node;
        while(nextNode != nullptr) {
            if (nextNode->hashNode->key == key) {
                HNode* temp = nextNode;
                prevNode->next = nextNode->next;
                size--;
                erasedCount++;
                delete temp;
                return 1;
            }

            prevNode = nextNode;
            nextNode = nextNode->next;
        }
    }

    return false;
}

int HLinkedList::sizeList() {
    //знаходження кількості елементів
    return size;
}

void HLinkedList::print() {
    //виведення всіх елементів з даними, що зберігаються
    if (size > 0) {
        cout << endl << "1) ";
        //node->hashNode->print();
        cout << "&node:     " << &node << " node: " << node << " &hashNode: " << &node->hashNode  << ", key: " << node->hashNode->key
        << " &node.next: " << &node->next << " node.next: " << node->next << endl ;

        HNode* ptr = node->next;
        HNode** addrPtr = &node->next;
       // cout << "&addrPtr: " << &addrPtr << " addrPtr: " << addrPtr << " *addrPtr: " << *addrPtr << endl;
        for (int i = 1; i < size; i++) {
            if (ptr != NULL) {
                cout << (i + 1) << ") ";
                //ptr->hashNode->print();
                cout << "&nodeNext: " << addrPtr << " nodeNext: " << ptr  << " &hashNode: " << &ptr->hashNode <<
                ", key: " << ptr->hashNode->key
                << " &ptr.next: " << &ptr->next << " ptr.next: " << ptr->next << endl ;
                addrPtr = &ptr->next;
                ptr = ptr->next;
            }
        }
        cout << endl;
    }
}

//----------------------Test----------------------------------------------------------------------------------------------------

bool testHashTable() {
    const int iters = 500000;
    const int keysAmount = iters * 1;
    TMem *mem = new TMem();

    // generate random keys:
    long long* keys = new long long[keysAmount];
    long long* keysToInsert = new long long[iters];
    long long* keysToErase = new long long[iters];
    long long* keysToFind = new long long[iters];

    long long* keysToInsertMy = new long long[iters];
    long long* keysToEraseMy = new long long[iters];

    for (int i = 0; i < keysAmount; i++) {
        keys[i] = generateRandLong();
    }
    for (int i = 0; i < iters; i++) {
        keysToInsert[i] = keys[generateRandLong() % keysAmount];
        keysToErase[i] = keys[generateRandLong() % keysAmount];
        keysToFind[i] = keys[generateRandLong() % keysAmount];

        keysToInsertMy[i] = keysToInsert[i];
        keysToEraseMy[i] = keysToErase[i];
    }

/*    int insertUnique = 0;
    sort(keysToInsertMy, keysToInsertMy+iters);
    long long * end = unique(keysToInsertMy, keysToInsertMy+iters);
    for (int i = 0; i < end - keysToInsertMy; i++) {
        insertUnique++;
    }
    cout << "insertUnique: " << insertUnique << endl;

    int eraceUnique = 0;
    sort(keysToEraseMy, keysToEraseMy+iters);
    end = unique(keysToEraseMy, keysToEraseMy+iters);
    for (int i = 0; i < end - keysToEraseMy; i++) {
        eraceUnique++;
    }
    cout << "insertUnique: " << insertUnique << endl;
    cout << "eraceUnique: " << eraceUnique << endl;

//    cout << "eraseUnique: " << eraseUnique << endl;
//    cout << "insertEaseNotEqual: " << insertEaseNotEqual << endl;
*/
    // test my HashTable:
    HashTable hashTable;
    clock_t myStart = clock();
    cout << "do insert" << endl;
    for (int i = 0; i < iters; i++) {
        hashTable.insert(keysToInsert[i], new TMem());
    }
    int myInsertSize = hashTable.size();
    //hashTable.print();

    cout << "do erase" << endl;
    for (int i = 0; i < iters; i++) {
        hashTable.erase(keysToErase[i]);
    }
    int myEraseSize = hashTable.size();
   // hashTable.print();

    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (hashTable.find(keysToFind[i]) != NULL) {
            myFoundAmount++;
        }
    }
    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
    // test STL hash table:

    unordered_map<long long, TMem*> unorderedMap;
    clock_t stlStart = clock();

    for (int i = 0; i < iters; i++) {
        unorderedMap.insert({keysToInsert[i], new TMem()});
    }
    int stlInsertSize = unorderedMap.size();

    for (int i = 0; i < iters; i++) {
        unorderedMap.erase(keysToErase[i]);
    }
    int stlEraseSize = unorderedMap.size();

    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (unorderedMap.find(keysToFind[i]) != unorderedMap.end()) {
            stlFoundAmount++;
        }
    }

    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;
    cout << "My HashTable:" << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "STL unordered_map:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl << endl;

    cout << "insertedCount: " << insertedCount << endl;
    cout << "replacedCount: " << replacedCount << endl ;
    cout << "erasedCount: " << erasedCount << endl << endl;

    delete keys;
    delete keysToInsert;
    delete keysToErase;
    delete keysToFind;
    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize && myFoundAmount == stlFoundAmount) {
        cout << "The lab is completed" << endl;
        return true;
    }
    cerr << ":(" << endl;
    return false;
}
