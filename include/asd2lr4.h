#ifndef ASD2LR4_H_INCLUDED
#define ASD2LR4_H_INCLUDED

#include <string>

using namespace std;

typedef struct StudentAsd4 {
    string name;
    int gpa;

    StudentAsd4() {
        name = "";
        gpa = -1;
    }

    StudentAsd4(int i) {
      //  cout << "StudentAsd4()" << endl;
        name = "student_" + to_string(i);
        gpa = rand()%100;
    }

    StudentAsd4(int i, int _gpa) {
        name = "student_" + to_string(i);
        gpa = _gpa;
    };

    bool operator == (const StudentAsd4& arg) {
        //cout << "operator == exec" << endl;
        return gpa == arg.gpa;
    }

    bool operator < (const StudentAsd4& arg) {
        //cout << "operator < exec" << endl;
        if (gpa < arg.gpa) {
            return 1;
        }
        return 0;
    }

    void print() {
        cout << "name: " << name << ", gpa: " << gpa << endl;
    }

} TStudentAsd4;

struct NodeAsd4 {
    StudentAsd4 *current;
    NodeAsd4 *left;
    NodeAsd4 *right;
};

typedef struct BinarySearchTree {
    NodeAsd4 *node;
    int count;

    BinarySearchTree() {
        count = 0;
        node = nullptr;
    }

    int size() {
        return count;
    }

    int height() {
        return 1;
    }

    int insert(StudentAsd4 st) {
        //додати новий елемент в дерево (без повторень)
        cout << " insert : ";
        st.print();

        if(!find(st)) {
            addNode(st, &node);
            count++;
        }

        return 1;
    }

    NodeAsd4* addNode(StudentAsd4 st, NodeAsd4 **_node) {
        if (*_node == nullptr) {
            *_node = new NodeAsd4();
            (*_node)->current = &st;
            (*_node)->left = nullptr;
            (*_node)->right = nullptr;
        } else
        if (st < *(*_node)->current) {
            (*_node)->left = addNode(st, &(*_node)->left);
        } else {
            (*_node)->right = addNode(st, &(*_node)->right);
        }

        return *_node;
    }

    bool find(StudentAsd4 st) {
        //перевірити наявність елемента в дереві
        return findInNode(st, node);
    }

    bool findInNode(StudentAsd4 st, NodeAsd4 *_node) {
        if (_node == nullptr) {
            return false;
        } else
        if (st == *_node->current) {
            cout << " found : ";
            st.print();
            return true;
        } else
        if (st < *_node->current) {
            findInNode(st, _node->left);
        } else {
            findInNode(st, _node->right);
        }
    }

    int erase(StudentAsd4 st) {
        //видалити елемент з дерева

        return 1;
    }

    int findInRange(StudentAsd4 minSt, StudentAsd4 maxSt) {
        return 1;
    }

} TBinarySearchTree;

int asd2Lr4Main();
bool testBinarySearchTree();

#endif // ASD2LR4_H_INCLUDED
