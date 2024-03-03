#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>

#include<filesStruct.h>

using namespace std;

int i,j;            //��������� ���������� � ��������
FILE *fp;           //�������� �� ����

//------------------�������� �����-----------------------
void input() {
  subject predmet[10];    //����� ��������
  char answer_prep, answer_stud;

  if (fp != NULL) {           //���� ���� ��� ����
    remove("fp.dat");   //�������� �����
  } else {
    fp = fopen("fp.dat", "wb");//�������� ����� ��� ������
    i = 0;                //��������� �������� ���������

    do {
      cout << "subject name" << endl;
      cin >> predmet[i].name;
      cout << "teacher's surname" << endl;
      cin >> predmet[i].prepod.fio;
      cout << "teacher's position" << endl;
      cin >> predmet[i].prepod.posada;
      cout << "teacher's salary" << endl;
      cin >> predmet[i].prepod.salary;
      j=0;

      do {
        cout << "student's surname" << endl;
        cin >> predmet[i].student[j].fio;
        cout << "student's ball on subject" << endl;
        cin >> predmet[i].student[j].bal;
        cout << "student's scholarship" << endl;
        cin >> predmet[i].student[j].stip;
        j++;

        cout << "any students else? y/n" << endl;
        answer_stud = getch();
      } while(answer_stud != 'n');

      predmet[i].stnum = j;

      //������� �������� �� ��������
      cout << "contunue input? y/n" << endl;
      answer_prep = getch();

      fwrite(&predmet[i], sizeof(subject), 1, fp); //����� �������� �� �����

      i++; //������� �� ������ ��������
    } while (answer_prep != 'n');

    fclose(fp); //�������� �����
  }

  getch(); //������ ���������� ������
}

//------------������� ����� � �����----------------------
void read_from_file() {
  subject predmet;

  if (!(fp = fopen("fp.dat", "rb"))) {
        cerr << "File do not exist!";
  } else {
    cout << setw(20) << "It is file:" << endl;

    //fseek(fp, 1*sizeof(subject), SEEK_SET);

    fread(&predmet, sizeof(subject), 1, fp);

    //������� ����� � 1 ��������
    while (!feof(fp)) {  //��������� ����� � �����
      cout << "subject------teacher----position-----salary" <<endl;
      cout.setf(ios::left);
      cout << setw(12) << predmet.name
           << setw(12) << predmet.prepod.fio
           << setw(13) << predmet.prepod.posada
           << setw(10) << predmet.prepod.salary << endl;

      cout << "____Students" << endl;
      cout << "    fio--------ball-----scholarship"<<endl;

      for (j = 0; j < predmet.stnum; j++) {//��������
        cout.setf(ios::left);
        cout << setw(12) << predmet.student[j].fio
             << setw(10) << predmet.student[j].bal
                         << predmet.student[j].stip << endl;
      }

      fread(&predmet, sizeof(subject), 1, fp); //������� ����� � 1 ��������
    }

    fclose(fp); //�������� �����
  }

  getch(); //������ ���������� ������
}

//-------------��������� ����� �� ����������-------------
void list_prepod() {
  subject predmet;

  if (!(fp=fopen("fp.dat","rb"))) {
        cerr<<"File do not exist!";
  } else {
    cout << "subject----teacher-----position-----salary\n";

    fread(&predmet, sizeof(subject), 1, fp);

    //������� ����� � 1 ��������
    while(!feof(fp)) {  //���� �� ����� �����
      cout.setf(ios::left);
      //��������� ����� �� ����������
      cout << setw(10) << predmet.name
           << setw(12) << predmet.prepod.fio
           << setw(14) << predmet.prepod.posada
                       << predmet.prepod.salary << endl;

      fread(&predmet, sizeof(subject), 1, fp); //������� ����� � 1 ��������
    }

    fclose(fp); //�������� �����
  }

  getch(); //������ ���������� ������
}

//-----------��������� ����� �� ���������----------------
void list_student() {
  subject predmet;                      //���������

  if (!(fp = fopen("fp.dat","rb"))) {
  //�������� ��������� ����� ��� �������
    cerr<<"File do not exist!";
  } else {
    cout<<"teacher----student-----ball---scholarship \n";

    fread(&predmet, sizeof(subject), 1, fp);

    //������� ����� � 1 ��������
    while (!feof(fp)) {
        cout<<predmet.prepod.fio<<endl;

        for (j = 0; j < predmet.stnum; j++) { //�������� �������� �� ���� ��������
            cout.setf(ios::left);
            //��������� ����� �� ���������
            cout << setw(12) << predmet.student[j].fio
                 << setw(10) << predmet.student[j].bal
                             << predmet.student[j].stip << endl;
        }

        fread(&predmet, sizeof(subject), 1, fp); //������� ����� � 1 ��������
    }

    fclose(fp); //�������� �����
  }

  getch();           //������ ���������� ������
}

//------- ��������� � �������� ������� �����-----------
void maxbal() {
  float sr[10];                   //������� ���
  subject predmet[15];            //����� ��������

  if (!(fp = fopen("fp.dat","rb"))) {
    cerr << "File do not exist!";
  } else {
    i = 0;
    fread(&predmet[i], sizeof(subject), 1, fp);

    //������� ����� � 1 ��������
    while(!feof(fp)) {
      sr[i]=0;
      for(j=0;j<predmet[i].stnum;j++)
      //�������� ��������
        sr[i]+=predmet[i].student[j].bal;
        //���� ���� �������� �� ��������
      sr[i]=float(sr[i])/predmet[i].stnum;
      //������� ��� �� ������ ��������
      i++;    //������� �� ���������� ��������
      fread(&predmet[i],sizeof(subject),1,fp);
      //������� ����� � 1 ��������
    }

    int kol_prep=i;               //������� ����������
    cout<<"  Subject\'s average ball"<<endl;

    for (i=0;i<kol_prep;i++) {
      cout.setf(ios::left);
      cout<<setw(10)<<predmet[i].name<<setw(5)<<sr[i]<< endl;
    }

    cout<<"subject with the highest ball: "<<endl;
    float max=sr[0];          //������������ ���
    int nomer_predmet=0;
    //����� ���������(���������) � ����� ��������
    for(i=1;i<kol_prep;i++) {  //�������� ��������
        if (max<sr[i]) {
          max=sr[i];
          //��������� ������������ ��� � ����� ���������
          nomer_predmet=i;
        }
    }
    cout<<"max ball="<<max<<" in subject   " << predmet[nomer_predmet].name
    << "  teacher " << predmet[nomer_predmet].prepod.fio << endl;
    fclose(fp);                   //�������� �����
  }
  getch();                   //������ ���������� ������
}

//-------------- ����������� ��������------------------
void stipendia() {
  float sum=0;
  //���� �������� �������� � ������� ����� ����� 3
  int k=0;
  //������� ������ ��� �������� � �������� �����
  int l=0;       //�������� ��� ��������
  subject predmet;        //�������
  stud s,tmp[10],stud_tmp[10];

  //������ ������ ��������
  //��������� ����� �� ��������� � ���������� �����
  //��� �������� �� ����� �� ����������
  if (!(fp=fopen("fp.dat","rb"))) {
    cerr<<"File do not exist!";
  } else {
    fread(&predmet,sizeof(subject),1,fp);
    while(!feof(fp)) {
      for(j=0;j<predmet.stnum;j++) {  //�������� �������� �� ���� ��������
        //��������� ������ ��������
        tmp[k]=predmet.student[j];
        k++;
      }
      fread(&predmet,sizeof(subject),1,fp);
    }
    fclose(fp);  //�������� �����
    //������� ��� �������� � ����������� �������� ����� ��������
    int kol[10];

    //�������� ��������, �� ����� ���� �������
    for (i=0;i<k;i++) { //�������� ������ ������ ��������
      stud_tmp[l].bal=0;
      //���� ���� ������ �������� �� ����� ���������
      kol[l]=0;
      //������� �������� ��� ������ ��������
      int f=0;     //��������� ������� ����� �� ��������
      for (j=0;j<i;j++) {
        //�������� �������� �������� ������ �� ������ ������
        if ((strcmp(tmp[i].fio,tmp[j].fio)==0))
            f=1;        //������� ��� ���������� � �����
      }

      if (f==0) { //������� �� �� ���������� � �����
        for (j=i;j<k;j++) { // �������� ������ �� ������ ������ �� ����
          if (strcmp(tmp[i].fio,tmp[j].fio) == 0) {
          //�� � ��� ����� ������� �� ������ ��������
            stud_tmp[l].bal+=tmp[j].bal;
            //����������� ���� �� ������ ��������
            strcpy(stud_tmp[l].fio, tmp[j].fio);
            //�����'����� ��������
            stud_tmp[l].stip=tmp[j].stip;
            //�����'����� ��������
            kol[l]++; //������� �� �������� ���������
          }
        }
        //������� ��� �������� �� ��� ���������
        stud_tmp[l].bal=float(stud_tmp[l].bal)/kol[l];
        l++;         //������� �� ���������� ��������
      }
    }

    int all_stud=l;     //�������� ������� ��������
    //���������� �������� �� �������
    for (i=0;i<all_stud;i++)
      for(j=i+1;j<all_stud;j++)
        if (strcmp(stud_tmp[i].fio,stud_tmp[j].fio) > 0) {
          s=stud_tmp[i];
          stud_tmp[i]=stud_tmp[j];
          stud_tmp[j]=s;
        }

    //��������� ����� ��� ��������� ������� ���
    //�� ��������� ��������
    cout<<"Array of students after sort"<<endl;
    cout<<"--student------average ball------scholarship" <<endl;
    for (i=0;i<all_stud;i++) {
      cout.setf(ios::left);
      cout<<setw(20)<<stud_tmp[i].fio<<setw(15)<<stud_tmp [i].bal<<stud_tmp[i].stip<<endl;
    }
    getch();

    //������� �������� � ������� ����� ����� 3
    j=0;                             //���� �������
    for (i=0;i<all_stud;i++) {
      if ((stud_tmp[i].bal>=0)&&(stud_tmp[i].bal<3)) {
        sum+=stud_tmp[i].stip;
        stud_tmp[i].stip=0;     //��������� �� ������䳿
        j++;
      }
    }

    for (i=0;i<all_stud;i++) {      //������� �� ������
      if ((stud_tmp[i].bal>=3)&&(stud_tmp[i].bal<=5)) {
        stud_tmp[i].stip=stud_tmp[i].stip+sum/(all_stud-j);
      }
    }
    //��������� ���������� ������䳿
    cout<<endl<<"Counted scholarship"<<endl;
    cout<<"--FIO------average ball------scholarship"<<endl;
    for(i=0;i<all_stud;i++) {
      cout.setf(ios::left);
      cout<<setw(15)<<stud_tmp[i].fio<<setw(15)<<stud_tmp [i].bal;
        if ((stud_tmp[i].bal>=3)&&(stud_tmp[i].bal<=5))
            cout<<stud_tmp[i].stip<<endl;
        else
            cout<<"has no scholarship"<<endl;
        //�������� �� ����������
    }
  }
  getch();                   //������ ���������� ������
}

//----------------������������� ����--------------------
void fond() {
  float fond_prep=0;   //���� ����������
  float fond_stip=0;   //������������� ����
  subject predmet;     //�������
  stud tmp[10];        //���������� ����� ��������

  if (!(fp=fopen("fp.dat","rb"))) {
    cerr<<"File do not exist!";
  } else {
    fread(&predmet,sizeof(subject),1,fp);
    int k=0;
    while(!feof(fp)) {
      fond_prep+=predmet.prepod.salary;
      for(j=0;j<predmet.stnum;j++)
      //�������� �������� �� ���� ��������
      {                  //��������� ������ ��������
        tmp[k]=predmet.student[j];
        k++;
      }
      fread(&predmet,sizeof(subject),1,fp);
    }
    fclose(fp);           //�������� �����

    for (i=0;i<k;i++) { //�������� ������ ������ ��������
      int f=0;      //��������� ������� ����� �� ��������
      for (j=0;j<i;j++) {//�������� �������� �������� �������� ������ ������
        if ((strcmp(tmp[i].fio,tmp[j].fio)==0))
            f=1;        //������� ��� ���������� � �����
      }
      if (f==0)  //������� �� �� ���������� � �����
        fond_stip+=tmp[i].stip;
    }
    cout<<"salary found ="<<fond_prep<<endl;
    cout<<"scholarship found ="<<fond_stip<<endl;

    if (fond_prep-fond_stip>0)
      cout<<"salary found is bigger "<<endl;
    else
      cout<<"salary found is smaller "<<endl;
  }
  getch();               //������ ���������� ������
}

//-------------------������� ��������--------------------
void mainFileStruct() {
  while (1) {
    system("cls");
    cout<<"          MENU  \n"<<endl;
    cout<<"1. Database input by keyboard."<<endl;
    cout<<"2. Read data from file."<<endl;
    cout<<"3. View teacher's database."<<endl;;
    cout<<"4. View student's database."<<endl;
    cout<<"5. List of subjects with the highest average ball."<<endl;
    cout<<"6. Scholarship."<<endl;
    cout<<"7. Scholarship found."<<endl;
    cout<<"8. Exit"<<endl;
    cout<<endl;
    int key;             //����� ������ ����
    cout<< "Choosen menu item:";
    cin>>key;
    system("cls");
    switch(key) {        // ���� ������� ��������� ����
      case 1:  {input();break;}
      case 2:  {read_from_file();break;}
      case 3:  {list_prepod();break;}
      case 4:  {list_student();break;}
      case 5:  {maxbal();break;}
      case 6:  {stipendia();break;}
      case 7:  {fond();break;}
      case 8:  {exit (0); break;}
      default: {cout<<"Try another time...";getch();break;}
    }
  }
}

