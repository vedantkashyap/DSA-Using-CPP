#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *lChild;
    int data;
    Node *rChild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void Enqueue(Node *x);
    Node *Deque();
    void Display();
    int isEmpty() { return front == rear; }
};

void Queue::Enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::Deque()
{
    Node *x = NULL;
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
    if (front == rear)
    {
        cout << "Queue is Empty, No value to Display";
    }
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}