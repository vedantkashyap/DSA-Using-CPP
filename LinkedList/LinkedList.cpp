#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }

    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int value);
    int Delete(int index);
    int length();
};
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::length()
{
    Node *p = first;
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

void LinkedList::Insert(int index, int value)
{
    Node *t, *p = first;
    if (index < 0 || index > length())
        return;
    t = new Node;
    t->data = value;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if (index < 0 || index > length())
        return -1;

    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int P[] = {5, 16, 27, 55, 32, 20};
    LinkedList L(P, 6);
    L.Display();
    cout << L.length() << endl;
    L.Insert(2, 8);
    L.Display();
    cout << L.length() << endl;
    cout << L.Delete(2) << endl;
    L.Display();

    return 0;
}