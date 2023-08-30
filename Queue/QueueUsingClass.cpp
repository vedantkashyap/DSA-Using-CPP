#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void Enqueue(int val);
    int Deque();
    void Display();
};

void Queue::Enqueue(int val)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        Q[rear] = val;
    }
}

int Queue::Deque()
{
    int x = -1;
    if (front == rear)
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
void Queue::Display()
{
    if(front==rear){
        cout<<"Queue is Empty, No value to Display";
    }
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue t(5);
    t.Enqueue(10);
    t.Enqueue(20);
    t.Enqueue(30);
    t.Enqueue(40);
    t.Display();

    cout << t.Deque() << endl;
    t.Display();
    t.Enqueue(50);
    t.Enqueue(60);
    t.Enqueue(70);
    t.Display();
    cout << t.Deque() << endl;
    t.Display();
    cout << t.Deque() << endl;
    t.Display();
    cout << t.Deque() << endl;
    t.Display();
    cout << t.Deque() << endl;
    t.Display();
    cout << t.Deque() << endl;
    t.Display();
}
queue<char> t;