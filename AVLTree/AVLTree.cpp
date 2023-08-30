#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int Height;
    Node *lchild;
    Node *rchild;

} *root = NULL;

int NodeHeight(Node *p)
{
    int lh, rh;
    lh = p && p->lchild ? p->lchild->Height : 0;
    rh = p && p->rchild ? p->rchild->Height : 0;

    return lh > rh ? lh + 1 : rh + 1;
}

int BalanceFactor(Node *p)
{
    int lh, rh;
    lh = p && p->lchild ? p->lchild->Height : 0;
    rh = p && p->rchild ? p->rchild->Height : 0;

    return lh - rh;
}

Node *LLRotation(struct Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    p->Height = NodeHeight(p);
    pl->Height = NodeHeight(pl);
    if (root == p)
        root = pl;
    return pl;
}
Node *LRRotation(struct Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->Height = NodeHeight(pl);
    p->Height = NodeHeight(p);
    plr->Height = NodeHeight(plr);
    if (root == p)
        root = plr;
    return plr;
}
Node *RRRotation(struct Node *p)
{
}
Node *RLRotation(struct Node *p)
{
}

struct Node *RecursiveInsert(Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = new Node();
        t->data = key;
        t->Height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = RecursiveInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RecursiveInsert(p->rchild, key);
    }
    p->Height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    {
        RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
    {
        RLRotation(p);
    }
}

void InOrder(Node *p)
{
    if (p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

int main()
{
    root = RecursiveInsert(root, 10);
    root=RecursiveInsert(root, 5);
    root=RecursiveInsert(root, 2);
    InOrder(root);
}