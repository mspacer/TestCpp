#ifndef FILESSTRUCT_H_INCLUDED
#define FILESSTRUCT_H_INCLUDED

struct teacher {       //структура викладач;
  char fio[10];      //прізвище
  char posada[20];   //посада
  float salary;      //заробітна плата
};

struct stud {          //структура студента;
  char fio[10];        //прізвище
  float bal;           //середній бал
  float stip;          //стипендія
};

struct subject {       //структура дисципліни;
  char name[10];       //назва дисципліни
  teacher prepod;      //викладач, що читає предмет
  int stnum;  //кількість студентів, що вивчають дану дисципліну
  stud student[10];  //масив студентів, що вивчають предмет
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
