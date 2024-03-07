#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>

#include <asd2lr3.h>

using namespace std;

int asd2Lr3Main() {
    cout << "ACD-3" << endl;

    struct StudentAsd3 s1(1, 2, 3, 5);

    struct StudentAsd3 s2(10, 1, 2, 4);

    bool b = s1 == s2;
    cout << "s1 == s2: " << b << endl;

    b = s1 < s2;
    cout << "s1 < s2: " << b << endl;

    return 0;
}
