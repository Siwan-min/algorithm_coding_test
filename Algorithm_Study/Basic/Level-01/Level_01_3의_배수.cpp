#include <iostream>
using namespace std;

int main() {
  int i;
  cin>>i;
  if(i>=1 && i<=1000){
    for(int k=1; k<=i; k++){
      if(k%3!=0){
        cout<<k<<' ';
      }
      else if(k%3 == 0){
        cout<<"X ";
      }
    }
  }
  return 0;
}
