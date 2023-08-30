#include <bits/stdc++.h>
using namespace std;
#include "Queuecpp.h"

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *p);
};
void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter Root Value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lChild = root->rChild = NULL;
    q.Enqueue(root);

    while (!q.isEmpty())
    {
        p = q.Deque();
        cout << "Enter left child of : " << p->data<<" ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            q.Enqueue(t);
        }
        cout << "Enter Right child of : " << p->data<<" ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::Preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lChild);
        Preorder(p->rChild);
    }
}

void Tree::Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lChild);
        cout << p->data << " ";
        Inorder(p->rChild);
    }
}

void Tree::Postorder(struct Node *p)
{
    if (p)
    {

        Postorder(p->lChild);
        Postorder(p->rChild);
        cout << p->data << " ";
    }
}

void Tree::LevelOrder(struct Node *p)
{
    Queue q(100);
    cout << root->data << " ";
    q.Enqueue(root);
    while (!q.isEmpty())
    {
        root = q.Deque();
        if (root->lChild)
        {
            cout << root->lChild->data << " ";
            q.Enqueue(root->lChild);
        }
        if (root->rChild)
        {
            cout << root->rChild->data << " ";
            q.Enqueue(root->rChild);
        }
    }
}

int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lChild);
    y = Height(root->rChild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Tree t;
    t.createTree();

    cout<<endl<<"PreOrder : ";
    t.Preorder(t.root);
    
    cout<<endl<<endl<<"Inorder : ";
    t.Inorder(t.root);

    cout<<endl<<endl<<"Postorder : ";
    t.Postorder(t.root);

    cout<<endl<<endl<<"Levelorder : ";
    t.LevelOrder(t.root);

    cout<<endl<<endl<<"Height : "<<t.Height(t.root)<<endl;
}