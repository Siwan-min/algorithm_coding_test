#include <iostream>
using  namespace std;

int main(){
  int n, k;
  cin>>n;
  k=n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<k; j++){
      cout<<" ";
    }k--;
    
    for(int q=1; q<=i; q++){
      cout<<"*";
    }cout<<endl;
  }
  return 0;
}
