#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 100005

using namespace std;

int n, m;

vector<int> myGraph[MAX];
bool visited1[MAX];
bool visited2[MAX];

queue <int> Queue;

void DFS(int x){
  
  visited1[x] = true;
  cout<<x<<" ";
  
  for(int i = 0; i < myGraph[x].size(); i++){
    int y = myGraph[x][i];
    
    if(!visited1[y])
      DFS(y);
  }
}

void BFS(){
  
  visited2[0] = true;
  Queue.push(0);
  while(!Queue.empty()){
    int current = Queue.front();
    Queue.pop();
    cout<<current<<" ";
    for(int i = 0; i < myGraph[current].size(); i++){
      int next = myGraph[current][i];
      if(!visited2[next]){
        visited2[next] = true;
        Queue.push(next);
      }
    }
  }
}

int main(){
  
  cin>>n>>m;
  
  for(int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
    
  }
  
  for(int i = 0; i < n; i++)
    sort(myGraph[i].begin(), myGraph[i].end());
  
  DFS(0);
  cout<<endl;
  BFS();
  
  
  return 0;
}