#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cstdlib>
#include<conio.h>

#include <fstream>

#include <files.h>

using namespace std;

FILE* fin, *fout; //��������� �� ������� �� �������� �����
char fileName[2][20]; //����� �������� �� ��������� �����

int mainFiles() {
    cout <<  "files" << endl;

    myExample();
    //pdfExample();

    return 1;
}

int myExample() {
    chooseName(1);
    //fin = fopen(fileName[1], "w"); //������� ���� ��� ������
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

//========= ��������� ���������� ����� =================
void createFile() {
    char answer; //������ ���������� �������� �����
    char s[100]; //�����, � ���� ������� ���

    fflush(stdin);
    if (strcmp(fileName[1], "") == 0) {
        chooseName(0);
    }

    fout = fopen(fileName[1], "w"); //������� ���� ��� ������

    do {
        puts("input string:"); //������� ����� �����������
        fflush(stdin);
        gets(s); //������ � ��������� �����
        fputs(s, fout); //�������� ����� � ����
        fputc('\n', fout); //�������� ������ ����������� �������
        puts("continue ? [y/n]");
        answer = getch(); //������ ������ ����������� ��������
    } while ((answer != 'n') && (answer != 'N'));

    fclose(fout); //������� ���� ��� ������
}

//===== ��������� �� ����� ���������� ����� ============
void addWord() {
    int max; //������� ���������� �����
    char word[20]; //�������� ����� � �����
    char sa[100], sb[100]; //�������� � ��������� �����
    char* p; //�������� �� ������� �����
    char* spacer=". ,:"; //���������� ��� � ������

    fin = fopen(fileName[1],"r"); //������� ���� ��� �������

    while (!feof(fin)) {//���� �� ����� �������� �����
        fgets(sa, 100, fin); //������ ����� �� �����

        if (feof(fin)) {
            break; //���� ����� �����, ����� � �����
        }

        strcpy(sb, sa); //��������� �������� � ����� �����
        p = strtok(sb, spacer); //����� �����
        max = strlen(p); //������� ���������

        while (p != NULL) {//���� � ����� � �����
            if (max <= strlen(p)) {//���� � ����� ����� �� ��������
                max = strlen(p); //������� ������� ����� ���������
                strcpy(word,p); //���������� �������� �����

                if (word[strlen(word)-1] == '\n') {//���� ����������� � �����, �� ���� ������� ������
                    word[strlen(word)-1] = ' '; //������� �� �����
                }
            }

            p = strtok(NULL,spacer); //��������� �������� �����
        }

        sa[strlen(sa) - 1] = ' '; //�������� ������ ���� �����
        strcat(sa, word); //�������� ����� � ����� �����
//        fputs(sa, fout); //�������� ����� � ����� ����
//        fputc('\n', fout); //�������� ������ ������ ����� � ����
    } //����� ����� ������� �����

    fclose(fin);

    fout = fopen(fileName[0],"w"); //������� ���� ��� ������
    fputs(sa, fout); //�������� ����� � ����� ����
    fputc('\n', fout); //�������� ������ ������ ����� � ����
    fclose(fout);


    fout = fopen(fileName[0], "r");
    out(fout);
    getch();
    fclose(fout);
}

//======== ��������� ����� �� ����� ====================
void out(FILE* f) { //�������� f � �������� �� ����, �� ����������
    char s[100]; //�����, �������� � �����

    while(!feof(f)) {//���� �� ����� �����
        fgets(s,100,f); //������ ����� �����

        if (feof(f)) {
            break; //���� ����� �����, ����� � �����
        }

        puts(s); //������� ����� �� �����
    }

    fclose(f);
}

void out2(char *filename) { //�������� f � �������� �� ����, �� ����������
    wifstream file(filename);
    //wifstream file("Text.txt");
    wstring str;
    while (getline(file, str)) {
		wcout << str << endl;
	}
//    fclose(f);
}

void out3(char *filename) { //�������� f � �������� �� ����, �� ����������
    ifstream file(filename);
    //wifstream file("Text.txt");
    string str;
    int i = 1;
    while (getline(file, str)) {
		cout << i++ << ") " << str << endl;
	}
//    fclose(f);
}
//============������� �������� ========================
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

        int key; //����� ������ ����
        cout << "Choosen menu item:";
        cin >> key;
        system("cls");

        switch (key) {//���� ������� ��������� ����
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

            /*    if ((fin = fopen(fileName[0], "r")) == NULL) {//��������� �������� �����
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
