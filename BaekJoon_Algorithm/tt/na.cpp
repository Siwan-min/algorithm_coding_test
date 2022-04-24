#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct POSI{
    int y, x;
};

int n, l, r;
int map[50][50];

void create_area(int sy, int sx, int status[][50], int index, int& count, int& sum){
    int visited[50][50] = {0, };

    const int dy[] = {0, 0, -1, 1};
    const int dx[] = {-1, 1, 0, 0};

    queue<POSI> q;
    POSI head;
    head.y = sy;
    head.x = sx;
    visited[sy][sx] = 1;
    q.push(head);

    while(!q.empty()){
        POSI cur = q.front(); 
        q.pop();

        status[cur.y][cur.x] = index;
        count++;
        sum += map[cur.y][cur.x];

        for(int dir = 0; dir < 4; dir++){
            POSI next;
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];

            if(next.y < 0 || next.y >=n || next.x < 0 || next.x >= n) continue;
            int delta = abs(map[cur.y][cur.x] - map[next.y][next.x]);
            if(visited[next.y][next.x] == 0 && l <= delta && delta <= r){
                visited[next.y][next.x] = 1;
                q.push(next);
            }
        }

    }
}

int main(){

    scanf("%d %d %d", &n, &l, &r);

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            scanf("%d", &map[y][x]);
        }
    }
    int ret = 0;
    bool is_update = true;
    while (is_update) // 업데이트가 발생하지 않으면 끝냄
    {
        is_update = false; 

        int status[50][50] = {0, }; // 묶이는 도시 체크 
        int area_index = 0;
        int count[25001] = {0, };
        int sum[25001] = {0, };
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(status[y][x] == 0){
                    area_index++;
                    create_area(y, x, status, area_index, count[area_index], sum[area_index] );
                }
            }
        }

        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                int index = status[y][x];
                int avg = sum[index] / count[index];
                if(map[y][x] != avg){
                    map[y][x] = avg;
                    is_update = true;
                }
            }
        }
        if(is_update){ //업데이트 있었다면 카운드 
            ++ret;
        }
    }
    printf("%d\n", ret);
    return 0;
}

/*
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/