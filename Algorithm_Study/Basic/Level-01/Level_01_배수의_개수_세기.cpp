#include <iostream>
using namespace std;
int main(){
  int a, b, c;
  cin>>a>>b>>c;
  
  if(a>b){
    int t;
    t=a;
    a=b;
    b=t;
  }
  int cnt = 0;
  for(int i=a; i<=b; i++){
    if(i%c==0)
    cnt++;
  }
  cout<<cnt;
  return 0;
}
