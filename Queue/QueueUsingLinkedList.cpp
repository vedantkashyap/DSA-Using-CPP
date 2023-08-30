#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *rear = NULL, *front = NULL;

void Enqueue(int val)
{
    struct Node *t = new Node;
    if (t == NULL)
    {
        cout << "Queue is FULL " << endl;
    }
    else
    {
        t->data = val;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        Node *temp;
        temp = front;
        front = front->next;
        x = temp->data;
        delete temp;
    }
    return x;
}
void Display()
{
    struct Node *p=front;
    if (p == NULL)
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}
int main()
{
    Display();
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Display();
    cout<<Dequeue()<<endl;
    cout<<Dequeue()<<endl;
    cout<<Dequeue()<<endl;
    cout<<Dequeue()<<endl;
    cout<<Dequeue()<<endl;
    cout<<"---------------"<<endl;
    Display();

    cout<<Dequeue()<<endl;
    cout<<Dequeue()<<endl;

    Display();
}