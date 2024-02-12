#ifndef STRUCTEXAMPLE_H_INCLUDED
#define STRUCTEXAMPLE_H_INCLUDED

int structexampleMain();
int sum(int a, int b);

struct Time {
    int hour, min, sec;
    Time() {
        hour = min = sec = 0;
    }
    Time(int h, int m, int s) {
        hour = h; min = m; sec = s;
    }

    int getHour() {
        return hour;
    }
};

#endif // STRUCTEXAMPLE_H_INCLUDED
