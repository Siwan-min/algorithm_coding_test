/*
T[i] : 정점 i에 도달하는 데 걸리는 최단거리
for i = 0 ~ n
(1) T[i] 중 최솟값을 정한다. 단, 지금까지 최솟값으로 뽑히지 않았던 값들 중
(2) index로 부터 뻗어 나간다. T[index] + cost
*/

#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

vector <int> graph[MAX];
vector <int> cost[MAX]; // 간선의 가중치

int n, m, start, _end;

int Table[MAX];
bool Check[MAX]; // true : 이미 i 는 최단거리가 확정되었다.
                //false : 아직 i 는 최단거리가 확정되지 않았다.
int main(){
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int a, b, c;

        cin>>a>>b>>c;

        graph[a].push_back(b);
        graph[b].push_back(a);

        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    cin>>start;
    for(int i = 0; i < n; i++) Table[i] = 987987987;
    Table[start] = 0; //시작 점은 최단거리가 0, 나머지는 모르니까 큰 값으로 초기화

    for(int i = 0; i < n; i++){
        //(1) 최솟값을 구한다. 단, 지금까지 최단거리로 확정되지 않았던 정점에 대해서.
        //(2) 그 최솟값을 갖는 노드로부터 뻗어나간다.
        int minValue = 987987987, minIndex = -1; //minValue : 최솟값을 받는 변수
        for(int j = 0; j < n; j++){
            if(!Check[j]&&minValue>Table[j]){
                minValue = Table[j];
                minIndex = j;
            }
        }
        Check[minIndex] = true;

        for(int j = 0; j < graph[minIndex].size(); j ++){
            int Node2 = graph[minIndex][j]; // minIndex에 연결된 정점
            int Cost2 = cost[minIndex][j]; // minIndex과 연결된 정점 노드들이 갖는 값

            if(Table[Node2] > Table[minIndex] + Cost2){
                Table[Node2] = Table[minIndex] + Cost2;
            }
        }
    }

    for(int i = 0; i<n; i++) cout<< Table[i] << " ";
  //  cout << Table[_end];
    return 0;
}

