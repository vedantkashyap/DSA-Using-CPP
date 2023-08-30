#include <iostream>
using namespace std;
int main() {
    char c[]="Python";
    cout<<c;

    char t;
    int j;
    for (j = 0; c[j]!='\0'; j++)
    {
        
    }

    j=j-1;
    int i;
    for (i=0;i <j; i++,j--)
    {
        t=c[i];
        c[i]=c[j];
        c[j]=t;
    }

    cout<<"\n";
    cout<<c;
}