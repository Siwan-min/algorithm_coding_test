#include <iostream>
using namespace std;
#define MAX 1000000
int T[MAX];
int n, sum;
int main(){
 cin>>n;
   
 T[0]=0;
 T[1]=1;
 T[2]=2;
 T[3]=4;
  
  for(int i = 4; i<=n; i++){
    sum = (T[i-3]+T[i-2]+T[i-1])%1000007;
    T[i] = sum;
  }
  cout<<T[n];
  return 0;
}

