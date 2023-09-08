#include <bits/stdc++.h>
using namespace std;

int findMax(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void CountSort(int A[], int n)
{
    int i, j, max;
    max = findMax(A, n);
    int *C = new int[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}
int main()
{
    int A[] = {3, 15, 7, 10, 2, 7, 9, 6, 12, 4}, n = 10;
    cout << "Count Sort: ";
    CountSort(A, n);
    for (int x : A)
    {
        cout << x << " ";
    }
}