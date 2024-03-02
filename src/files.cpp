#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include<conio.h>

#include <fstream>

#include <files.h>

using namespace std;

FILE* fin, *fout; //покажчики на вхідний та вихідний файли
char fileName[2][20]; //назви вхідного та вихідного файлів

int mainFiles() {
    cout <<  "files" << endl;

    myExample();
    //pdfExample();

    return 1;
}

int myExample() {
    chooseName(1);
    //fin = fopen(fileName[1], "w"); //відкрити файл для запису
    //out2(fileName[1]);
    out3(fileName[1]);
    //fclose(fin);
}

//-----------------EXAMPLE--------------------------------------------------------------------------------------------------------------
void chooseName(int mode) {
    if (mode == 0 || mode == 2) {
        puts("enter name of file for write");
        fflush(stdin);
        gets(fileName[0]);
    }

    if (mode == 1 || mode == 2) {
        puts("enter name of file for read");
        fflush(stdin);
        gets(fileName[1]);
    }

}

//========= створення текстового файла =================
void createFile() {
    char answer; //ознака завершення введення даних
    char s[100]; //рядок, у який вводять дані

    fflush(stdin);
    if (strcmp(fileName[1], "") == 0) {
        chooseName(0);
    }

    fout = fopen(fileName[1], "w"); //відкрити файл для запису

    do {
        puts("input string:"); //вивести запит користувачу
        fflush(stdin);
        gets(s); //ввести з клавіатури рядок
        fputs(s, fout); //записати рядок у файл
        fputc('\n', fout); //записати символ переведення курсору
        puts("continue ? [y/n]");
        answer = getch(); //задати ознаку продовження введення
    } while ((answer != 'n') && (answer != 'N'));

    fclose(fout); //закрити файл для запису
}

//===== додавання до рядка найдовшого слова ============
void addWord() {
    int max; //довжина найдовшого слова
    char word[20]; //найдовше слово у рядку
    char sa[100], sb[100]; //зчитаний і записаний рядки
    char* p; //покажчик на поточне слово
    char* spacer=". ,:"; //роздільники слів у рядках

    fin = fopen(fileName[1],"r"); //відкрити файл для читання

    while (!feof(fin)) {//доки не кінець вхідного файлу
        fgets(sa, 100, fin); //читати рядок із файлу

        if (feof(fin)) {
            break; //якщо кінець файлу, вийти з циклу
        }

        strcpy(sb, sa); //скопіювати зчитаний з файлу рядок
        p = strtok(sb, spacer); //перше слово
        max = strlen(p); //вважати найдовшим

        while (p != NULL) {//доки у рядку є слова
            if (max <= strlen(p)) {//якщо є слово довше за прийняте
                max = strlen(p); //вважати поточне слово найдовшим
                strcpy(word,p); //запам’ятати найдовше слово

                if (word[strlen(word)-1] == '\n') {//якщо словоостаннє в рядку, то його останній символ
                    word[strlen(word)-1] = ' '; //замінити на пробіл
                }
            }

            p = strtok(NULL,spacer); //визначити наступне слово
        }

        sa[strlen(sa) - 1] = ' '; //видалити символ кінця рядка
        strcat(sa, word); //дописати слово у кінець рядка
//        fputs(sa, fout); //записати рядок у новий файл
//        fputc('\n', fout); //записати символ нового рядка у файл
    } //кінець циклу читання файлу

    fclose(fin);

    fout = fopen(fileName[0],"w"); //відкрити файл для запису
    fputs(sa, fout); //записати рядок у новий файл
    fputc('\n', fout); //записати символ нового рядка у файл
    fclose(fout);


    fout = fopen(fileName[0], "r");
    out(fout);
    getch();
    fclose(fout);
}

//======== виведення файлу на екран ====================
void out(FILE* f) { //параметр f – покажчик на файл, що виводиться
    char s[100]; //рядок, зчитаний з файлу

    while(!feof(f)) {//доки не кінець файлу
        fgets(s,100,f); //читати рядок файлу

        if (feof(f)) {
            break; //якщо кінець файлу, вийти з циклу
        }

        puts(s); //вивести рядок на екран
    }

    fclose(f);
}

void out2(char *filename) { //параметр f – покажчик на файл, що виводиться
    wifstream file(filename);
    //wifstream file("Text.txt");
    wstring str;
    while (getline(file, str)) {
		wcout << str << endl;
	}
//    fclose(f);
}

void out3(char *filename) { //параметр f – покажчик на файл, що виводиться
    ifstream file(filename);
    //wifstream file("Text.txt");
    string str;
    int i = 1;
    while (getline(file, str)) {
		cout << i++ << ") " << str << endl;
	}
//    fclose(f);
}
//============головна програма ========================
int pdfExample() {
    char filename[20];
    puts("Search longest word in strings from file");
    system("pause");

    while (1) {
        system("cls");
        cout << " MENU \n" << endl;
        cout << "1. Choose name of file" << endl;
        cout << "2. Create file" << endl;
        cout << "3. Read data from file" << endl;
        cout << "4. Add word to string" << endl;
        cout << "5. Exit" << endl;
        cout << endl;

        int key; //номер пункту меню
        cout << "Choosen menu item:";
        cin >> key;
        system("cls");

        switch (key) {//вибір функції реалізації меню
            case 1: {
                chooseName(2);
                break;
                }
            case 2: {
                chooseName(0);
                createFile();
                break;
                }
            case 3: {
                puts("choose name of file:");
                chooseName(1);

            /*    if ((fin = fopen(fileName[0], "r")) == NULL) {//можливість відкриття файлу
                    puts("file not created");
                    strcpy(filename, fileName[1]);
                } else {
                    if ((fin = fopen(fileName[1], "r")) == NULL) {
                        puts("file not created");
                        strcpy(filename, fileName[0]);
                    }
                }

                if ((fin = fopen(filename, "r")) == NULL) {
                    puts("return menu");
                } else {
                    cout << "text from file '" << filename << "':" <<endl;
                    out(fin);
                } */

                if ((fin = fopen(fileName[1], "r")) == NULL) {
                        cout << fileName[1] << "not found" <<endl;
                } else {
                    cout << "text from file '" << fileName[1] << "':" <<endl;
                    out(fin);
                }

                getch();
                break;
            }
            case 4: {
                chooseName(2);
                addWord();
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
    }//while
}
