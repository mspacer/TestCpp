#ifndef ASD2LR4_H_INCLUDED
#define ASD2LR4_H_INCLUDED

#include <string>
#include <vector>

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
        gpa = rand()%160000;
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
    StudentAsd4 current;
    NodeAsd4 *left;
    NodeAsd4 *right;
    NodeAsd4 *parent;
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
        return heightTree(node);
    }

    int heightTree(NodeAsd4 *_node) {
      if (_node == nullptr) {
          return 0;
      }

      int highLeft = heightTree(_node->left);
      int highRight = heightTree(_node->right);

      if (highLeft > highRight) {
        return highLeft + 1;
      } else {
          return highRight + 1;
      }
    }

    int insert(StudentAsd4 st) {
        //додати новий елемент в дерево (без повторень)
        /*cout << " insert : ";
        st.print();*/

        if(!find(st)) {
            if (node == nullptr) {
                node = addNode(st, node, nullptr);
            } else {
                addNode(st, node, nullptr);
            }
            count++;
        }
        return 1;
    }

    NodeAsd4* addNode(StudentAsd4 st, NodeAsd4 *_node, NodeAsd4 *_parent) {
        if (_node == nullptr) {
            _node = new NodeAsd4();
            _node->current = st;
            _node->left = nullptr;
            _node->right = nullptr;
            _node->parent = _parent;
        } else
        if (st < _node->current) {
            _node->left = addNode(st, _node->left, _node);
        } else {
            _node->right = addNode(st, _node->right, _node);
        }

        return _node;
    }

    bool find(StudentAsd4 st) {
        //перев≥рити на€вн≥сть елемента в дерев≥
        if (findInNode(st, node) == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    NodeAsd4* findInNode(StudentAsd4 st, NodeAsd4 *_node) {
        if (_node == nullptr) {
            return nullptr;
        } else
        if (st == _node->current) {
            /*cout << " found : ";
            st.print();*/
            return _node;
        }

        NodeAsd4 *found = nullptr;
        if (st < _node->current) {
            found = findInNode(st, _node->left);
        } else {
            found = findInNode(st, _node->right);
        }

        return found;
    }

    int erase(StudentAsd4 st) {
        //видалити елемент з дерева
        NodeAsd4 *found = findInNode(st, node);
        if (found != nullptr) {
           /* cout << "erase: ";
            found->current.print();
            if (found->parent != nullptr)
                cout << " parent: " << found->parent->current.gpa << endl; */

            eraseNode(node, found);
            //deleteNode(found->parent, st);
            count--;
        }

        return 1;
    }

    int eraseNode(NodeAsd4 *t, NodeAsd4 *v) { // t Ч дерево, v Ч удал€емый элемент
       NodeAsd4 *p = v->parent;                                  // предок удал€емого элемента
       if (v->left == nullptr && v->right == nullptr) {        // первый случай: удал€емый элемент - лист
           //cout << "1" << endl;

         if (p != nullptr && p->left != nullptr && p->left->current == v->current)
           p->left = nullptr;
         else
             if (p != nullptr && p->right != nullptr && p->right->current == v->current)
               p->right = nullptr;
             else
               node = nullptr;
       } else
        if (v->left == nullptr || v->right == nullptr) {    // второй случай: удал€емый элемент имеет одного потомка
          // cout << "2" << endl;

           if (v->left == nullptr) {
               if (p == nullptr)
                   node = v->right;
               else
               if (p->left != nullptr && p->left->current == v->current)
                   p->left = v->right;
               else
                   p->right = v->right;

               v->right->parent = p;
           } else {
               if (p == nullptr)
                   node = v->left;
               else
               if (p->left != nullptr && p->left->current == v->current)
                   p->left = v->left;
               else
                   p->right = v->left;

               v->left->parent = p;
           }
        } else {  // третий случай: удал€емый элемент имеет двух потомков
            // cout << "3" << endl;

             NodeAsd4 *successor = next(v);
            // cout << "successor: "; successor->current.print();
             v->current.gpa = successor->current.gpa;
             if (successor->parent->left == successor) {
                 successor->parent->left = successor->right;
                 if (successor->right != nullptr) {
                    successor->right->parent = successor->parent;
                 }
             } else {
               successor->parent->right = successor->right;
               if (successor->right != nullptr) {
                 successor->right->parent = successor->parent;
               }
             }
         }

        // cout << "erase ok" << endl;
    }

    NodeAsd4* next(NodeAsd4 *x) {
       if (x->right != nullptr)
          return minimum(x->right);

       NodeAsd4 *y = x->parent;
       while (y != nullptr && x == y->right) {
          x = y;
          y = y->parent;
       }
       return y;
    }

    NodeAsd4* minimum(NodeAsd4 *x) {
      if (x->left == nullptr) {
        return x;
      }
      return minimum(x->left);
    }

    NodeAsd4* deleteNode(NodeAsd4 *root,  StudentAsd4 st) {// корень поддерева, удал€емый ключ
      if (root == nullptr)
        return root;

      if (st < root->current)
         root->left = deleteNode(root->left, st);
      else if (!(st < root->current))
        root->right = deleteNode(root->right, st);
      else if (root->left != nullptr && root->right != nullptr) {
        root->current.gpa = minimum(root->right)->current.gpa;
        root->right = deleteNode(root->right, root->current.gpa);
      } else
        if (root->left != nullptr)
          root = root->left;
        else if (root->right != nullptr)
          root = root->right;
        else
          root = nullptr;

      return root;
    }

    int findInRange(StudentAsd4 minSt, StudentAsd4 maxSt) {
        int range = 0;
        calcRange(node, minSt, maxSt, &range);
        return range;
    }

    int calcRange(NodeAsd4 *_node, StudentAsd4 minSt, StudentAsd4 maxSt, int *r) {
        if (_node != nullptr) {
          calcRange(_node->left, minSt, maxSt, r);

          if (_node->current.gpa >= minSt.gpa &&  _node->current.gpa <= maxSt.gpa) {
            *r = *r + 1;
            //_node->current.print();
          }

          calcRange(_node->right, minSt, maxSt, r);
        }
        return 0;
    }

    int inOrderTraversal(NodeAsd4 *_node) {
        if (_node != nullptr) {
          inOrderTraversal(_node->left);
          _node->current.print();
          inOrderTraversal(_node->right);
        }
        return 0;
    }

    int preOrderTraversal(NodeAsd4 *_node, string pos) {
       if (_node != nullptr) {
           if (_node-> parent != nullptr) {
                cout << "parent " << _node->parent->current.gpa << " " ;
           }
           cout << "tree " << pos << " " ;
          _node->current.print();
          preOrderTraversal(_node->left, "left");
          preOrderTraversal(_node->right, "right");
       }
       return 0;
    }

} TBinarySearchTree;

int asd2Lr4Main();
bool testBinarySearchTree();

#endif // ASD2LR4_H_INCLUDED
