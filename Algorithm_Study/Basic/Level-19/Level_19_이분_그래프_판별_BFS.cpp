#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;
int n, m;
bool flag = false;
bool visitied[MAX];
vector <int> myGraph[MAX];
int group[MAX];

void DFS(int node, int c){
  visitied[node]= true;
   group[node]= c;
  
  for(int i = 0; i<myGraph[node].size(); i++){
    int next = myGraph[node][i];
    
    if(group[next]==c){
      flag = true;
      return ;
    }
    
    int c2;
    if(c==1) c2=2;
    else c2=1;
    
    if(!visitied[next])
    DFS(next,c2);
  }
}


int main(){
  cin>>n>>m;
  
  for(int i = 0; i<m; i++){
    int a, b;
    cin>>a>>b;
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  DFS(1,1);
  
  if(flag==true) cout<<"No";
  else cout<<"Yes";
  return 0;
}