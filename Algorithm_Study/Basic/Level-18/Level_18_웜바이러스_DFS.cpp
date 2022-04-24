
/*
9 12
1 2 
1 3 
2 3 
2 4 
2 6 
3 7 
4 5 
4 7 
4 8 
5 6 
7 8 
8 9 
*/

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;
//global variable
int n, m, cnt;
vector <int> myGraph[MAX]; // myGraph[x] = x의 인접 리스트
bool visited[MAX];

void DFS(int x){
  visited[x] = true;
  cnt++;
  
  for(int i = 0; i<myGraph[x].size(); i++){
    int y = myGraph[x][i];
    
    if(visited[y]==false){
      DFS(y);
    }
  }
}

int main() {
 
  cin>>n>>m;
  
  for(int i = 0; i<m; i++){
    int a, b;
    
    cin>>a>>b;
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  DFS(1);
  cout<<cnt-1;
  return 1;
}