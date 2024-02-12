#include <iostream>
#include <structexample.h>

using namespace std;

int sum(int a, int b) {
    cout << "a + b = " << a + b << endl;
}

int structexampleMain() {
    Time x;
    cout << x.getHour() << endl;
    Time t (2,5,6);
    cout << t.getHour() << endl;

    return 0;
}
