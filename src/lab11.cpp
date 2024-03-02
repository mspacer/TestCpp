#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include<conio.h>
#include <string.h>

#include <fstream>

#include <lab11.h>
#include <stringExample.h>

using namespace std;

char filesLab11[3][20] = {{"data\\f1.txt"}, {"data\\f2.txt"}}; //назви вхідного та вихідного файлів
//char filesLab11[3][20]; //назви вхідного та вихідного файлів
FILE* fin1Lab11, *fin2Lab11, *fresultLab11; //покажчики на вхідний та вихідний файли
char* fPath = "data\\";

int mainLab11() {
    cout <<  "Lab11" << endl;

    menu();

    return 1;
}

int menu() {
    while(1) {
        system("cls");
        cout << " MENU \n" << endl;
        cout << "1. Choose name of file" << endl;
        cout << "2. Создать первый файл" << endl;
        cout << "3. Создать второй файл" << endl;
        cout << "4. Создать третий файл" << endl;
        cout << "5. Exit" << endl;
        cout << endl;

        int key; //номер пункту меню
        cout << "Choosen menu item:";
        cin >> key;
        system("cls");

        switch (key) {//вибір функції реалізації меню
            case 1: {
                chooseFileName(0);
                chooseFileName(1);
                getch();
                break;
                }
            case 2: {
                chooseFileName(0);
                createFile(0);
                break;
                }
            case 3: {
                chooseFileName(1);
                createFile(1);
                break;
                }
            case 4: {
                chooseFileName(2);
                resultFile();
                break;
            }
            case 5: {
                exit(0);
                break;
                }
            default: {
                cout<<"Try another time...";
                getch();
                break;
                }
        }//switch
        //fflush(stdin);
    }//while
}

void chooseFileName(int mode) {
    if (mode == 2) {
        puts("enter name of file for write");
    } else {
        puts("enter name of file for read");
    }

    fflush(stdin);
    gets(filesLab11[mode]);
    strcatBegin2(filesLab11[mode], fPath);
    cout << "filesLab11[" << mode << "]: " << filesLab11[mode] << endl;
}

/*void openFile(int mode) {
    puts("enter name of file for read");
    fflush(stdin);
    gets(filesLab11[mode]);

    fin1Lab11 = fopen(filesLab11[mode], "r"); //відкрити файл для читання
    if (fin1Lab11 == NULL) {//можливість відкриття файлу
        cout << "File " << filesLab11[mode] << " not found." << endl;
        chooseFileName(mode);
    }
}*/

void createFile(int mode) {
    char answer; //ознака завершення введення даних
    char s[100]; //рядок, у який вводять дані

    fflush(stdin);
    fin1Lab11 = fopen(filesLab11[mode], "w"); //відкрити файл для запису

    do {
        puts("input string:"); //вивести запит користувачу
        fflush(stdin);
        gets(s); //ввести з клавіатури рядок
        fputs(s, fin1Lab11); //записати рядок у файл
        fputc('\n', fin1Lab11); //записати символ переведення курсору
        puts("continue ? [y/n]");
        answer = getch(); //задати ознаку продовження введення
    } while ((answer != 'n') && (answer != 'N'));

    fclose(fin1Lab11); //закрити файл для запису
}

int resultFile() {
    int n = 100;
    int m = 100;
    char sa[n+1], sb[n+1]; //зчитаний і записаний рядки
    char* spacer = " "; //роздільники слів у рядках
    char ** pSb = (char **) malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++) {
        pSb[i] = (char *)malloc(m*sizeof(char));
    }

    fin1Lab11 = fopen(filesLab11[0],"r"); //відкрити файл для читання
    fin2Lab11 = fopen(filesLab11[1],"r"); //відкрити файл для читання

    if (fin1Lab11 == NULL) {//можливість відкриття файлу
        cout << "Первый файл не найден" << endl;
        getch();
        return 0;
    }

    if (fin2Lab11 == NULL) {//можливість відкриття файлу
        cout << "Второй файл не найден" << endl;
        getch();
        return 0;
    }

    int line = 0;
    while (!feof(fin2Lab11)) {//доки не кінець вхідного файлу
        fgets(pSb[line], n, fin2Lab11); //читати рядок із файлу

        if (feof(fin2Lab11) || isEmptyStr(pSb[line])) {
            *pSb[line] = '\0';
            break; //якщо кінець файлу, вийти з циклу
        }

        line++;
    } //кінець циклу читання файлу


    fresultLab11 = fopen(filesLab11[2], "w"); //відкрити файл для запису

    line = 0;
    char word[100];
    while (!feof(fin1Lab11)) {//доки не кінець вхідного файлу
        fgets(sa, n, fin1Lab11); //читати рядок із файлу

        if (feof(fin1Lab11) || strlen(sa) == 0) {
            break; //якщо кінець файлу, вийти з циклу
        }

        if (strlen(pSb[line]) > 0) {
            if (sa[strlen(sa) - 1] == '\n') {//якщо словоостаннє в рядку, то його останній символ
                sa[strlen(sa) - 1] = ' '; //замінити на пробіл
            }

            strcat(sa, pSb[line]);
            sa[strlen(sa) - 1] = '\n';
        }
/*        strcpy(word, pSa[line]);
        //cout << word << " length: " <<  strlen(word) << endl;
        if (word[strlen(word)-1] == '\n') {//якщо словоостаннє в рядку, то його останній символ
            word[strlen(word)-1] = ' '; //замінити на пробіл
        }

        strcat(word, sb);
*/
        fputs(sa, fresultLab11); //записати рядок у новий файл

        line++;
    } //кінець циклу читання файлу

    for(int i = 0; i < n; i++) {
        if(*pSb[i] == '\0')
            break;
        if (strlen(pSb[i]) > 0)
            cout << i << ") " << pSb[i] << endl;
        free(pSb[i]);
    }

    free(pSb);
    fclose(fin1Lab11);
    fclose(fin2Lab11);
    fclose(fresultLab11);

    getch();
}

int resultFile2() {
    int n = 100;
    int m = 100;
    char sa[n+1], sb[n+1]; //зчитаний і записаний рядки
    char* spacer = " "; //роздільники слів у рядках

    char ** pSa = (char **) malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++) {
        pSa[i] = (char *)malloc(m*sizeof(char));
    }

    fin1Lab11 = fopen(filesLab11[0],"r"); //відкрити файл для читання
    fin2Lab11 = fopen(filesLab11[1],"r"); //відкрити файл для читання

    if (fin1Lab11 == NULL) {//можливість відкриття файлу
        cout << "Первый файл не найден" << endl;
        getch();
        return 0;
    }

    if (fin2Lab11 == NULL) {//можливість відкриття файлу
        cout << "Второй файл не найден" << endl;
        getch();
        return 0;
    }

    int line = 0;
    while (!feof(fin1Lab11)) {//доки не кінець вхідного файлу
        fgets(pSa[line], n, fin1Lab11); //читати рядок із файлу

        if (feof(fin1Lab11) || isEmptyStr(pSa[line])) {
            *pSa[line] = '\0';
            break; //якщо кінець файлу, вийти з циклу
        }

        line++;
    } //кінець циклу читання файлу


    fresultLab11 = fopen(filesLab11[2], "w"); //відкрити файл для запису

    line = 0;
    char word[100];
    while (!feof(fin2Lab11)) {//доки не кінець вхідного файлу
        fgets(sb, n, fin2Lab11); //читати рядок із файлу

        if (feof(fin2Lab11) || strlen(pSa[line]) == 0 ) {
            break; //якщо кінець файлу, вийти з циклу
        }
        strcpy(word, pSa[line]);
        //cout << word << " length: " <<  strlen(word) << endl;
        if (word[strlen(word)-1] == '\n') {//якщо словоостаннє в рядку, то його останній символ
            word[strlen(word)-1] = ' '; //замінити на пробіл
        }

        strcat(word, sb);
        fputs(word, fresultLab11); //записати рядок у новий файл

        line++;
    } //кінець циклу читання файлу

    for(int i = 0; i < n; i++) {
        if(*pSa[i] == '\0')
            break;
        //if (strlen(pSa[i]) > 0)
        //    cout << i << ") " << pSa[i] << endl;
        free(pSa[i]);
    }

    free(pSa);
    fclose(fin1Lab11);
    fclose(fin2Lab11);
    fclose(fresultLab11);

    getch();
}
