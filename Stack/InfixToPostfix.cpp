#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void Push(char val)
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

char Pop()
{
    char x = -1;
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

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else return 1;
}
char* infixToPostfix(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=new char[len+2];
    
    while (infix[i]!='\0')
    {
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }else{
            if(pre(infix[i])>pre(top->data)){
                Push(infix[i++]);
            }else{
                postfix[j++]=Pop();
            }
        }
    }
    while (top!=NULL)
    {
        postfix[j++]=Pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix="a+b+c*d";
    Push(' ');
    char *postfix=infixToPostfix(infix);    
    cout<<postfix;
    cout<<6+5*3+4;
}