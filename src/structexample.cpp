#include <iostream>
#include <structexample.h>

using namespace std;

int structexampleMain() {
    Time x;
    cout << x.getHour() << endl << endl;
    Time t (2,5,6);
    cout << "sizeof(t): " << sizeof(t) << endl;
    cout << "t " << &t << " " << &t.hour << " " << &t.min << " " << &t.sec << endl;

    Time t1;
    cout << "t1 " << &t1 << " " << &t1.hour << " " << &t1.min << " " << &t1.sec << endl;
    cout << "t1 " << t1.hour << " " << t1.min << " " << t1.sec << endl;
    t1 = t;
    cout << "t1 " << &t1 << " " << &t1.hour << " " << &t1.min << " " << &t1.sec << endl << endl;
    t1.hour = 20;
    t.print();
    t1.print();

    Time* t3;
    //t3->print(); t3 == NULL
    cout << "&t3: " << &t3 << " " << t3 << " " << &t3->hour << " " << &t3->min << " " << &t3->sec << endl;
    Time* t4 = new Time(7,8,9);
    cout << "&t4: " << &t4 << " " << t4 << " " << &t4->hour << " " << &t4->min << " " << &t4->sec << endl << endl;
    t4->print();

    //t3 = 7;
    //*t3 = *t4; //ошибка, т.к. t3 не выделена память
    t3 = t4;
    cout << "&t3: " << &t3 << " " << t4 << " " << &t3->hour << " " << &t3->min << " " << &t3->sec << endl << endl;

    t3->hour = 22;
    t3->print();
    t4->print();

    int* pHour = &t3->hour;
    cout << "&pHour: " << &pHour << " " << pHour << " " << *pHour << endl << endl;

    delete t3;
    //delete t4; // ошибка программы т.к. t3, t4, pHour ссылаются на один объект, удаленный с t3
    //delete pHour;

   cout << "&t3: " << &t3 << " " << &t3->hour << " " << &t3->min << " " << &t3->sec << endl ;
   cout << "&t4: " << &t4 << " " << &t4->hour << " " << &t4->min << " " << &t4->sec << endl << endl;
   t3->print();
   t4->print();
    cout << "&pHour: " << &pHour << " " << pHour << " " << *pHour << endl << endl;

    cout << "__________________________________________________________________" <<  endl << endl;

    Time* pTimeArr = (Time*) malloc(3*sizeof(Time));
    cout << "&pTimeArr: " << &pTimeArr << " " << pTimeArr << endl
        << "&pTimeArr[0]: " << &pTimeArr[0] << endl
        << "&pTimeArr[1]: " << &pTimeArr[1] << endl
        << "&pTimeArr[2]: " << &pTimeArr[2] << endl;
    cout << "&pTimeArr[0]: " << &pTimeArr[0].hour << " " << &pTimeArr[0].min << " " << &pTimeArr[0].sec << endl;
    cout << "pTimeArr[0]: "; pTimeArr[0].print();

    t4 = new Time(7,8,9);
    cout << "&t4:          " << &t4 << " " << &t4->hour << " " << &t4->min << " " << &t4->sec << endl << endl;

    //*pTimeArr = *t4; // в отличии от ошибки в стр 29 pTimeArr память выделена. Значения копируются
    pTimeArr[0] = *t4;

    //pTimeArr = t4; // Допустимо, но меняется адрес массива, что ведет к ошибке в программе
    cout << "&pTimeArr: " << &pTimeArr << " " << pTimeArr << endl
        << "&pTimeArr[0]: " << &pTimeArr[0] << endl
        << "&pTimeArr[1]: " << &pTimeArr[1] << endl
        << "&pTimeArr[2]: " << &pTimeArr[2] << endl;

    t4->min = 51;
    cout << "t4: " << " "; t4->print();

    cout << "&pTimeArr[0]: " << &pTimeArr[0] << " " << &pTimeArr[0].hour << " " << &pTimeArr[0].min << " " << &pTimeArr[0].sec << endl << endl;
    cout << "pTimeArr[0]: " <<  " "; pTimeArr[0].print();

    pTimeArr[1] = TTime(1, 2, 3);
    cout << "pTimeArr[1]: " <<  " "; pTimeArr[1].print();

    Time* t5 = new Time(17,18,19);
    pTimeArr[2] = *t5;
    cout << "(pTimeArr + 2): " << " "; (pTimeArr + 2)->print();

    delete[] pTimeArr;

    cout << "t5: " << " "; t5->print();
    delete t5;
    cout << "t5: " << " "; t5->print();

    cout << "t4: " << " "; t4->print();
    cout << "pTimeArr[0]:    " << " ";  pTimeArr[0].print();
    cout << "(pTimeArr + 1): " << " "; (pTimeArr + 1)->print();
    cout << "(pTimeArr + 2): " << " "; (pTimeArr + 2)->print();

    delete t4;

    cout << "__________________________________________________________________" <<  endl << endl;

    DinamicArray* pDma = new DinamicArray();
    cout << "&pDma: " << &pDma << " "  << pDma << " " << &pDma->times << " " << sizeof(pDma->times[0]) << " " << &pDma->size << endl << endl;
    cout << "&pDma->times: " << pDma->times << " " << &pDma->times->hour << " " << &pDma->times->min << " " << &pDma->times->sec << endl ;
    cout << "&pDma->times[0]: " << &pDma->times[0] << " " << &pDma->times[0].hour << " " << &pDma->times[0].min << " " << &pDma->times[0].sec << endl ;
    cout << "&pDma->times[0]: " << pDma->times[0].hour << " " << pDma->times[0].min << " " << pDma->times[0].sec << endl;
    cout << "&pDma->times[1]: " << &pDma->times[1] << endl ;
    cout << "&pDma->times[2]: " << &pDma->times[2] << endl << endl;

    t4 = new Time(1, 2, 3);
    cout << "&t4: " << &t4 << " " << t4 << " " << &t4->hour << " " << &t4->min << " " << &t4->sec << endl << endl;

    pDma->times[0] = *t4;
    cout << "pDma->times[0] : " << " " ; pDma->times[0].print();
    cout << "&pDma->times[0]: " << &pDma->times[0] << " " << &pDma->times[0].hour << " " << &pDma->times[0].min << " " << &pDma->times[0].sec << endl ;

    delete pDma;
    delete t4;

    return 0;
}
