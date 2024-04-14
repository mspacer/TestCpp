#ifndef LAB12_H_INCLUDED
#define LAB12_H_INCLUDED

#include<iomanip>
using namespace std;

const int Length_Name = 20;

typedef struct Firm {
    char name[Length_Name];
    Firm() {
        name[0] = '\0';
    }
    Firm(char _name[Length_Name]) {
        for(int i = 0; i < strlen(name); i++) {
            name[i] = _name[i];
         }
    }
} TFirm;

typedef struct Product {
    char name[Length_Name];
    double cost;
    int daysOfDelivery;
    TFirm firm;
    Product() {
        name[0] = '\0';
    }

    Product(char _name[], double _cost, int daysOfD, Firm _firm) {
        memccpy (name, _name, '\0', Length_Name);
        cost = _cost;
        daysOfDelivery = daysOfD;
        firm = _firm;
    }

    void print() {
          cout << "____Product:" << endl;
          cout << "            name----------------cost------days of delivery----Firm"<<endl;

          cout.setf(ios::left);
          cout << "            "
               << setw(20) << name
               << setw(10) << cost
               << setw(16) << daysOfDelivery
                           << firm.name
               << endl;
    }

} TProduct;

int mainLab12();
void menuLab12();
void inputLab12();
void readLab12Data(long long pos);
int addNewProduct();
int addProduct();
int searchProduct();
TProduct doSearchProduct(char* name);
int insertAfter();
int searchAfter();
int editProduct();
int editProduct2();
int deleteProduct();

#endif // LAB12_H_INCLUDED
