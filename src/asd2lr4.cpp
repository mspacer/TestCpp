#include <iostream>

#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "asd2lr2.h"
#include "asd2lr4.h"

using namespace std;

int asd2Lr4Main() {
    cout << "ACD-4" << endl;

    TStudentAsd4 s1(1, 60);
    TStudentAsd4 s2(2, 38);
    TStudentAsd4 s3(3, 50);
    TStudentAsd4 s4(4, 75);
    TStudentAsd4 s5(5, 35);
    TStudentAsd4 s6(6, 61);
    TStudentAsd4 s7(7, 47);
    TStudentAsd4 s8(8, 14);
    TStudentAsd4 s9(9, 61);// �����
    TStudentAsd4 s10(10, 80);
    TStudentAsd4 s11(11, 35);// �����
    TStudentAsd4 s12(12, 29);
    TStudentAsd4 s13(13, 76);
    TStudentAsd4 s14(14, 90);

    BinarySearchTree myTree;

    myTree.insert(s1);
    myTree.insert(s2);
    myTree.insert(s3);
    myTree.insert(s4);
    myTree.insert(s5);
    myTree.insert(s6);
    myTree.insert(s7);
    myTree.insert(s8);
    myTree.insert(s9);
    myTree.insert(s10);
    myTree.insert(s11);
    myTree.insert(s12);
    myTree.insert(s13);
    myTree.insert(s14);

    cout << "myTree.size(): " << myTree.size() << " myTree.height(): " << myTree.height() << endl;
   // cout << "inOrderTraversal: " << endl;
   // myTree.inOrderTraversal(myTree.node);
    cout << "preOrderTraversal: " << endl;
    myTree.preOrderTraversal(myTree.node, "top");

    cout << "minimum: " << endl;
    NodeAsd4 *minNode = myTree.minimum(myTree.node);
    cout << "minNode = " << minNode->current.gpa <<  endl;

    cout << "findInRange: " << endl;
    int r = myTree.findInRange(s7, s14);
    cout << "r = " << r <<  endl;

    myTree.erase(s14);
    myTree.erase(s13);
    myTree.erase(s12);
    myTree.erase(s11);
    myTree.erase(s10);
    myTree.erase(s9);
    myTree.erase(s8);
    myTree.erase(s7);
    myTree.erase(s6);
    myTree.erase(s5);
    myTree.erase(s4);
    myTree.erase(s3);
    myTree.erase(s1);
    myTree.erase(s2);

    cout << "myTree.size(): " << myTree.size() << " myTree.height(): " << myTree.height() << endl;
    cout << "preOrderTraversal: " << endl;
    myTree.preOrderTraversal(myTree.node, "top");

    return 0;
}

bool testBinarySearchTree() {
    srand(time(NULL));
    const int iters = 80000;
    const int keysAmount = iters * 2;
    const int itersToRangeQueries = 1;//000;

    vector<StudentAsd4> data(keysAmount);
    vector<StudentAsd4> dataToInsert(iters);
    vector<StudentAsd4> dataToErase(iters);
    vector<StudentAsd4> dataToFind(iters);
    vector<pair<StudentAsd4, StudentAsd4>> dataToRangeQueries;

    for (int i = 0; i < keysAmount; i++) {
        data[i] = StudentAsd4(i);
    }

    for (int i = 0; i < iters; i++) {
        dataToInsert[i] = data[generateRandLong() % keysAmount];
        dataToErase[i] = data[generateRandLong() % keysAmount];
        dataToFind[i] = data[generateRandLong() % keysAmount];
    }

    /*for (int i = 0; i < 50; i++) {
        dataToErase[i] = data[generateRandLong() % keysAmount];
    }*/

    for (int i = 0; i < itersToRangeQueries; i++) {
        StudentAsd4 minData = data[generateRandLong() % keysAmount];//StudentAsd4(i);
        StudentAsd4 maxData = data[generateRandLong() % keysAmount];//StudentAsd4(i);

        if (maxData < minData) {
            swap(minData, maxData);
        }

        dataToRangeQueries.push_back({minData, maxData});
    }

    BinarySearchTree myTree;
    clock_t myStart = clock();

    cout << "myTree.insert" << endl;
    for (int i = 0; i < iters; i++) {
        myTree.insert(dataToInsert[i]);
    }
    cout << "myTree.size(): " << myTree.size() << endl;
    /*cout << "inOrderTraversal: " << endl;
    myTree.inOrderTraversal(myTree.node);*/
    //cout << "preOrderTraversal: " << endl;
    //myTree.preOrderTraversal(myTree.node, "top");

    int myInsertSize = myTree.size();
    int myTreeHeight = myTree.height();
    int optimalTreeHeight = log2(myInsertSize) + 1;
    cout << "myTree.erase" << endl;
    for (int i = 0; i < iters; i++) {
        myTree.erase(dataToErase[i]);
    }
    cout << "after erase myTree.size(): " << myTree.size() << endl;
    //cout << "preOrderTraversal: " << endl;
    //myTree.preOrderTraversal(myTree.node, "top");

    int myEraseSize = myInsertSize - myTree.size();
    int myFoundAmount = 0;
    for (int i = 0; i < iters; i++) {
        if (myTree.find(dataToFind[i])) {
            myFoundAmount++;
        }
    }

    clock_t myEnd = clock();
    float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;
    set<StudentAsd4> stlTree;
    clock_t stlStart = clock();

    for (int i = 0; i < iters; i++) {
        stlTree.insert(dataToInsert[i]);
    }

    int stlInsertSize = stlTree.size();
    for (int i = 0; i < iters; i++) {
        stlTree.erase(dataToErase[i]);
    }

    int stlEraseSize = stlInsertSize - stlTree.size();
    int stlFoundAmount = 0;
    for (int i = 0; i < iters; i++)  {
        if (stlTree.find(dataToFind[i]) != stlTree.end()) {
            stlFoundAmount++;
        }
    }

    clock_t stlEnd = clock();
    float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;
    clock_t myRangeStart = clock();
    int myRangeFoundAmount = 0;
    cout << "myTree.findInRange" << endl;
    /*cout << "inOrderTraversal: " << endl;
    myTree.inOrderTraversal(myTree.node);*/

    for (int i = 0; i < itersToRangeQueries; i++) {
        //cout << dataToRangeQueries[i].first.gpa << " " << dataToRangeQueries[i].second.gpa << endl;
        myRangeFoundAmount += myTree.findInRange(dataToRangeQueries[i].first, dataToRangeQueries[i].second);
    }

    clock_t myRangeEnd = clock();
    float myRangeTime = (float(myRangeEnd - myRangeStart)) / CLOCKS_PER_SEC;
    clock_t stlRangeStart = clock();
    int stlRangeFoundAmount = 0;
    for (int i = 0; i < itersToRangeQueries; i++) {
        const auto& low = stlTree.lower_bound(dataToRangeQueries[i].first);
        const auto& up = stlTree.upper_bound(dataToRangeQueries[i].second);
        stlRangeFoundAmount += distance(low, up);
    }

    cout << endl;

    clock_t stlRangeEnd = clock();
    float stlRangeTime = (float(stlRangeEnd - stlRangeStart)) / CLOCKS_PER_SEC;
    cout << "My BinaryTree: height = " << myTreeHeight << ", optimal height = " << optimalTreeHeight << endl;
    cout << "Time: " << myTime << ", size: " << myInsertSize << " - " << myEraseSize << ", found amount: " << myFoundAmount << endl;
    cout << "Range time: " << myRangeTime << ", range found amount: " << myRangeFoundAmount << endl << endl;

    cout << "STL Tree:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlInsertSize << " - " << stlEraseSize << ", found amount: " << stlFoundAmount << endl;
    cout << "Range time: " << stlRangeTime << ", range found amount: " << stlRangeFoundAmount << endl << endl;

    if (myInsertSize == stlInsertSize && myEraseSize == stlEraseSize
        && myFoundAmount == stlFoundAmount && myRangeFoundAmount == stlRangeFoundAmount) {
        cout << "The lab is completed" << endl;
        return true;
    }

    cerr << ":(" << endl;
    return false;
}

bool operator < (const StudentAsd4& arg, const StudentAsd4& arg1) {
    if (arg.gpa < arg1.gpa) {
        return 1;
    }
    return 0;
}

