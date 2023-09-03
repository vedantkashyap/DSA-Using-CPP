#include <bits/stdc++.h>
using namespace std;
void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k=j;
            }
        }
        Swap(&A[i],&A[k]);
    }
}

int main()
{
    int A[] = {3, 15, 7, 10, 2, 9, 6, 25, 4}, n = 9;
    SelectionSort(A, n);
    for (int x:A)
    {
        cout << x << " ";
    }
    cout << endl;
}