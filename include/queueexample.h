#ifndef QUEUEEXAMPLE_H_INCLUDED
#define QUEUEEXAMPLE_H_INCLUDED

using namespace std;

const int QUEUE_SIZE = 5;

struct Film {
    string name;
    string genre;
    int time;
};

typedef struct Queue {
    Film elements[QUEUE_SIZE];
    int head;
    int tail;
} QFilms;

int queueMain();
void push(Queue *queue, Film film);
Film pop(Queue *queue);
bool empty(Queue *queue);
int size(Queue *queue);
void print(Queue *queue);
void print(Film film);
bool isFull(Queue *queue);

#endif // QUEUEEXAMPLE_H_INCLUDED
