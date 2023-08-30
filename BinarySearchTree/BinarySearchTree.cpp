#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *lchild;
    int data;
    TreeNode *rchild;
} *root = NULL;

void Insert(int key)
{
    struct TreeNode *t = root;
    struct TreeNode *r = NULL, *p;
    if (root == NULL)
    {
        p = new TreeNode();
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
            return;
    }
    p = new TreeNode();
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void Inorder(TreeNode *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

struct TreeNode *Search(int key)
{
    TreeNode *t = root;
    while (t)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
    }
    return NULL;
}

struct TreeNode *RInsert(TreeNode *p, int key)
{
    TreeNode *t = NULL;
    if (p == NULL)
    {
        t = new TreeNode();
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    return p;
}

int Height(TreeNode *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct TreeNode *InPre(TreeNode *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
struct TreeNode *InSucc(TreeNode *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
struct TreeNode *Delete(TreeNode *p, int key)
{
    TreeNode *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    root = RInsert(root, 50);
    RInsert(root, 15);
    RInsert(root, 40);
    RInsert(root, 20);
    RInsert(root, 30);
    RInsert(root, 10);
    Inorder(root);
    cout << endl;
    Delete(root,15);
    cout<<Height(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    TreeNode *p = Search(10);
    cout << p->data;
}