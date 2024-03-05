#ifndef LAB12_H_INCLUDED
#define LAB12_H_INCLUDED

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
