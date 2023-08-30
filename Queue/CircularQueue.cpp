#include <bits/stdc++.h>
using namespace std;

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct CircularQueue *p, int s)
{
    p->size = s;
    p->front = p->rear = 0;
    p->Q = new int[p->size];
}

void Enqueue(struct CircularQueue *p, int val)
{
    if ((p->rear + 1) % p->size == p->front)
        cout << "Queue is Full " << endl;

    else
    {
        p->rear = (p->rear + 1) % p->size;
        p->Q[p->rear] = val;
    }
}

int Dequeue(struct CircularQueue *p)
{
    int x = -1;
    if (p->front == p->rear)
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        p->front = (p->front + 1) % (p->size);
        x = p->Q[p->front];
    }
    return x;
}
void Display(CircularQueue p)
{
     if (p.front == p.rear)
    {
        cout << "Queue is Empty " << endl;
    }else{
    int i = p.front + 1;
    do
    {
        cout << p.Q[i] << " ";
        i = (i + 1) % p.size;
    } while (i != (p.rear + 1) % (p.size));
    }
    cout << endl;
}
int main()
{
    struct CircularQueue CQ;
    create(&CQ, 5);
    Display(CQ);
    cout<<"-----------"<<endl;
    Enqueue(&CQ, 10);
    Enqueue(&CQ, 20);
    Enqueue(&CQ, 30);
    Display(CQ);
    cout << Dequeue(&CQ) << endl; // 20,30
    Enqueue(&CQ, 40);             // 20,30,40
    Enqueue(&CQ, 50);             // 20,30,40,50
    cout << Dequeue(&CQ) << endl; // 30,40,50=>20
    Enqueue(&CQ, 60);             // 30,40,50,60
    Display(CQ);
    cout << Dequeue(&CQ) << endl; // 40 50 60(30)
    cout << Dequeue(&CQ) << endl; // 50 60(40)
    Enqueue(&CQ, 70);             // 50 60 70
    Enqueue(&CQ, 80);             // 50 60 70 80
    cout << "----50 60 70 80-----" << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
    Display(CQ);
    cout << Dequeue(&CQ) << endl;
}