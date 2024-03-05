#ifndef FILESSTRUCT_H_INCLUDED
#define FILESSTRUCT_H_INCLUDED

struct teacher {       //��������� ��������;
  char fio[10];      //�������
  char posada[20];   //������
  float salary;      //�������� �����
};

struct stud {          //��������� ��������;
  char fio[10];        //�������
  float bal;           //������� ���
  float stip;          //��������
};

struct subject {       //��������� ���������;
  char name[10];       //����� ���������
  teacher prepod;      //��������, �� ���� �������
  int stnum;  //������� ��������, �� �������� ���� ���������
  stud student[10];  //����� ��������, �� �������� �������
};

void mainFileStruct();
void input();
void list_prepod();
void list_student();
void read_from_file();
void maxbal();
void stipendia();
void fond();


#endif // FILESSTRUCT_H_INCLUDED
