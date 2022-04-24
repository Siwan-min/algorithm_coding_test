#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 330

int n, m, cnt;
int arr[MAX][MAX];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

bool visited[MAX][MAX];
bool flag = false;

struct p
{
    int y;
    int x;
};

queue<p> Queue;
void BFS(int y, int x)
{

    visited[y][x] = true;
    Queue.push({y, x});

    while (!Queue.empty())
    {

        p front = Queue.front();
        int curY = front.y;
        int curX = front.x;

        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int yy = curY + dy[i];
            int xx = curX + dx[i];

            if (yy >= 0 && yy < n &&
                xx >= 0 && xx < m &&
                !visited[yy][xx])
            {
                if (arr[yy][xx] == 0)
                    arr[curY][curX]--;

                else
                {
                    visited[yy][xx] = true;
                    Queue.push({yy, xx});
                }
            }
        }
        if (arr[curY][curX] < 0)
            arr[curY][curX] = 0;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int result = 0;
    //int cnt=0;

    while (cnt < 2)
    {
        result++;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] && !visited[i][j])
                {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            cout << "0";
            return 0;
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << result - 1;
    return 0;
}