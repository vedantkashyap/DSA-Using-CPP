#include <bits/stdc++.h>
using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Partion(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            Swap(&A[i], &A[j]);
    } while (i < j);
    Swap(&A[l], &A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partion(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {3, 15, 7, 10, 2, 9, 6, 25, 4}, n = 9;
    QuickSort(A, 0, n);
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}