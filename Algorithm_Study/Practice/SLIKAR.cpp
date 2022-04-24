#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 55

using namespace std;

char Map[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int min, R, C, w, d, cnt;

struct p
{
    int y;
    int x;
};
queue<p> Queue1;
void water()
{

    while (!Queue1.empty())
    {
        p front = Queue1.front();
        Queue1.pop();

        int y = front.y;
        int x = front.x;

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy >= 0 && yy < R && xx >= 0 && xx < C)
            {
                if (Map[yy][xx] != 'D' && visited[yy][xx] == false && Map[yy][xx] != 'S')
                {
                    Map[yy][xx] = '*';
                    visited[y][x] = true;
                }
            }
        }
    }
}
queue<p> Queue2;
void BFS()
{

    while (!Queue2.empty())
    {
        p front = Queue2.front();
        Queue2.pop();

        int curY = front.y;
        int curX = front.x;

        for (int i = 0; i < 4; i++)
        {
            int yy = curY + dy[i];
            int xx = curX + dx[i];

            if (yy >= 0 && yy < R && xx >= 0 && xx < C && !visited[yy][xx] && Map[yy][xx] == '.')
            {
                Map[yy][xx] = 'S';
            }
            if (Map[yy][xx] == 'D')
            {
                cout << cnt << endl;
                return;
            }
        }
    }
}
/*
고슴도치가 갈 길이 없거나 
출구가 막혔거나
*/
int main()
{
    cin >> R >> C;
    ////////입력////////
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'X')
            {
                visited[i][j] = true;
            }
            if (Map[i][j] == 'D')
            {
                w = i;
                d = j;
            }
        }
    }
    /////////////////////탐색///////////
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (Map[i][j] == 'S')
                {
                    Map[i][j] = 'S';

                    Queue2.push({i, j});
                    visited[i][j] = true;
                }
                if (Map[i][j] == '*')
                {
                    Queue1.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        water();

        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int yy = w + dy[i];
            int xx = d + dx[i];

            if (Map[yy][xx] == 'S')
            {
                cout << cnt << endl;
                return 0;
            }
        }
        BFS();
    }

    cout << "KAKTUS";
    return 0;
}