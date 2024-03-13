#ifndef ASD2LR3_H_INCLUDED
#define ASD2LR3_H_INCLUDED

using namespace std;

typedef struct StudentAsd3 {
    int deadline;
    int interest;
    int useful;
    int difficult;

    StudentAsd3() {
        //cout << "StudentAsd3()" << endl;
        deadline = rand()%100;
        interest = rand()%100;
        useful = rand()%100;
        difficult = rand()%100;
    }

    StudentAsd3(int dd, int intr, int usf, int dff) {
        //cout << "StudentAsd3(.....)" << endl;
        deadline = dd;
        interest = intr;
        useful = usf;
        difficult = dff;
    };

    bool operator == (const StudentAsd3& arg) {
        //cout << "operator == exec" << endl;
        return deadline == arg.deadline /*&& interest == arg.interest && useful == arg.useful && difficult == arg.difficult*/;
    }

    bool operator < (const StudentAsd3& arg) {
        //cout << "operator < exec" << endl;
        if (deadline < arg.deadline) {
            return 1;
        }
        /*if (deadline == arg.deadline && interest < arg.interest) {
            return 1;
        }

        if (deadline == arg.deadline && interest == arg.interest &&
            useful < arg.useful) {
            return 1;
        }

        if (deadline == arg.deadline && interest == arg.interest && useful == arg.useful &&
            difficult < arg.difficult) {
            return 1;
        }*/

        return 0;
    }

    void print() {
        cout << "deadline: " << deadline << endl;
    }

} TStudentAsd3;

typedef struct PriorityQueue {
  TStudentAsd3* students;
  int count;
  int capacity = 20;

  PriorityQueue() {
      //cout << "PriorityQueue()" << endl;
      count = 0;
      students = (TStudentAsd3*) malloc(capacity*sizeof(TStudentAsd3));
      for (int i = 0; i < capacity; i++) {
            ;//cout << "i: "  << i << " students: " << &students[i] << endl;
      }
  }

  int getParent(int index); // знайти індекс батьківського вузла
  int getLeftChild(int index); // знайти індекс лівого дочірнього вузла
  int getRightChild(int index); // знайти індекс правого дочірнього вузла
  void siftUp(int index); // просіяти елемент вверх по дереву
  void siftDown(int index); // просіяти елемент вниз по дереву
  int push(TStudentAsd3 object); // додати новий елемент в чергу
  TStudentAsd3 top(); // отримати верхній елемент з черги
  int pop(); //видалити верхній елемент з черги
  int size(); // знайти кількість елементів в черзі
  void empty(); // перевірити чергу на пустоту
  void checkCapacity();
  void pqPrint();

} TPriorityQueue;

int asd2Lr3Main();
bool testPriorityQueue();

#endif // ASD2LR3_H_INCLUDED
