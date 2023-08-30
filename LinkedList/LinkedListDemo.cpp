#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
}*third;

struct ListNode *insertAtBegning(struct ListNode *head,int val)
{
    ListNode *temp=new ListNode;

    temp->data=val;
    temp->next=NULL;

    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
};

ListNode* insertAtEnd(ListNode *head,int val){
    ListNode *temp,*curr;
    temp=new ListNode;
    temp->data=val;
    temp->next=NULL;
    curr=head;
    if(curr==NULL){
        head=temp;
    }
    else{
        while (curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
    return head;
}

void insertAtPosition(struct ListNode *head,int index,int val){
    ListNode *temp;
    int i;
    if(index<0)return;

    temp=new ListNode;
    temp->data=val;
    if(index==0){
        temp->next=head;
        head=temp;
    }
    else{
        for (i = 0; i < index-1; i++)
        {
            head=head->next;
        }
        temp->next=head->next;
        head->next=temp;
       // return head;
    }
    

}


void Display(ListNode *head){
    ListNode *curr=head;
    while (curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    
}

int length(ListNode *head){
    ListNode *curr=head;
    int count=0;
    while (curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    
    return count;

}

void insertSorted(struct ListNode *head,int val){
    struct ListNode *p ,*t,*q=NULL;
    p=head;
    t=new ListNode;
    t->data=val;
    t->next=NULL;

    if(head==NULL){
        head=t;
    }
    else{
        while (p&&p->data<val)
        {
            q=p;
            p=p->next;
        }
        if(p==head){
            t->next=head;
            head=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
        
    }

}

int Delete(ListNode *head){
    ListNode *p=head;
    head=head->next;
    int x=p->data;
    return x;
}

int DeletePosition(ListNode *head,int index){
   // ListNode *p=head;
    ListNode *q=NULL;
    int x=-1;
   // if(index<1||length(head)){return -1;}
    if (index==1)
    {
        q=head;
        x=head->data;
        head=head->next;
        delete q;
        return x;
    }

    else{
        for (int i = 0; i < index-1; i++)
           {
             q=head;
             head=head->next;
            }
         q->next=head->next;
         x=head->data;
         delete head;
         return x;
    }
}

int isSorted(ListNode *head){
    int x=-65536;
    while (head!=NULL)
    {
        if (head->data<x)
        {
            return 0;
        }
        x=head->data;
        head=head->next;
        
    }
    return 1;
    
}

void RemoveDuplicate(ListNode* head){
    ListNode *q=head->next;
    while (q!=NULL){
        if(head->data!=q->data){
            head=q;
            q=q->next;
        }else{
            head->next=q->next;
            delete(q);
            q=head->next;
        }
    }
    
}

void ReverseUsingArray(ListNode *head){
    int A[length(head)] ,i=0;
    ListNode *q=head;
    while (q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=head;
    i--;
    while (q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

ListNode *ReverseLinks(ListNode *head){
    ListNode *q=NULL,*r=NULL;
   // struct ListNode *p=head;
    while (head!=NULL)
    {
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
   // Display(head);
   // cout<<endl;
   //head=q;
   // Display(q);
   // cout<<endl;
   // Display(head);
    return q;
    
}

void ReverseLinksTwo(ListNode *head){
    ListNode *q=NULL,*r=NULL;
   // struct ListNode *p=head;
    while (head!=NULL)
    {
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
   // Display(head);
   // cout<<endl;
   head=q;
   while (head!=NULL)
   {
   cout<<"Head Data: "<<head->data<<endl;
    head=head->next;
   }
   
   // Display(q);
   // cout<<endl;
   // Display(head);
   
    
}

void Concat(ListNode *p,ListNode *second){
    third=p;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=second;
    
}

void Merge(ListNode *p,ListNode *q){
    ListNode *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while (p&&q)
    {
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if (p)last->next=p;
    if (q)last->next=q;
    
}

int isLoop(ListNode *f){
    ListNode *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while (p&&q&&p!=q);
    if(p==q)
        return 1;
    else return 0;

}


int main(){
    ListNode* head=NULL;
    ListNode *second=NULL;
    //ListNode *third=NULL;


    head= insertAtBegning(head,30);
    head=insertAtBegning(head,20);
    head=insertAtBegning(head,10);
    head=insertAtBegning(head,15);

    Display(head);
    cout<<endl;
    insertSorted(head,25);
    insertSorted(head,15);
    insertSorted(head,35);
    insertSorted(head,55);
    insertSorted(head,35);
    insertSorted(head,60);
    insertSorted(head,20);

    Display(head);
    cout<<endl<<isSorted(head)<<endl;

    cout<<"Length is: "<<length(head)<<endl;

    cout<<"Deleted Item : "<<DeletePosition(head,2)<<endl;
   // cout<<endl<<DeletePosition(head,2)<<endl;

    Display(head);

    cout<<endl<<isSorted(head);
    cout<<endl<<"Length is: "<<length(head)<<endl;

    RemoveDuplicate(head);
    Display(head);
    cout<<endl<<"Length is: "<<length(head)<<endl;

    cout<<"Reverse USing Array : ";
    ReverseUsingArray(head);
    Display(head);
    cout<<endl;

    cout<<"Reverse Using Links : ";
    head=ReverseLinks(head);
    Display(head);
    
    // cout<<endl;
    //cout<<"Reverse Using Links Second Method: ";
    //ReverseLinksTwo(head);
   // Display(head);

    cout<<endl<<"\nSecond LinkedList: ";

    second= insertAtBegning(second,3);
    insertSorted(second,5);
    insertSorted(second,22);
    insertSorted(second,32);
    insertSorted(second,50);
    insertSorted(second,40);
    insertSorted(second,42);

    Display(second);

    // cout<<endl<<"Concatination : ";
    // Concat(second,head);
    // Display(third);

    cout<<endl<<"Mergining: ";
    Merge(head,second);
    Display(third);
    cout<<endl<<"----------";
//15 20 25 30 35 55 60
    ListNode *t1,*t2;
    t1=head->next->next;
    t2=head->next->next->next->next->next->next;
    t2->next=t1;

    cout<<endl;
    //Display(head);
    //cout<<endl;
   // Display(t1);
    //cout<<endl;
    //Display(t2);
cout<<"Loop: "<<isLoop(head);


}