#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head;

void create(int A[], int n)
{
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int isLoop(Node *f)
{
    Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

void Display(Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}
int Length(Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void Insert(Node *p, int index, int value)
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(p))
        return;

    if (index == 0)
    {
        t = new Node;
        t->data = value;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(p))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }

    else
    {
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{

    int A[] = {2, 4, 6, 8, 9};
    create(A, 5);
    Display(head);
    cout << isLoop(head) << endl;

    Insert(head, 0, 5);
    Insert(head, 1, 10);
    Insert(head, 7, 15);

    Display(head);

    cout<<Delete(head,1)<<endl;
    Display(head);
    
    cout<<Delete(head,5)<<endl;

    Display(head);


    return 0;
}