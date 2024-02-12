#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fibonachy.h>

using namespace std;

int fibonachyMain()
{
    cout << "Hello world!" << endl;

    int b[10]; // массив

    b[0] = 11;
    cout <<  b[0] << endl;

    int *t = b; // указатель на массив
    t[1] = 22;
    cout <<  b[1] << endl;

    initArray(b); // инициализация в функции
    cout <<  b[2] << endl;

    printf("%f\n", 0.8 + 0.4);

    string s = "0";
    //s = 1 + s;
    printf("%s\n", s);

    int i1 = 1;
    i1 <<= 5;
    printf("i1 %d\n", i1);
    pringByte(i1);

    pringByte(65);

    int i2 = 65|i1;
    printf("i2 %d\n", i2);
    pringByte(i2);

    printf("\n");
    pringByte(1993);

    printf("\n");
    pringByte(93);

    int count = fibonach(0, 0 + 0, 10, 1);
    cout << "final count = " << count << endl;

    cout << endl << "Eratosfen" << endl;
    //eratosfen(20);
    eratosfen2();

    cout << endl << "Rest" << endl;
    int rest = 7%4;
     printf("%d\n", 7%4);

    return 0;
}

void initArray(int *u) {
    u[2] = 33;
}

void pringByte1(int b) {
  //char strByte[16];
  string s = "";
  for (int i = 0; i < 16; i++) {
    if (i%4 == 0) {
        s = " " + s;
    }
        //printf("%c", ' ');
    //printf("%c", (b & 0x8000) ? '1' : '0');
    string bit = (b & 1) ? "1" : "0";
    s =  bit +  s;
    //strByte[i] = (b & 0x8000) ? '1' : '0';
    b >>= 1;
    if (b == 0)
        break;
  }
  cout << s << endl;
/*  for (int i = 0; i < 16; i++) {
      if (i%4 == 0)
        printf("%c", ' ');
     printf("%c", strByte[i]);
  }*/
  printf("\n");
}

void pringByte(int b) {
  string s = "";
  int i = 0;
  do {
    if (b & 1) {
        s =  "1" +  s;
    } else {
        s =  "0" +  s;
    }
    i++;
    if (i%4 == 0) {
        s =  " " +  s;
        i = 0;
    }
    b >>= 1;
  } while (b > 0);

  for (int j= 0; j < 4 - i; j++) {
    s =  "0" +  s;
  }
  /*int rest = s.length()%4;
  for (int i = 0; i < 4 - rest; i++) {
    s =  "0" +  s;
  }
  for(int i = 0; i < s.length(); ++i) {
    if (i%4 == 0 && i > 0) {
        cout << " ";
    }
    cout << s[i];
  }
  cout << endl;*/
  cout << s << endl;
}

int fibonach(int n0, int n1, int to, int count) {
    int i = count;
    printf("n0 = %d, n1 = %d\n", n0, n1);
    if (n1 == 0) {
        count = fibonach(0, 0 + 1, to, count+1);
    } else if ((n0 + n1) < to) {
        count = fibonach(n1, n0 + n1, to, count+1);
    }
    printf("%d\n", i);
    return count;
}

void eratosfen(int n) {
    bool simple[n];
    int digits[n];
    for (int i = 0; i < n; i++) {
        simple[i] = true;
        digits[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (simple[i] == true) {
            for (int j = 0; j <= n; j++) {
                int p = i*i + j*i;
                if (p < n) {
                    simple[p] = false;
                } else {
                    break;
                }
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        if (simple[i] == true)
            printf("%d, ", digits[i]);
    }
}

void eratosfen2() {
 int s = 38;
 int count = 0;
 bool p[s];
 for (int i = 0; i < s; i++){
   p[i] = true; // установка значение массива
 }
 for (int i = 2; i <= sqrt(s); i++){
     if (p[i] == true) {
            // определение простых чисел
             for (int j = pow(i,2); j <= s; j += i){
                 p[j] = false;
             }
      }
  }

  cout << endl;
  for (int i = 0; i <= s; i++) {
     if (p[i] == true) {
        count++;
        cout << i << ", ";
     }
  }
  cout << endl << "count = " << count << endl;
}
