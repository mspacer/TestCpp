#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include<conio.h>
#include <lab11.h>

using namespace std;

FILE* fin, *fout; //��������� �� ������� �� �������� �����
char fileName[2][20]; //����� �������� �� ��������� �����

int mainLab11() {
    cout <<  "Lab11" << endl;

    mainExample();

    return 1;
}


//-----------------EXAMPLE--------------------------------------------------------------------------------------------------------------
void chooseName() {
    puts("enter name of file for write");
    fflush(stdin);
    gets(fileName[0]);
    puts("enter name of file for read");
    fflush(stdin);
    gets(fileName[1]);
}

//========= ��������� ���������� ����� =================
void createFile() {
    char answer; //������ ���������� �������� �����
    char s[100]; //�����, � ���� ������� ���

    fflush(stdin);
    if (strcmp(fileName[0], "") == 0) {
        chooseName();
    }
    fout = fopen(fileName[0],"w"); //������� ���� ��� ������

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

    fin = fopen(fileName[0],"r"); //������� ���� ��� �������
    fout = fopen(fileName[1],"w"); //������� ���� ��� ������

    while (!feof(fin)) {//���� �� ����� �������� �����
        fgets(sa, 100, fin); //������ ����� �� �����

        if (feof(fin)) {
                break; //���� ����� �����, ����� � �����
        }

        strcpy(sb,sa); //��������� �������� � ����� �����
        p = strtok(sb,spacer); //����� �����
        max = strlen(p); //������� ���������

        while (p != NULL) {//���� � ����� � �����
            if(max <= strlen(p)) {//���� � ����� ����� �� ��������
                max = strlen(p); //������� ������� ����� ���������
                strcpy(word,p); //���������� �������� �����

                if (word[strlen(word)-1] == '\n') {//���� ����������� � �����, �� ���� ������� ������
                    word[strlen(word)-1] = ' '; //������� �� �����
                }
            }

            p=strtok(NULL,spacer); //��������� �������� �����
        }

        sa[strlen(sa) - 1] = ' '; //�������� ������ ���� �����
        strcat(sa, word); //�������� ����� � ����� �����
        fputs(sa, fout); //�������� ����� � ����� ����
        fputc('\n', fout); //�������� ������ ������ ����� � ����
    } //����� ����� ������� �����

    fclose(fin);
    fclose(fout);
    fout = fopen(fileName[1], "r");
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

//============������� �������� ========================
int mainExample() {
    char filename[20];
    puts("Search longest word in strings from file");
    system("pause");
    while (1) {
        system("cls");
        cout<<" MENU \n"<<endl;
        cout<<"1. Choose name of file"<<endl;
        cout<<"2. Create file"<<endl;
        cout<<"3. Read data from file"<<endl;
        cout<<"4. Add word to string"<<endl;;
        cout<<"5. Exit"<<endl;
        cout<<endl;

        int key; //����� ������ ����
        cout<< "Choosen menu item:";
        cin>>key;
        system("cls");

        switch(key) {//���� ������� ��������� ����
            case 1: {
                chooseName();
                break;
                }
            case 2: {
                createFile();
                break;
                }
            case 3: {
                puts("choose name of file:");
                chooseName();

                if ((fin = fopen(fileName[0], "r")) == NULL) {//��������� �������� �����
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
                    cout<<"text from file '" << filename << "':" <<endl;
                    out(fin);
                }

                getch();
                break;
            }
            case 4: {
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
