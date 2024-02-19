#ifndef STRUCTEXAMPLE_H_INCLUDED
#define STRUCTEXAMPLE_H_INCLUDED

using namespace std;

int structexampleMain();

typedef struct Time {
    int hour, min, sec;
    Time() {
        hour = min = sec = 0;
    }
    Time(int h, int m, int s) {
        hour = h; min = m; sec = s;
    }

    void print() {
        cout << hour << " " << min << " " << sec << endl << endl;
    }
    int getHour() {
        return hour;
    }
}TTime;

struct DinamicArray {
    Time* times;
    int size;

    DinamicArray() {
        size = 3;
        times = (Time*) malloc(3*sizeof(Time));
    }
};

#endif // STRUCTEXAMPLE_H_INCLUDED
