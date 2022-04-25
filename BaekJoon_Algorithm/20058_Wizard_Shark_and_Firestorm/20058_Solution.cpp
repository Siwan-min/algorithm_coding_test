#include <iostream>
#include <queue>
#include <math.h>

#define MAX 64

using namespace std;

int N, Q, ans;
int n_size;

int map[MAX][MAX];
int temp[MAX][MAX];
        // 동 서 남 북
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0,};

struct p {
    int y;
    int x;
};

void rotate(int y, int x, int part)
{
    for (int i = 0; i < part; ++i)
    {
        for(int j = 0; j < part; ++j)
        {
            temp[i][j] = map[y + i][x + j];
        }
    }

    for (int i = 0; i < part; ++i)
    {
        for(int j = 0; j < part; ++j)
        {
            map[y + i][x + j] = temp[part - 1 - j][i];
        }
    }
}

void melt(int N) 
{
    queue <p> q;
    for (int i = 0 ; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!map[i][j]) continue;
            int cnt = 0;
            for (int k = 0; k < 4; ++k)
            {
                int y = i + dy[k];
                int x = j + dx[k];
                if (y < 0 || x < 0 || x == N || y == N || !map[y][x]) continue;
                ++cnt;
            }
            if (cnt < 3) q.push({i, j});
        }
    }
    while (!q.empty())
    {
        --map[q.front().y][q.front().x];
        q.pop();
    }
    
}

int main()
{

    cin>>N>>Q;
    N = pow(2, N);
    int a = 1;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    
    while (Q--)
    {
        int L;
        cin >> L;
        if (!L) {
            melt(N);
            continue;
        }
        int part = (int)pow(2, L);
        for (int y = 0; y < N; y += part) 
        {
            for (int x = 0; x < N; x += part)
            {
                rotate(y, x, part);
            }
        }
        melt(N);
    }
    
    int sum = 0;
    int m = 0;
    
    queue<p> q;
    for (int i = 0 ; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            if (!map[i][j]) continue;
            sum += map[i][j];
            int now = 1;
            map[i][j] = 0;
            q.push({i, j});
            while (!q.empty())
            {
                int y = q.front().y;
                int x = q.front().x;
                q.pop();
                for (int k = 0; k < 4; ++k) 
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (nx < 0 || ny < 0 || nx == N || ny == N || ! map[ny][nx]) continue;
                    sum += map[ny][nx];
                    ++now;
                    map[ny][nx] = 0;
                    q.push({ny, nx});
                }
            }
            if ( now > m)  m = now;
            
        }
    }

    cout << sum << "\n" << m;
}