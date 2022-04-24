#include <iostream>
using namespace std;

int a[10];
int b[10];

int main() {
int s=0;
  for(int i = 0; i<10; i++)
    cin>>a[i];
  for(int i = 0; i<10; i++)
    cin>>b[i];
    
  for(int i = 0; i<10; i++){
    if(a[i]>b[i])
     s++;
    else if(a[i]<b[i])
    s--;
  }
  
  if(s>0) cout<<"A";
  else if(s<0) cout<<"B";
  else cout<<"D";
  return 0;
}
