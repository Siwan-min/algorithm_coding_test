#include <iostream>

using namespace std;

int fibo[50];
int n;

int main(){
  
  cin>>n;
  
  fibo[0] = 0;
  fibo[1] = 1;
  
  int k = 0;
  int idx = 2;
  while(k < n){
    
    fibo[idx] = fibo[idx-1] + fibo[idx-2];
    idx++;
    k++;
  }
  
  cout<<fibo[n]<<endl;
  
  return 0; 
}