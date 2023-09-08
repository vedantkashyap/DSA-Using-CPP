#include <bits/stdc++.h>
using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];

}

void IterativeMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1<n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
         if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
       Merge(A, 0, p / 2 - 1, n - 1);
    }
}

void RecursiveMergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RecursiveMergeSort(A,l,mid);
        RecursiveMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[] = {3, 15, 7, 10, 2, 9, 6, 12, 4}, n = 9;
    cout<<"Iterative Sort: ";
    IterativeMergeSort(A, n);
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
    int B[] = {3, 15, 7, 10, 2, 9, 6, 12, 4};
    cout<<"Recursive Sort: ";
    RecursiveMergeSort(B,0,8);
    for (int x : B)
    {
        cout << x << " ";
    }
}