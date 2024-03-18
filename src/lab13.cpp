#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdarg.h>

#include <lab13.h>

#define PI 3.14159
#define MAX0(a, b) a >= b ? a : b
#define MAX1(a,b) ({int _a = (a), _b = (b); _a > _b ? _a : _b; })
#define MAX2(a, b) (a >= b ? a : b)
#define SWAP(type, a, b) type tmp = a; a = b; b = tmp;
#define SWAP1(type, a, b) ({ type tmp = a; b = a; })
//decltype � �++ ���� �����, ��� typeof � ����� C
#define SWAP2(a, b) ({  \
  decltype(a) tmp = a; \
  a = b;               \
  b = tmp; })

 //�������� ������� ����� ���������� � ������, ������� ����� ��� ���� '#':
#define PRINT_VALUE(value) printf("Value of %s is %d\n", #value, value);
//�������� ����� ��������� � ����-�� ���, ����� ��������� ����� �������������. ��� ����� ����� ���������� � ���, � ��� �� ��� ���������, ����� ��������� '##':
#define PRINT_VALUE2(number) printf("%d\n", value_##number);

#define PRINT_VALUE3() { printf("%s\n", "str1"); \
  printf("%s\n", "str2"); }

#define DEF_SUM(type) type sum_##type (type a, type b) { \
  type result = a + b; \
  return result; \
}

#define DEBUG

#define N 15 // ��������� ������������ � ���������������
// ������ � ���������� � ���������� �������� �����
#define SQR(x) (x)*(x)
// ������ ���������� ���������� � ���� �����
#define MAX(y,z) ((y)>(z))?(y):(z) //������ �� ������� �����
// ��������� ����������� �� �������� ������ �����
// ��������������� ������ ����������� ������� '\'
#define KTPR(w) puts("control output"); \
printf(#w"=%d\n",w)
// ������ '#' ��������������� ��� �ᒺ������ �����
// ��������� �����������
#define REZPR(w) puts("rezult :");\
printf(#w"=%f\n",(float)w)
// ��������� �������� ������� �����
#define SQCIRCLE(r) (3.14*SQR(r)) //����� ����


DEF_SUM(int)
DEF_SUM(float)
DEF_SUM(double)

using namespace std;

int mainLab13() {
    cout << "���� 13" << endl << endl;

    int r = 11;
    double area = 2 * PI * r * r;
    cout << "area: " << area << endl;

    #undef PI
    //cout << "PI: " << PI << endl; //������ ���������� ����� #undef PI

    int num1 = 2;
    int num2 = 5;
    SWAP(int, num1, num2)
    //SWAP(float, num1, num2) - error: conflicting declaration 'float tmp'
    cout << "tmp: " << tmp << ", num1: " << num1 << ", num2: " << num2  << endl;
    SWAP1(int, num1, num2);
    cout << "tmp: " << tmp << ", num1: " << num1 << ", num2: " << num2  << endl;
    SWAP2(num1, num2);
    cout << "tmp: " << tmp << ", num1: " << num1 << ", num2: " << num2  << endl;

    int v = 5;
    PRINT_VALUE(v)  // -> Value of v is 5

    int value_one = 10, value_two = 20;
    PRINT_VALUE2(one)  // -> 10
    PRINT_VALUE2(two)  // -> 20

    //1. ����������� �������� �� ������ ���� ��������� � ������ �������.
    int x = 1, y = 5;
    int max = MAX0(++x, --y); //int max = ++x >= --y ? ++x : --y;
    cout << "max: " << max << endl; //max = 3
    x = 1; y = 5;
    max = MAX1(++x, --y);
    cout << "max: " << max << endl;

    //2. ��� ��������� ������� � ��� ������ ������ ���� ��������� � ������.
    int result = 5 + MAX0(1, 4); //int result = 5 + 1 > 4 ? 1 : 4;
    cout << "result: " << result << endl; // result = 1
    result = 5 + (MAX0(1, 4));
    cout << "result: " << result << endl; // result = 9
    result = 5 + MAX2(1, 4);
    cout << "result: " << result << endl; // result = 9

    //3. ������������� ������� ������ ����� ���� ������� ���������.
    if (result == 2) PRINT_VALUE3();

    //4. ����������� �� ������������ ����

    cout << sum_int(1, 2) << endl;
    cout << sum_float(2.4, 6.3) << endl;
    cout << sum_double(1.43434, 2.546656) << endl;

    example1();
    example2();

    return 0;
}


int example1() {
  cout << endl << "example1()" << endl;

  puts("Using macros and preprocessing directives");
  int a, b, c, // ���� ��� ����������
  a_kvadr, // ����� ��� ���������� �������� �����
  b_kvadr, // ����� ��� ���������� �������� �����
  maxim; // ����������� �������� ����� ����� �����
  char ch; // ������� �� ��������� ��� ����������� ��������
  float rad, s; // ����� � ����� ����

  do {
    #if N < 10
        // ���� ����� �������, �� ����������� �������� � ����� �����
        puts("define maximum of three numbers");
        puts("Input 3 integer numbers");
        scanf("%d", &a); // �������� �����
        KTPR(a); // ������ ��������� �����
        scanf("%d", &b);
        KTPR(b);
        scanf("%d", &c);
        KTPR(c);
        a_kvadr = SQR(a); // ������ ���������� �������� �����
        KTPR(a_kvadr);
        b_kvadr = SQR(b);
        KTPR(b_kvadr);
        maxim = MAX(a_kvadr, b_kvadr);
        // ����� ���������� � ���� �����
        maxim = MAX(maxim, SQR(c));
        REZPR(maxim); // ������ ��������� ����������
    #else
        // ���������� ���� ������� ��������, ���� N >= 10
        puts("Define area of a circle");
        puts("Input radius of circle");
        scanf("%f", &rad);
        s = SQCIRCLE(rad);
        REZPR(s);
    #endif // ���������� ������ ���������

    puts ("Repeat? y / n");
    ch=getch();
  } while (ch=='y');

  return 0;
}

int example2(void) {
  cout << endl << "example2()" << endl;

  puts("function with a variable number of arguments");
  // ������ � 3 ������ (-1 ��������������� �� ���������)
  printf("Average(2,3,4,-1) is: %f\n", average(2,3,4,-1));
  // ������ � 4 ������
  printf("Average(5,7,9,12,-1) is: %f\n", average(5,7,9,12,-1));
  // ������ ������ � ����������� -1
  printf("Average(-1) is: %f\n", average(-1));
  //�������� ���������� ���� �� ��������� ����-��� ������
  while(!kbhit());
}

//==== ������� ������ ������� ������ ����� ����� ====
float average(int first, ... ) {
  //first - ������ ��������
  int count = 0;
  int sum = 0, i = first;
  va_list marker;
  va_start(marker, first); // ����������� ���������

  while(i != -1) {
      #ifdef DEBUG
      cout << "i: " << i << endl;
      #endif // DEBUG
      sum += i; // ����������� ���� ���������
      count++; // ���������� ������� ���������
      // ���������� ���������� ���������
      i = va_arg(marker, int);
  }
  va_end(marker);
  #ifdef DEBUG
  cout << "sum: " << sum << ", count: " << count << endl;
  #endif // DEBUG
  float rez = (float) sum / count;
  return(sum ? rez : 0);
}
