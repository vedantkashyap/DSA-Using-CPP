#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[size];
}
void Enque(struct Queue *q, int val)
{
    if (q->front == q->size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        q->front++;
        q->Q[q->front] = val;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        q->rear++;
        x = q->Q[q->rear];
    }
    return x;
}
void Display(struct Queue q)
{
    for (int i = q.rear + 1; i <= q.front; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct Queue t;
    create(&t, 5);
    Enque(&t, 10);
    Enque(&t, 20);
    Enque(&t, 30);
    Display(t);

    cout << Dequeue(&t) << endl;
    Display(t);
    Enque(&t, 40);
    Enque(&t, 50);
    Display(t);
    cout << Dequeue(&t) << endl;
    Enque(&t, 60);
    Display(t);
    cout << Dequeue(&t) << endl;
    Display(t);
    cout << Dequeue(&t) << endl;
    Display(t);
    cout << Dequeue(&t) << endl;
    Display(t);
    cout << Dequeue(&t) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << t.Q[i] << " ";
    }
}