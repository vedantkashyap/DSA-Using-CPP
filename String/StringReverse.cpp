#include <iostream>
using namespace std;
int main() {
 char c[]="Python";
 char b[7];
 int i;
 for (i = 0; c[i]!='\0'; i++)
 {
    
 }

 i=i-1;
 int j;
 for (j= 0; i >=0; i--,j++)
 {
    b[j]=c[i];
 }

 b[j]='\0';
 cout<<c;
 cout<<"\n";
 cout<<b;
}