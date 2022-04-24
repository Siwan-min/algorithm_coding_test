#include <iostream>
using namespace std;

int main(){
  int a, b, c, d, t;
  for(int i = 0; i<3; i++){
  cin>>a>>b>>c>>d;
  t = a + b+ c + d;
  
  if(t==3){
    cout<<"A"<<endl;
  }
  else if(t==2){
    cout<<"B"<<endl;
  }
  else if(t==1){
    cout<<"C"<<endl;
  }
  else if(t==0){
    cout<<"D"<<endl;
  }
  else if(t==4){
    cout<<"E"<<endl;
  }
  }
  return 0;
}
