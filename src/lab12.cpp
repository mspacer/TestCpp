#include<iostream>
#include<conio.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
//#include <string>
#include <fstream>

#include<lab12.h>

using namespace std;

FILE *fpLab12;           //покажчик на файл
char* fileNameLab12 = "data\\lab12.dat";
char* fileNameLab12copy = "data\\lab12copy.dat";
int countProduct;
long long currentPos;
int indexProduct;

int mainLab12() {
    cout << "Lab12" << endl;

    menuLab12();

    return 0;
}

void menuLab12() {
  currentPos = -1;
  indexProduct = -1;

  while (1) {
    system("cls");
    cout<<"          MENU  \n"<<endl;
    cout<<"1. Database input by keyboard."<<endl;
    cout<<"2. Read data from file."<<endl;
    cout<<"3. Add product."<<endl;;
    cout<<"4. Search product."<<endl;;
    cout<<"5. Insert after."<<endl;
    cout<<"6. Search after."<<endl;
    cout<<"7. Edit product."<<endl;
    cout<<"8. Delete product."<<endl;
    cout<<"9. Exit"<<endl;
    cout<<endl;
    int key;             //номер пункту меню
    cout<< "Choosen menu item:";
    cin>>key;
    system("cls");
    switch(key) {        // вибір функції реалізації меню
      case 1:  {
          inputLab12();
          break;
          }

      case 2:  {
          readLab12Data(0);
          break;
          }
      case 3:  {
          addNewProduct();
          break;
          }
      case 4:  {
          searchProduct();
          break;
          }
      case 5:  {
          insertAfter();
          break;
          }
      case 6:  {
          searchAfter();
          break;
          }
      case 7:  {
          editProduct2();
          break;
          }
      case 8:  {
          deleteProduct();
          break;
          }
      case 9:  {
          exit (0);
          break;
          }
      default: {
          cout<<"Try another time...";
          getch();
          break;
          }
    }
  }
}

void inputLab12() {
  TProduct product;    //масив дисциплін
  char answer_firm, answer_product;
  countProduct = 0;

  fpLab12 = fopen(fileNameLab12, "wb");

  if (fpLab12 != NULL) {           //якщо файл уже існує
    remove(fileNameLab12);   //знищення файлу
  }

  addProduct();
  fclose(fpLab12); //закриття файлу

  getch(); //чекати натискання клавіші
}

//------------читання даних з файлу----------------------
void readLab12Data(long long position) {
  TProduct product;
  countProduct = 0;

  if (!(fpLab12 = fopen(fileNameLab12, "rb"))) {
        cerr << "File do not exist!";
        getch();
        return;
  } else {
    cout << setw(20) << "It is file:" << endl;

    if (position > 0) {
        fpos_t *pos = &position;
        int set = fsetpos(fpLab12, pos);
         cout << "set pos " << pos << " is " << set << endl;
    }

    fread(&product, sizeof(TProduct), 1, fpLab12);

    //char* currentFirm = (char*) malloc(20*sizeof(char));
    //currentFirm[0] = '\0';
    char currentFirm[21];
    currentFirm[20] = '\0';
    //читання даних з 1 предмету
    while (!feof(fpLab12)) {  //виведення даних з файлу
      countProduct++;
      //cout << "currentFirm " << currentFirm << " &currentFirm " << *currentFirm << endl;
      //cout << "product.firm.name " << product.firm.name << endl;
      //cout << "strcmp() " << strcmp(currentFirm, product.firm.name) << endl;
      if (strcmp(currentFirm, product.firm.name) != 0) {
          //cout << "Firm:" <<endl;
          cout.setf(ios::left);
          cout << setw(12) << product.firm.name << endl;
          strcpy(currentFirm, product.firm.name);
      }

      /*cout << "____Product:" << endl;
      cout << "            name----------------cost------days of delivery"<<endl;

      cout.setf(ios::left);
      cout << "            "
           << setw(20) << product.name
           << setw(10) << product.cost
                       << product.daysOfDelivery
           << endl;
        */
      product.print();

      fread(&product, sizeof(TProduct), 1, fpLab12); //читання даних з 1 предмету
    }

    //delete currentFirm;
    fclose(fpLab12); //закриття файлу
  }

  getch(); //чекати натискання клавіші
}

int addNewProduct() {
    if (!(fpLab12 = fopen(fileNameLab12, "ab"))) {
        cerr << "File do not exist!";
        return -1;
    }

 /*   if (countProduct == 0) {
        TProduct product;
        while (!feof(fpLab12)) {  //виведення даних з файлу
            countProduct++;
            fread(&product, sizeof(TProduct), 1, fpLab12); //читання даних з 1 предмету
        }
    } else {
       fseek(fpLab12, countProduct*sizeof(TProduct), SEEK_SET);
    }
    cout << countProduct << endl;
    getch();
*/
    addProduct();
    fclose(fpLab12);

    getch(); //чекати натискання клавіші
    return 0;
}

int addProduct() {
  TProduct product;
  char answer_firm, answer_product;

  do {
      system("cls");
      //string line;
      cout << "Firm name" << endl;
      //cin >> product.firm.name;
      //getline(cin, product.firm.name);
      fflush(stdin);
      gets(product.firm.name);

      do {
        cout << "product's name:" << endl;
        //cin >> product.name;
        //getline(cin, product.name);
        fflush(stdin);
        gets(product.name);

        cout << "product's cost:" << endl;
        cin >> product.cost;
        cout << "product's count days delivery:" << endl;
        cin >> product.daysOfDelivery;

        fwrite(&product, sizeof(TProduct), 1, fpLab12); //запис предмету до файлу
        countProduct++;

        cout << "any product else? y/n" << endl;
        answer_product = getch();
        //cout << "answer_product " << answer_product << endl;
      } while(answer_product != 'n');

      //кількість студентів по дисципліні
      cout << "contunue input firm? y/n" << endl;
      answer_firm = getch();
        //cout << "answer_firm " << answer_firm << endl;
    } while (answer_firm != 'n');

    return 0;
}

int searchProduct() {
    if (!(fpLab12 = fopen(fileNameLab12, "r"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "search product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    TProduct product = doSearchProduct(productName);
    if (strlen(product.name) > 0) {
            product.print();
    } else {
          cout << "Product " << productName << " not found." << endl;
    }

    getch(); //чекати натискання клавіші
    return 0;
}

TProduct doSearchProduct(char* name) {
    TProduct product;
    product.name[0] = '\0';
    bool found = false;
    fread(&product, sizeof(TProduct), 1, fpLab12);

    while (!feof(fpLab12)) {  //виведення даних з файлу
      indexProduct++;

      if (strcmp(name, product.name) == 0) {
         found = true;
         currentPos = ftell(fpLab12);
        break;
      }

      fread(&product, sizeof(TProduct), 1, fpLab12); //читання даних з 1 предмету
    }

    if (found)
        return product;
    else {
        indexProduct = -1;
        return {};
    }
}

int insertAfter() {
    if (!(fpLab12 = fopen(fileNameLab12, "r"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "search product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    TProduct product;

    if (currentPos < 0) {
        doSearchProduct(productName);
    }
    cout << "currentPos: " << currentPos << endl;

    if (currentPos < 0) {
        cout << "Product " << productName << " not found." << endl;
    } else {
        //вставка в конец
        fpLab12 = fopen(fileNameLab12, "a+b");
        fpos_t *pos = &currentPos;
        int set = fsetpos(fpLab12, pos);
        if (set == 0) {
            addProduct();
        } else {
            cout << errno << endl;
        }
    }

    fclose(fpLab12);
    getch(); //чекати натискання клавіші
    return 0;
}

int searchAfter() {
    if (!(fpLab12 = fopen(fileNameLab12, "r"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "search product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    doSearchProduct(productName);
    readLab12Data(currentPos);

    getch(); //чекати натискання клавіші
    return 0;
}

int editProduct() {
    if (!(fpLab12 = fopen(fileNameLab12, "r"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "modify product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    TProduct product = doSearchProduct(productName);

    /*if (indexProduct < 0) {
        product = doSearchProduct(productName);
    }*/
    cout << "indexProduct: " << indexProduct << endl;
    fclose(fpLab12);

    if (indexProduct < 0) {
        cout << "Product " << productName << " not found." << endl;
    } else {
        product.cost = 77.7;
        product.daysOfDelivery = 123;

        product.print();

        fstream f;
        f.open(fileNameLab12, ios::binary|ios::in|ios::out);
        f.seekg(indexProduct * sizeof(TProduct)); // устанавливаем указатель на нужную запись
        f.write((const char*)&product, sizeof(TProduct));
        f.close();
    }

    getch(); //чекати натискання клавіші
    return 0;
}

int editProduct2() {
    TProduct product;
    cout << "sizeof(product): " << sizeof(product) << endl;

    if (!(fpLab12 = fopen(fileNameLab12, "rb"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "modify product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    TProduct prd;
    fread(&prd, sizeof(TProduct), 1, fpLab12);
    fpos_t pos;
    long long curPos;
    while (!feof(fpLab12)) {  //виведення даних з файлу
      if (strcmp(productName, prd.name) == 0) {
         curPos = ftell(fpLab12);
         cout << "editProduct: " << curPos <<  endl;
         int rez = fgetpos(fpLab12, &pos);
         cout << "editProduct-1: " << rez << " " << pos << endl;

         /*for(int i = 0; i < strlen(prd.name); i++) {
            product.name[i] = prd.name[i];
         }*/
         memccpy (product.name, prd.name, '\0', Length_Name);
         product.cost = prd.cost;
         product.daysOfDelivery = prd.daysOfDelivery;
         product.firm = prd.firm;
        //break;
      }

      fread(&prd, sizeof(TProduct), 1, fpLab12);
    }

    //curPos = ftell(fpLab12);
    //cout << "editProduct-2: " << curPos <<  endl;

    fclose(fpLab12);

    product.print();

    char name[Length_Name] = "pr6_f1";
    memccpy (product.name, name, '\0', Length_Name);
    product.cost = 7;
    product.daysOfDelivery = 8;

    fpLab12 = fopen(fileNameLab12, "r+b");
    //int rez = fseek(fpLab12, curPos, SEEK_SET);
    //cout << "rez: " << rez << pos << endl;

     if (fseek (fpLab12, curPos - sizeof(TProduct), SEEK_SET)==0) {
        cout  << "установлено" << endl;
        fwrite(&product, sizeof(TProduct), 1, fpLab12); //запис предмету до файлу
        //fwrite(&product, 0, 1, fpLab12); //запис предмету до файлу
     }

    fclose(fpLab12);
    getch(); //чекати натискання клавіші
    return 0;
}

int deleteProduct() {
    if (!(fpLab12 = fopen(fileNameLab12, "r"))) {
        cerr << "File do not exist!";
        return -1;
    }

    cout << "delete product name:" << endl;
    char productName[20];
    fflush(stdin);
    gets(productName);

    TProduct product;

    if (indexProduct < 0) {
        product = doSearchProduct(productName);
    }
    cout << "indexProduct: " << indexProduct << endl;
    fclose(fpLab12);

    if (indexProduct < 0) {
        cout << "Product " << productName << " not found." << endl;
    } else {
        fstream fin;
        ofstream fout;
        long length, n;

        fin.open(fileNameLab12, ios::binary|ios::in);
        fin.seekg(0, ios::end);
        length = fin.tellg();
        n = length / sizeof(TProduct);
        fin.seekg(0, ios::beg);
        cout << "n = " << n << " indexProduct = " << indexProduct <<  endl;

        fout.open(fileNameLab12copy, ios::binary);

        for (int i = 0; i < n; i++) {
            fin.read((char*)&product, sizeof(TProduct));
            cout << "product.name: " << product.name ;
            if (i != indexProduct) {
                cout << " copied";
                fout.write((const char*)&product, sizeof(TProduct));
            }
            cout <<  endl;
        }
        // не работает
        //f.write(NULL, sizeof(TProduct));

        fin.close();
        fout.close();

        /*fin.seekg(0, ios::beg);
        fout.seekg(0, ios::beg);
        for (int i = 0; i < n-1; i++) {
            fout.read((char*)&product, sizeof(TProduct));
            fin.write((const char*)&product, sizeof(TProduct));
        }*/

        if (rename(fileNameLab12, "data\\lab12tmp.dat") != 0)
            perror("Error renaming file");
        else {
            if (rename(fileNameLab12copy, fileNameLab12) != 0) {
                perror("Error renaming file");
                rename("data\\lab12tmp.dat", fileNameLab12);
            } else {
                cout << "File renamed successfully";
            }
        }

        remove("data\\lab12tmp.dat");
    }

    indexProduct = -1;
    getch(); //чекати натискання клавіші
    return 0;
}
