#include <iostream>
#include <cstring>
#include <queue>
#define MAX 60
using namespace std;
 
int T, n, m, r, c, l;
 
int map[MAX][MAX];
int cost[MAX][MAX];
bool check[MAX][MAX];
 
struct p
{
    int y;
    int x;
};
 
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
 
queue<p> Queue;
 
void push_check(int yy, int xx, int curY, int curX)
{
    Queue.push({ yy, xx });
    check[yy][xx] = true;
    cost[yy][xx] = cost[curY][curX] + 1;
}
 
void Tunnel(int dir, int yy, int xx, int curY, int curX) {
    int i = dir;
    if (i == 0)
    {
        if (map[yy][xx] == 1 || map[yy][xx] == 2 || map[yy][xx] == 5 || map[yy][xx] == 6)
            push_check(yy, xx, curY, curX);
    }
    else if (i == 1)
    {
        if (map[yy][xx] == 1 || map[yy][xx] == 2 || map[yy][xx] == 4 || map[yy][xx] == 7)
            push_check(yy, xx, curY, curX);
    }
    else if (i == 2)
    {
        if (map[yy][xx] == 1 || map[yy][xx] == 3 || map[yy][xx] == 4 || map[yy][xx] == 5)
            push_check(yy, xx, curY, curX);
    }
    else if (i == 3)
    {
        if (map[yy][xx] == 1 || map[yy][xx] == 3 || map[yy][xx] == 6 || map[yy][xx] == 7)
            push_check(yy, xx, curY, curX);
    }
}
 
 
int getResult()
{
    Queue.push({ r, c });
    check[r][c] = true;
    cost[r][c] = 1;
 
    while (!Queue.empty())
    {
        p front = Queue.front();
 
        Queue.pop();
        int curY = front.y;
        int curX = front.x;
        for (int i = 0; i < 4; i++)
        {
            int yy = dy[i] + curY;
            int xx = dx[i] + curX;
            if (0 <= yy && yy < n && 0 <= xx && xx < m && check[yy][xx] == false)
            {
                if (map[curY][curX] == 1)
                {
                    Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 2)
                {
                    if (i == 0 || i == 1) Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 3)
                {
                    if (i == 2 || i == 3) Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 4)
                {
                    if (i == 0 || i == 3) Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 5)
                {
                    if (i == 1 || i == 3) Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 6)
                {
                    if (i == 1 || i == 2) Tunnel(i, yy, xx, curY, curX);
                }
                else if (map[curY][curX] == 7)
                {
                    if (i == 0 || i == 2) Tunnel(i, yy, xx, curY, curX);
                }
            }
        }
    }
}
 
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> m >> r >> c >> l;
        memset(check, 0, sizeof(check));
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
 
        getResult();
 
        int cnt = 0;
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cost[i][j] > 0 && cost[i][j] <= l)
                    cnt++;
            }
        }
        cout << "#" << tc << " " << cnt << endl;
        //   memset(map, 0, sizeof(map));
    }
    return 0;
}