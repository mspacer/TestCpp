#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queueexample.h>

using namespace std;

int queueMain()
{
    cout << "Queue!" << endl;
    for (int i = 0; i <= QUEUE_SIZE; i++) {
        cout << i << "(i + 1) % QUEUE_SIZE = " << (i + 1) % QUEUE_SIZE << endl;
    }

    QFilms *queue = new (nothrow) QFilms;
    queue->head = -1, queue->tail = -1;
    Film films[10] = {};
    films[0] = {"A", "action", 120};
    films[1] = {"B", "comedy", 60};
    films[2] = {"C", "drama", 140};
    films[3] = {"D", "fantasy", 300};
    films[4] = {"E", "science-fiction", 200};
    films[5] = {"F", "action", 1200};
    films[6] = {"G", "comedy", 600};
    films[7] = {"H", "drama", 1400};
    films[8] = {"I", "fantasy", 3000};
    films[9] = {"J", "science-fiction", 2000 };

    for(int i = 0; i < 2; i++) {
        push(queue, films[i] );
    }
    print(queue);

//    Film film1 = pop(queue);
//    print(film1);
//    print(queue);

    int n = size(queue);
    for(int i = 0; i < 4; i++){
        push(queue, films[n + i]);
    }
    print(queue);

    Film film1 = pop(queue);
    print(film1);
    Film film2 = pop(queue);
    print(film2);
    print(queue);

    if (film1.time < film2.time){
        push(queue, film1);
    } else{
        push(queue, film2);
    }
    push(queue, films[8]);
    print(queue);

    pop(queue);
    pop(queue);
    pop(queue);
    pop(queue);
    pop(queue);

    print(queue);

    delete queue;
    return 0;
}

void push(Queue *queue, Film film) {
    if (isFull(queue)) {
        cout << "Overflow! (stack is full)" << endl;
    } else {
        if (queue->head == -1) queue->head = 0;
        queue->tail = (queue->tail + 1) % QUEUE_SIZE;
        queue->elements[queue->tail] = film;
        cout << "push size(queue) = " << size(queue) << ", queue->tail = " << queue->tail << ", queue->head = " << queue->head << endl;
    }
}

Film pop(Queue *queue) {
    if (empty(queue))
        return {};
    Film film = queue->elements[queue->head];
    if (queue->head == queue->tail) {
      queue->head = -1;
      queue->tail = -1;
    } else {
        queue->head = (queue->head + 1) % QUEUE_SIZE;
    }

    cout << "pop size(queue) = " << size(queue) << ", queue->tail = " << queue->tail << ", queue->head = " << queue->head << endl;
    return film;
}

bool isFull(Queue *queue) {
  if ((queue->head == queue->tail + 1) || (queue->head == 0 && queue->tail == QUEUE_SIZE - 1)) return 1;
  return 0;
}

bool empty(Queue *queue) {
    return queue->head == -1 && queue->tail == -1;
}

int size(Queue *queue) {
  if (empty(queue))
        return 0;
  else
  if (queue->head > queue->tail)
    return QUEUE_SIZE - queue->head + queue->tail + 1;
  else
    return queue->tail - queue->head + 1;
}

void front(Film film) {

}

void print(Queue *queue) {
    if (empty(queue)) {
        cout << endl << "Underflow! (Stack is empty)" << endl;
    }else {
        cout << endl << "Queue has " << size(queue) << " elements: " << endl;
        int i;
        for (i = queue->head; i != queue->tail; i = (i + 1) % QUEUE_SIZE) {
            cout << queue->elements[i].name << "  " << queue->elements[i].genre << "  " << queue->elements[i].time << endl;
        }
        cout << queue->elements[i].name << "  " << queue->elements[i].genre << "  " << queue->elements[i].time << endl;
    }
    cout << endl;
}

void print(Film film) {
    cout << endl << "Film is:" << endl;
    if (film.name == "") {
        cout << "film is null" << endl;
    } else {
          cout << film.name << "  " << film.genre << "  " << film.time << endl;
    }

    cout << endl;
}
