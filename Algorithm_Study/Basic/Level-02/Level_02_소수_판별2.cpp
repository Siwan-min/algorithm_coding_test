#include <iostream>
using namespace std;

bool prime(int n){
  if(n==1) 
  return 0;
  int i;
  for( i = 2; i * i <=n; i++){
    if(n % i ==0)
      return 0;
  }
  return true; // i 는 소수이다. 
}

int main()
{
  int m, n;
  cin>>m>>n;
  for(int i = m; i<= n; i++)
  {
    if(prime(i))
    {
      cout<<i<<' ';
    }
  }
}
