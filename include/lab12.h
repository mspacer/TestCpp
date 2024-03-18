#ifndef LAB12_H_INCLUDED
#define LAB12_H_INCLUDED

#include<iomanip>
using namespace std;

typedef struct Firm {
    char name[20];
} TFirm;

typedef struct Product {
    char name[20];
    double cost;
    int daysOfDelivery;
    TFirm firm;
    Product() {
        name[0] = '\0';
        firm.name[0] = '\0';
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
int deleteProduct();

#endif // LAB12_H_INCLUDED
