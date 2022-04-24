#include <iostream>
using namespace std;
 
int N, K, map[8][8], ans;
bool visit[8][8];
 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
 
void dfs(int x, int y, int now, int dis, bool check) {
    if (dis > ans) ans = dis;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx == N || ny == N || visit[nx][ny]) continue;
        if (map[nx][ny] < now) {
            visit[nx][ny] = 1;
            dfs(nx, ny, map[nx][ny], dis + 1, check);
            visit[nx][ny] = 0;
        }
        else if(!check){
            if (map[nx][ny] - K < now) {
                visit[nx][ny] = 1;
                dfs(nx, ny, now - 1, dis + 1, 1);
                visit[nx][ny] = 0;
            }
        }
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("Test.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> K;
        int top = 0;
        ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (map[i][j] > top) top = map[i][j];
            }
        }
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == top) {
                    visit[i][j] = 1;
                    dfs(i, j, map[i][j], 1, 0);
                    visit[i][j] = 0;
                }
            }
        }
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}