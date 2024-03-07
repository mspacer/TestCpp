#ifndef ASD2LR3_H_INCLUDED
#define ASD2LR3_H_INCLUDED

using namespace std;

typedef struct StudentAsd3 {
    int deadline;
    int interest;
    int useful;
    int difficult;

    StudentAsd3(int dd, int intr, int usf, int dff) {
        deadline = dd;
        interest = intr;
        useful = usf;
        difficult = dff;
    };

    bool operator == (const StudentAsd3& arg) {
        //cout << "operator == exec" << endl;
        return deadline == arg.deadline && interest == arg.interest && useful == arg.useful && difficult == arg.difficult;
    }

    bool operator < (const StudentAsd3& arg) {
        //cout << "operator < exec" << endl;
        bool _deadline = deadline > arg.deadline;
        if (deadline < arg.deadline) {
            return 1;
        }
        if (deadline == arg.deadline && interest < arg.interest) {
            return 1;
        }

        if (deadline == arg.deadline && interest == arg.interest &&
            useful < arg.useful) {
            return 1;
        }

        if (deadline == arg.deadline && interest == arg.interest && useful == arg.useful &&
            difficult < arg.difficult) {
            return 1;
        }

        return 0;
    }

} TStudentAsd3;

int asd2Lr3Main();

#endif // ASD2LR3_H_INCLUDED
