#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <windows.h>
#include <inputexample.h>

using namespace std;

int inputExampleMain() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "¬ведите кол-во символов:" << endl;
    scanf("%d", &n); // ввод  переменной a с клавиатуры

    char temp[1000];
    char *p = (char*) malloc(1000);

    gets(p);
    int i=0;
    puts("¬вед≥ть р€док :");
    gets(p);
    while(p[i++]);
    printf("ƒовжина введеного р€дка = %i\n", i - 1);

    for (int i=0; *(p+i)!='\0'; i++){
        printf("%c", p[i]);
    }
    printf("\n");

    if (i < n) n = i - 1;

    char charArr[n];

    for (int i = 0; i < n; i++) {
        charArr[i] = p[i];
    }
    char *s = (char*) malloc(n);
    for (int j = 0; j < n ; j++) *(s+j) = *(p+j);

    for (int i = 0; i < n; i++) {
        //printf("%c", charArr[i]);
        printf("%c", s[i]);
    }
    printf("\n");

    char *ch = strrchr(p, 'a');
    //printf("%c\n", *ch);
    cout << "*ch " << &ch << " " << *ch << endl;
    for (int i=0; *(ch + i) != '\0'; i++){
        cout << ch[i];
    }
    cout << endl;

    //char ch2[] = {'1', '2', '3', '4', '5'};
    char *ch2 = "67567567";
    char *ch3 = strcat(ch, ch2);
    cout << "*ch3 " << &ch3 << " " << *ch3 << endl;
    for (int i=0; *(ch + i) != '\0'; i++){
        cout << ch[i];
    }
    cout << endl;
    for (int i=0; *(ch3 + i) != '\0'; i++){
        cout << ch3[i];
    }
    cout << endl;

    cout << "compare ch, ch3: " << strcmp(ch, ch3) << endl;
    cout << "compare ch2, ch3: " << strcmp(ch2, ch3) << endl;

    char *ch4 = (char*) malloc(2);
    char *ch5 = strncpy(ch4, ch3, 2);
    for (int i=0; i < 2; i++){
        cout << ch4[i];
    }
    cout << endl << endl << endl;

     cout << "lab" << endl;

    for (int i=0; *(ch3 + i) != '\0'; i++){
        cout << ch3[i];
    }
     cout << endl;

    char *ch6 = "ok";
    char *ch7 = strstr(ch3, ch6);
    int count = 0;
    for (int i=0; *(ch7 + i) != '\0'; i++){
        cout << ch7[i];
    }
    cout << endl;
    while (ch7 != NULL) {
        count++;
        ch7 = strstr((ch7+2), ch6);
    }
    cout << "count: " << count << endl;

    cout << "atof('23.56') " <<  atof("23.56") << endl;

    delete p;
    delete s;

    //cout << "It`s work" << endl;
/*    int n;
    cout << "¬ведите кол-во символов:" << endl;
    scanf("%d", &n); // ввод  переменной a с клавиатуры

    char charArr[n];

    cin.ignore();
    string strTemp;
    cout << "¬ведите строку из " << n << " символов:" << endl;
    getline(cin, strTemp);
    cout << "strTemp: " << strTemp << endl;

    char arr[strTemp.length() + 1];
    strcpy(charArr, strTemp.substr(0, n).c_str());
    cout<<"String to char array conversion:\n";
	for (int i = 0; i < n; i++)
		cout << charArr[i];
*/

/*    string s = "gdgdfdsf";
    for(int i = 0; i < s.length(); i++) {
        cout << s[i];
    }
*/

    return 1;
}

int inputExampleTask2() {
    string basis = "adeRRlfdSSghcVVokj";
    string result = "";

    int length = basis.length();
    int posFirst = 0;
    int posLast = length - 1;

    do {
        char prev = basis[posFirst];
        result.push_back(prev);
        for (int i = posFirst + 1; i < length; i++) {
            posFirst = i;
            char next = basis[i];
            if (next == prev) {
                result = result.substr(0, result.length() - 1) + "_";
                break;
            }
            prev = next;
            result.push_back(next);
        }
        posFirst++;

        prev = basis[posLast];
        result.push_back(prev);
        for (int i = posLast - 1; i >= posFirst; i--) {
            char next = basis[i];
            posLast = i;
            if (next == prev) {
                result = result.substr(0, result.length()-1) + "_";
                break;
            }
            prev = next;
            result.push_back(next);
        }
        posLast--;

    } while(posLast > posFirst);

    cout << "result: " << result << endl;

    return 1;
}

int inputExampleZero() {
    char arr[100], zero[]="zero";
    // arr[100] Ц р€док дов≥льних символ≥в;
    // р€док-зам≥на zero[]="zero"
    int i,j,temp;
    // i Ц л≥чильник циклу, ≥ндекс елементу масиву,
    // що дор≥внюЇ '0', запамТ€товуЇмо у зм≥нну temp.
    gets(arr);

    for(i=0; i<strlen(arr); i++) {
        if(arr[i] == '0') {
            temp=i; /* ≤ндекс елементу масиву, що дор≥внюЇ '0',
                    запамТ€товуЇмо у зм≥нну temp. ќск≥льки '0' Ц один символ, а р€док "zero" складаЇтьс€ з (strlen(zero)-1)
                    символ≥в (потр≥бно вставити р€док без символу зак≥нченн€ р€дка '\0'),
                    то сл≥д у вкладеному цикл≥ зсунути ус≥ символи, починаючи з символу '0' на (strlen(zero)-1) позиц≥ю вправо за допомогою циклу */
            for(j=strlen(arr); j>=i; j-- ){
                arr[j+strlen(zero)-1]=arr[j];
            }
            for(j=0; j<strlen(zero); j++, temp++)
                arr[temp]=zero[j];
            }
    }
    puts(arr);
    //getch();

    return 1;
}
