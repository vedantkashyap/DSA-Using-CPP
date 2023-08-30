#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void Push(int x);
    int Pop();
    void Display();
};
void Stack::Push(int value)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack Overflow " << endl;
    }
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}

int Stack::Pop(){
    int x;
    if(top==NULL){cout<<"Stack Underflow "<<endl;}
    else{
            x=top->data;
            Node *t=top;
            top=top->next;
            delete t;
    }
    return x;
}

void Stack::Display(){
    Node *t=top;
    while (t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
int main()
{
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Display();

    cout<<st.Pop()<<endl;
    cout<<st.Pop()<<endl;
    st.Display();

}