#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <ctime>

#include <asd2lr3.h>

using namespace std;

int asd2Lr3Main() {
    cout << "ACD-3" << endl;

    TStudentAsd3 s0(94, 2, 3, 5);
    TStudentAsd3 s1(84, 1, 2, 4);
    TStudentAsd3 s2(38, 1, 2, 4);
    TStudentAsd3 s3(50, 1, 2, 4);
    TStudentAsd3 s4(75, 1, 2, 4);
    TStudentAsd3 s5(35, 1, 2, 4);
    TStudentAsd3 s6(29, 1, 2, 4);
    TStudentAsd3 s7(47, 1, 2, 4);
    TStudentAsd3 s8(14, 1, 2, 4);
    TStudentAsd3 s9(61, 1, 2, 4);

    TStudentAsd3 s10(76, 1, 2, 4);
    TStudentAsd3 s11(100, 1, 2, 4);
    cout << "s11 " << &s11 << " s11.deadline " << &s11.deadline << endl;
    TStudentAsd3 s12(76, 1, 2, 4);

    bool b = s1 == s2;
    cout << "s1 == s2: " << b << endl;

    b = s1 < s2;
    cout << "s1 < s2: " << b << endl;

    int i1 = 6;
    int j1 = (i1 - 1)/2;
    cout << "j1 = " << j1 << endl;

    cout << endl << "----------PriorityQueue----------" << endl;

    TPriorityQueue prQueue;
    prQueue.push(s0);
    prQueue.push(s1);
    prQueue.push(s2);
    prQueue.push(s3);
    prQueue.push(s4);
    prQueue.push(s5);
    prQueue.push(s6);
    prQueue.push(s7);
    prQueue.push(s8);
    prQueue.push(s9);

    prQueue.push(s10);
    prQueue.push(s11);
    prQueue.push(s12);

    cout << "after push: " << endl;
    prQueue.pqPrint();

    cout << "after pop: " << endl;
    prQueue.pop();


/*    for (int i = 0; i < 10; i++) {
        prQueue.push(TStudentAsd3());
    }*/
    prQueue.pqPrint();
    prQueue.empty();

    return 0;
}

bool operator < (const StudentAsd3& arg, const StudentAsd3& arg1) {
    if (arg.deadline < arg1.deadline) {
        return 1;
    }

    return 0;
}

//---------------------------PriorityQueue---------------------------------------------------------------------------------------------------------------------
int TPriorityQueue::getParent(int index) {
    if (index == 0)
        return -1;
    else
        return (index - 1)/2;
}

int TPriorityQueue::getLeftChild(int index) {
    int leftIndex = 2*index + 1;
    if (leftIndex < count)
        return leftIndex;
    else
        return index;
}

int TPriorityQueue::getRightChild(int index) {
    int rightIndex = 2*index + 2;
    if (rightIndex < count)
        return rightIndex;
    else
        return index;
}

void TPriorityQueue::siftUp(int index) {
    int i = getParent(index);
    //cout << "index: "  << index << " " << "i: "  << i << " " << endl;
    while(i >= 0) {
        //students[i].print();
        if (students[i] < students[index]) {
            TStudentAsd3 temp = students[i];
            students[i] = students[index];
            students[index] = temp;
            index = i;
            i = getParent(index);
        } else {
            break;
        }
    }
}

void TPriorityQueue::siftDown(int index) {
    int leftIndex = getLeftChild(index);
    int rightIndex = getRightChild(index);
    int replaceIndex = -1;

    if (students[index] < students[leftIndex] && students[index] < students[rightIndex]) {
        int indexMax = leftIndex;

        if (students[leftIndex] < students[rightIndex]) {
            indexMax = rightIndex;
        }

        replaceIndex = indexMax;
    } else
    if (students[index] < students[leftIndex]) {
        replaceIndex = leftIndex;
    } else
    if (students[index] < students[rightIndex]) {
        replaceIndex = rightIndex;
    }

    if (replaceIndex != -1) {
        TStudentAsd3 temp = students[index];
        students[index] = students[replaceIndex];
        students[replaceIndex] = temp;

        siftDown(replaceIndex);
    }
}

int TPriorityQueue::push(TStudentAsd3 object) {
//    cout << "push: " ;
//    object.print();

    students[count++] = object;
    siftUp(count - 1);
    checkCapacity();

    return 0;
}

TStudentAsd3 TPriorityQueue::top() {
    if (count > 0) {
        return students[0];
    }
    return {};
}

int TPriorityQueue::pop() {
    students[0] = students[count - 1];
    //TStudentAsd3* student = (students + (count - 1));
    //delete student;
    siftDown(0);

    count--;
    return 0;
}

int TPriorityQueue::size() {
   /* int _count = 0;
    int i = 0;
    while ((students + i) != nullptr) {
        _count++;
        i++;
    }
    if (_count != count) {
        cout << "error evaluate count" << endl;
    }
    */
    return count;
}

void TPriorityQueue::empty() {
    delete[] students;
}

void TPriorityQueue::checkCapacity() {
    if (count == capacity) {
        capacity = capacity*2;
        //cout << "capacity: " << capacity << endl;
        students = (TStudentAsd3*) realloc(students, capacity*sizeof(TStudentAsd3));
    }
}

void TPriorityQueue::pqPrint() {
    for (int i = 0; i < count; i++) {
        cout << "i: "  << i << " students: " << &students[i] << " ";
        students[i].print();
    }
}

//-----------------TEST-------------------------------------------------------------------------------------------------------------------------------------
template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue) {
    const int iters = 100000;
    clock_t timeStart = clock();

    for (int i = 0; i < iters; i++) {
        int insertDataAmount = rand() % 6 + 5;

        for (int j = 0; j < insertDataAmount; j++) {
            priorityQueue.push(StudentAsd3());
        }

        priorityQueue.top();
        priorityQueue.pop();
    }

    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return time;
}

bool testPriorityQueue() {
    srand(time(NULL));
    const int iters = 20000;
    PriorityQueue myPriorQueue;
    priority_queue<StudentAsd3> stlPriorQueue;
    bool isDataEqual = true;

    for (int i = 0; i < iters; i++) {
        int insertDataAmount = rand() % 6 + 5;

        for (int j = 0; j < insertDataAmount; j++) {
            StudentAsd3 randData = StudentAsd3();

            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }

        StudentAsd3 myTop = myPriorQueue.top();
        StudentAsd3 stlTop = stlPriorQueue.top();

        if (!(myTop == stlTop)) {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl << endl;
            myTop.print();
            stlTop.print();
            break;
        }

        int removeDataAmount = rand() % insertDataAmount;

        for (int j = 0; j < removeDataAmount; j++) {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }

    cout << "Next test...." << endl;

    int myQueueSize = myPriorQueue.size();
    int stlQueueSize = stlPriorQueue.size();
    float stlTime = testPriorityQueueSpeed<priority_queue<StudentAsd3>>(priority_queue<StudentAsd3>());
    float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());

    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;

    if (isDataEqual && myQueueSize == stlQueueSize) {
        cout << "The lab is completed" << endl << endl;
        return true;
    }
    cerr << ":(" << endl << endl;
    return false;
}
