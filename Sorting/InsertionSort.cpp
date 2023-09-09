#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {5, 7, 2, 13, 15, 1, 9, 4}, n = 8;
    InsertionSort(A, n);
    for (int x : A)
    {
        cout << x << " ";
    }
}