#include<iostream>
#include<vector>
 
using namespace std;
 
const int MAX = 100005;
vector <int> arr[MAX];
int check[MAX] = {0,};
 
int n, m;
bool flag = false;
 
void DFS(int a, int c){
  check[a]=c;
  //cout<<a<<","<<c<<endl;
  for(int i=0; i<arr[a].size();i++){
    if(check[arr[a][i]]==c){
      flag = true;
      return;
    }
    if(check[arr[a][i]]==0){
      DFS(arr[a][i], c*-1);
    }
  }
}
 
int main(){
  
  cin>>n>>m;
  
  int a,b;
  for(int i=0; i<m; i++){
    cin>>a>>b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  
  DFS(0, 1);
  
  if(flag == true){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  
  return 0;
}
 