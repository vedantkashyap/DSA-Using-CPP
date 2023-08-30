#include <bits/stdc++.h>
using namespace std;

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i=i/2;
    }
    A[i]=temp;
}

int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    //40 25 35 10 5 20 30
     for (int i = 2; i < 8; i++)
    {
        Insert(H,i);
    }
    
    for (int i = 1; i < 8; i++)
    {
        cout<<H[i]<<" ";
    }
    
}