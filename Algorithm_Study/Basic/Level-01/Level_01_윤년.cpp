#include <iostream>
using namespace std;

int main() {

  int year;
  cin>>year;
  
  if(year<0 || year>5000)
  return 0;
  if(year > 400)
  {
  if(year%4==0)
  { 
    if(year%100 != 0 || year%400 == 0)
    {
      cout<<"YES"<<endl;
    }
    else
    {
      cout<<"NO"<<endl;
    }
  }
  else if(year %4 != 0)
  {
    cout<<"NO"<<endl;
  }
  }
  else{
    cout<<"NO"<<endl;
  }
  
  //Please Enter Your Code Here

  return 0;
}
