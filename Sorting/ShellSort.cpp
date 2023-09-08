#include<bits/stdc++.h>
using namespace std;

void ShellSort(int A[],int n){
    int gap,i,j;
    for ( gap = n/2; gap>=1; gap/=2)
    {
        for ( i = gap; i <n; i++)
        {
            int temp=A[i];
            j=i-gap;
            while (j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
            
        }
        
    }
    
}

int main(){
int A[]={3,15,7,10,2,9,6,12,4,7}, n=10;
ShellSort(A,n);
cout<<"Shell Sort: ";
for (int i = 0; i < n; i++)
{
    cout<<A[i]<<" ";
}
cout<<endl;
}