#include <iostream>
using namespace std;
long long n, k;

long long getOrder(long long x){
  long long result = 0;
  
  for(int i = 1; i<=n; i++){
    if((long long)i*n<x) result +=n;
    else{
      if(x%i==0) result += (x/i)-1;
      else result += x/i;
    }
  }
  return result + 1; 
}

int main() {

  cin>>n>>k;
  
  long long start = 1;
  long long end = n*n+1;
  while(start+1<end){
    long long mid = (start+end)/2;
    long long myOrder = getOrder(mid);
    
    if(myOrder<=k) start = mid;
    else end = mid;
    
  }
  cout<<start<<endl;
  return 0;
}