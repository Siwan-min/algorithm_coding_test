#include <stdio.h>
#include <queue>

using namespace std;

int map[51][51], N, L, R;

bool check[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int abs(int x, int y){
    return x - y > 0 ? x - y : y - x;
}

struct p {
    int x;
    int y;
};

void bfs(int a, int b){
    check[a][b] = true;
    queue<p> q;
    queue<p> s;
    int sum = map[a][b];
    q.push({a, b});
    s.push({a, b});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for( int i = 0 ; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx == N || ny == N || check[nx][ny]) continue;
			if (abs(map[x][y], map[nx][ny]) < L || abs(map[x][y], map[nx][ny]) > R) continue;

            check[nx][ny] = true;
			sum += map[nx][ny];
			q.push({nx, ny});
			s.push({nx, ny});
        }
    }
    sum = sum / s.size();
	while (!s.empty()) {
		int x = s.front().x;
		int y = s.front().y;
		map[x][y] = sum;
		s.pop();
	}
}

int main(){
    scanf("%d %d %d", &N, &L, &R);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    }
     for(int i = 0; i < N; i++)
         map[N][i] = 999, map[i][N] = 999;

    int cnt = 0;
    while (1)
    {
        bool b = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j]) continue;
				int r = abs(map[i][j], map[i][j + 1]); //오른쪽
				int l = abs(map[i][j], map[i + 1][j]); //아래쪽
				if ((r<L || r>R) && (l<L || l>R)) continue;
				bfs(i, j);
				b = true;
			}
		}
		if (!b) break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				check[i][j] = false;
		cnt++;
    }
    printf("%d", cnt);
}
/*
3 20 50
50 30 30
20 40 70
40 20 10

2 20 50
50 30
30 40

4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/