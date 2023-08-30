#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue()
    {
        front = rear = 0;
        Q = new int[5];
    }
    CircularQueue(int len)
    {
        front = rear = 0;
        this->size = len+1;
        Q = new int[size];
    }
    void Enqueue(int value);
    int Dequeue();
    void Display();
    bool isFull();
    bool isEmpty();
};

bool CircularQueue::isFull()
{
    return (rear + 1) % size == front;
}
bool CircularQueue::isEmpty()
{
    return (rear == front);
}
void CircularQueue::Enqueue(int value)
{
    if (isFull())
    {
        cout << "Queue is full " << endl;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = value;
    }
}
int CircularQueue::Dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}
void CircularQueue::Display()
{
    if (isEmpty())
    {
        cout << "--------Queue is Empty.---------" << endl;
    }
    else
    {
        int i = front + 1;
        do
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
}
int main()
{
    CircularQueue cq(5);
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Display();
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;

    cq.Enqueue(50); 
    cq.Enqueue(60);
    cq.Enqueue(70);
    cq.Enqueue(80);
    cq.Enqueue(90);
    cq.Display();
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cout << cq.Dequeue() << endl;
    cq.Display();
    cq.Enqueue(5);
    cq.Enqueue(15);
    cq.Enqueue(25);
    cq.Enqueue(35);
    cq.Display();
}