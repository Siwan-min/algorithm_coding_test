#include <iostream>
using namespace std;

int main(){
  int i;
  cin>>i;
  for(int a=0; a<i; a++){
    for(int b=0; b<=a; b++){
      cout<<"*";
    }cout<<"\n";
  }
  return 0;
}
