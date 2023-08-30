#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int Length(Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int index, int value)
{
    Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = value;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = value;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Delete(Node *p, int index)
{
    Node *t;
    int i, value;
    if (index < 0 || index > Length(p))
        return -1;
    if (index == 0)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        value = p->data;
        delete p;
    }
    else
    {
        for (i = 0; i < index; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        value = p->data;
        delete p;
    }
    return value;
}

void Reverse(Node *p)
{
    Node *temp;
    while (p != NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)first=p;

    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Display(first);
    cout << "Length is: " << Length(first) << endl
         << endl;

    Insert(first, 5, 25);
    Display(first);
    cout << "Length is: " << Length(first) << endl
         << endl;

    cout << "Deleted item is: " << Delete(first, 0) << endl;
    Display(first);
    cout << "Length is: " << Length(first) << endl<<endl;

    Reverse(first);
    Display(first);


}