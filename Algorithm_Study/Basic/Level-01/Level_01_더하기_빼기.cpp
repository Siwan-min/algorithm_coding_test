#include <iostream>
using namespace std;
int main() {
int a, b, sum;
cin>>a>>b;
for(a; a<=b; a++){
  if((a%2)==0){
  sum = sum+a*(-1);
  }
  else sum = sum+a;
}
cout<<sum;

  return 0;
}
