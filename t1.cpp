#include <iostream>
#include <vector>
#define MAX 100
 
using namespace std;
 
vector <int> graph[MAX];
vector <int> cost[MAX]; // 간선의 가중치
 
int n, m, start, end2;
 
int Table[MAX];
bool Check[MAX]; //ture : 이미 i 는 최단거리가 확정되었다.
                //false: 아직 i는 최단거리가 확정되지 않았다
int main(){
  cin>>n>>m>>start>>end2; //정점, 간선, 시작, 끝
  
  for(int i = 0; i<m; i++){
    int a, b, c; //a와 b가 연결, c 가중치
    
    cin>>a>>b>>c;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
    
    cost[a].push_back(c);
    cost[b].push_back(c);
  }
  
  for(int i = 0; i<n; i++) Table[i] = 98798798;
  Table[start] = 0; //시작 점은 최단거리가 0, 나머지는 모르니까 큰 값으로 초기화
  
  for(int i=0; i<n; i++){
    //(1) 최솟값을 구한다. 단, 지금까지 최단거리로 확정되지 않았던 정점에 대해서.
    //(2) 그 최솟값을 갖는 노드로부터 뻗어나간다.
    int minValue = 98798798, minIndex = -1; //minValue : 최솟값을 받는 변수
    for(int j = 0; j<n; j++){
      if(!Check[j]&&minValue>Table[j]){
        minValue = Table[j];
        minIndex = j;
      }
    }
    Check[minIndex] = true;
    
    for(int j=0; j<graph[minIndex].size(); j++){ //인접리스트를 돌겠다
      int Node2 = graph[minIndex][j];
      int Cost2 = cost[minIndex][j];
      
      if(Table[Node2] > Table[minIndex] + Cost2){
        Table[Node2] = Table[minIndex] + Cost2;
      }
    }
  }
  
  cout<<Table[end2];
  return 0;
}
