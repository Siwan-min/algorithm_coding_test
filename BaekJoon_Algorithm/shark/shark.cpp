/*
문제 파악:
N x N 크기의 공간에 물고리 M 마리, 아기 상어 1 마리가 있다. (각 칸에 한 마리만 존재)
아기 상어와 물고기는 크기를 가지고 있음.
아기 상어의 처음 크기는 2이다.
아기 상어는 1초에 상, 하, 좌, 우로 인접한 한 칸씩 이동.
자신보다 큰 물고기는 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
자기 자신보다 크기가 작은 물고기만 먹을 수 있다. ( 같은 크기는 지가가는 것만 가능)

- 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움 요청
- 먹을 수 잇는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
- 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
    (거리가 가까운 물고기가 많다면, (1)가장 위, (2)가장 왼쪽이 우선이다)

이동 시간: 1초, 먹는데 걸리는 시간: x
물고리를 먹은 칸은 빈 칸이 된다.

아기 상어의 레벨만큼 물고기를 잡아 먹었을 때, 아기 상어의 레벨이 1 증가한다.
>> 아기상어 레벨 2 일 때, 2마리 잡아먹으면 레벨 3이 된다. 

결과: 아기 상어가 몇 초 동안 혼자서 물고기를 잡아 먹을 수 있는지 출력하라. 
-------------------------------------------------------------------------------------------------------
0: 빈칸
1 ~ 6: 물고기 크기
9: 아기 상어 위치

문제 해결 방안:
(1) 내가 잡을 수 있는 물고기를 파악
(2) 잡을 수 있는 물고기들 까지의 거리를 계산한다.
(3) 내가 잡아야 하는 물고기를 파악한다
(4) 그 물고기를 잡는다
(5) 필요할 경우 레벨을 갱신한다.
*/

#include <iostream>
#include <cstring>
#include <queue>
#define MAX 50

using namespace std;

int n, currentLevel, result, curY, curX;
int map[MAX][MAX];
int dist[MAX][MAX];
bool check[MAX][MAX];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct p {
    int y;
    int x;
};



void BFS(){
    queue <p> Queue;

    Queue.push({curY, curX}); // 현재 위치 부터 탐색
    check[curY][curX] = true; // 현재 위치 방문 처리
    dist[curY][curX] = 0; //거리는 0부터 시작

    while (!Queue.empty())
    {
        p front = Queue.front();
        Queue.pop();

        int y = front.y;
        int x = front.x;

        for(int dir = 0; dir<4; dir++){ //주변 네 방향 탐색
            int yy = y + dy[dir];
            int xx = x + dx[dir];
            
            // 맵의 범위 안에 있고, 방문한 적이 없다. 
            //그리고 공간에 있는게 0 이거나 현재 레벨보다 작거나 같아야 이동 가능  
            if((yy >= 0 && yy < n && xx >= 0 && xx < n && !check[yy][xx]) && 
                    (map[yy][xx] == 0 || map[yy][xx] <= currentLevel)){
                Queue.push({yy, xx});
                check[yy][xx] = true;
                dist[yy][xx] = dist[y][x] + 1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    currentLevel = 2; // 아기 상어의 레벨
    cin>>n; //맵의 크기

    for(int i = 0; i<n; i++){ //맵에 정보를 받는다
        for(int j = 0; j<n; j++){
            cin>>map[i][j];
            if(map[i][j] == 9){ // 아기 상어의 위치를 받는다.
                curY = i;
                curX = j;
                map[i][j] = 0;
            }
        }
    }

    int kill_cnt = 0;
    while (1)
    {
        //물고기를 잡아 먹고 다음 물고기를 잡아 먹으러 가는 거리를 구하기 위해 초기화를 해주어야 한다.
        memset(check, 0, sizeof(check)); 
        memset(dist, 0, sizeof(dist));
        BFS(); // BFS 탐색으로 물고기를 잡어 먹데 걸리는 거리(시간)을 구한다. 

        int minDist = 987987987, minDist_y, minDist_x; //최소 거리

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(map[i][j] != 0 && check[i][j] && map[i][j] < currentLevel){ //잡아 먹을 수 있는 물고기 중에서 최소 거리에 있는 물고기를 탐색한다. 
                    if(minDist > dist[i][j]){
                        minDist = dist[i][j];
                        minDist_y = i;
                        minDist_x = j;
                    }
                }
            }
        }

        if(minDist == 987987987) break; // 잡아 먹을 수 있는 물고기가 없다고 판단

        kill_cnt++; //break로 빠져나오지 않고, 물고기를 잡아 먹었다면 잡아 먹은 물고기 수 Kill_cnt++
        result += dist[minDist_y][minDist_x]; // 결과 누적 합 
        map[minDist_y][minDist_x] = 0; //물고기를 앲애준다. 

        curY = minDist_y; //현재 위치를 갱신해준다. 
        curX = minDist_x;

        if(kill_cnt == currentLevel){ //현재 아기 상어 레벨만큼 물고기를 잡아 먹었다면 
            currentLevel++; //현재 레벨을 up 해준다.
            kill_cnt = 0; //잡아 먹은 물고기 수를 초기화 해준다. 
        }
    }
    cout<<result<<endl;
    return 0;
}