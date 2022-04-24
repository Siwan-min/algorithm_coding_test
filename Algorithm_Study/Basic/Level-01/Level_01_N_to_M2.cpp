#include <iostream>

using namespace std;

int main(){
  int n, m;
  cin>>n>>m;
  int cnt = 0;
  for(int i = n; i<=m; i++){
    cout<<i<<" ";
    cnt++;
    if(cnt%8==0)
    cout<<endl;
  }
  
  return 0;
}
