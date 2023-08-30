#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void Push(int val)
{
    struct Node *t;
    t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full " << endl;
    }
    else
    {
        t->data = val;
        t->next = top;
        top = t;
    }
}

int Pop()
{
    int x = -1;
    struct Node *t;
    if (top == NULL)
    {
        cout << "Stack Underflow " << endl;
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *t;
    t = top;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Display();

    cout << Pop() << endl;
    cout << Pop() << endl;
    Display();

    Push(50);
    Push(60);
    Display();
}