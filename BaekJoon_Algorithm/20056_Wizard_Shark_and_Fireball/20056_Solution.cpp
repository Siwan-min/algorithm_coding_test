// /*

// 크기 N X N 
// 개수 M

// 파이어볼 각자 위체어서 이동을 대기
// 파이어볼 위치(r_i, c_i), 질량: m_i, 방향 : d, 속력: s

// 1번 행은 N번과 연결
// 1번 열은 N번과 연결

// 파이어볼의 방향은 어떤 칸과 인접한 8개의
// 칸의 방향을 의미하며, 정수로는 다음과 같다.

 
// */

// #include <iostream>
// #include <vector>

// using namespace std;

// struct FIREBALL
// {
//     int y, x;
//     int m, s, d;
// };

// const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
// const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// int N, M, K;
// vector<FIREBALL> ball;
// vector<int> map[50][50];

// void move() 
// {
//     vector<int> new_map[50][50];
//     for(int i = 0; i < ball.size(); i++)
//     {
//         int dir = ball[i].d;
//         int speed = (ball[i].s % N);
//         int ny = (ball[i].y + (dy[dir] * speed ) + N ) % N;
//         int nx = (ball[i].x + (dx[dir] * speed ) + N ) % N;
//         new_map[ny][nx].push_back(i);
//         ball[i].y = ny;
//         ball[i].x = nx;
//     }

//     for (int y = 0; y < N; y++)
//     {
//         for(int x = 0; x < N; x++)
//         {
//             map[y][x] = new_map[y][x];
//         }
//     }
// }

// void sum() 
// {
//     vector<FIREBALL> new_ball;
//     for(int y = 0; y < N; y++)
//     {
//         for(int x=0; x < N; x++)
//         {
//             if(map[y][x].size() == 0)
//             {
//                 continue;
//             }
//             if(map[y][x].size() == 1)
//             {
//                 int index = map[y][x][0];
//                 new_ball.push_back(ball[index]);
//                 continue;
//             }
//             int sum_m = 0, sum_s = 0;
//             bool odd = true, even = true;
//             for (int i = 0; i < map[y][x].size(); i++)
//             {
//                 int index = map[y][x][i];
//                 sum_m += ball[index].m;
//                 sum_s += ball[index].s;
//                 if(ball[index].d % 2 == 0)
//                 {
//                     odd = false;
//                 }
//                 else 
//                 {
//                     even = false;
//                 }
//             }
//             if (sum_m / 5 == 0 ) continue;

//             int cur_m = sum_m / 5;
//             int cur_s = sum_s / map[y][x].size();

//             for(int i = 0; i < 4; i++)
//             {
//                 if(odd || even) {
//                     new_ball.push_back({y, x, cur_m, cur_s, i * 2});
//                 }
//                 else 
//                 {
//                     new_ball.push_back({y, x, cur_m, cur_s, i * 2 + 1});
//                 }
//             }
//         }
//     }

//     ball = new_ball;
// }

// int solve()
// {
//     while(K--) 
//     {
//         move();
//         sum();
//     }
//     int ret = 0;
//     for(int i = 0; i < ball.size(); i++)
//     {
//         ret += ball[i].m;
//     }
//     return ret;
// }

// int main(){

//     cin>>N>>M>>K;

//     for(int i = 0; i < M; i++)
//     {
//         int y, x, m, s, d;
//         cin>>y>>x>>m>>s>>d;
//         --y, --x;
//         ball.push_back({y, x, m, s, d});
//         map[y][x].push_back(i);

//     }

//     int ret = solve();
//     cout << ret << endl;
//     return 0;
// }

#include <iostream>
#include <cstring>

#define MAX 50
#define endl "\n"

struct BALL {
    int ball = 0;
    int mass = 0;
    int speed = 0;
    int dir = 0;
    int even = 0;
    int odd = 0;
};

int N, M, K;

BALL map[MAX][MAX];

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int get_count()
{
    int ans = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            ans += (map[y][x].mass * map[y][x].ball);
        }
    }
    return ans;
}

void move() 
{
    BALL temp[MAX][MAX];

    for(int y = 0; y < N; ++y)
    {
        for(int x = 0; x < N; ++x)
        {
            if(map[y][x].ball == 0) continue;
            if(map[y][x].ball == 1)
            {
                int speed = map[y][x].speed;
                int mass = map[y][x].mass;
                int dir = map[y][x].dir;
                int ny = y + speed*dy[dir];
                int nx = x + speed*dx[dir];
                if( ny < 0) ny = N - ((-ny) % N);
                if( ny >= N) ny = ny % N;
                if( nx < 0) nx = N - ((-nx) % N);
                if( nx >= N) nx = nx % N;

                temp[ny][nx].ball++;
                temp[ny][nx].mass += mass;
                temp[ny][nx].speed += speed;
                temp[ny][nx].dir = dir;
                if (dir % 2 == 0)
                {
                    temp[ny][nx].even++;
                }
                else 
                {
                    temp[ny][nx].odd++;
                }
                continue;
            }
            if (map[y][x].ball == 4)
            {
                int dir = 1;
                if((map[y][x].odd > 0 && map[y][x].even == 0) ||
                    (map[y][x].even > 0 && map[y][x].odd == 0))
                {
                    dir = 0;
                    // for (int dir = 0; dir < 8; dir += 2)
                    // {
                    //     int ny = y + map[y][x].speed * dy[dir];
                    //     int nx = x + map[y][x].speed * dx[dir];

                    //     if( ny < 0) ny = N - ((-ny) % N);
                    //     if( ny >= N) ny = ny % N;
                    //     if( nx < 0) nx = N - ((-nx) % N);
                    //     if( nx >= N) nx = nx % N;

                    //     temp[ny][nx].ball++;
                    //     temp[ny][nx].mass += map[y][x].mass;
                    //     temp[ny][nx].speed += map[y][x].speed;
                    //     temp[ny][nx].dir = dir;
                    //     temp[ny][nx].even++;
                    // }
                }
                //else 
                //{
                //    dir = 1;
                    // for (int dir = 1; dir < 8; dir += 2)
                    // {
                    //     int ny = y + map[y][x].speed * dy[dir];
                    //     int nx = x + map[y][x].speed * dx[dir];

                    //     if( ny < 0) ny = N - ((-ny) % N);
                    //     if( ny >= N) ny = ny % N;
                    //     if( nx < 0) nx = N - ((-nx) % N);
                    //     if( nx >= N) nx = nx % N;
                    //     temp[ny][nx].ball++;
                    //     temp[ny][nx].mass += map[y][x].mass;
                    //     temp[ny][nx].speed += map[y][x].speed;
                    //     temp[ny][nx].dir = dir;
                    //     temp[ny][nx].odd++;
                    // }
                //}

                for( dir; dir < 8; dir += 2)
                {
                    int ny = y + map[y][x].speed * dy[dir];
                    int nx = x + map[y][x].speed * dx[dir];

                    if( ny < 0) ny = N - ((-ny) % N);
                    if( ny >= N) ny = ny % N;
                    if( nx < 0) nx = N - ((-nx) % N);
                    if( nx >= N) nx = nx % N;
                    temp[ny][nx].ball++;
                    temp[ny][nx].mass += map[y][x].mass;
                    temp[ny][nx].speed += map[y][x].speed;
                    temp[ny][nx].dir = dir;
                    (dir == 0) ? temp[ny][nx].even++ : temp[ny][nx].odd++;
                }
            }
        }
    }

    memcpy(map, temp, sizeof(temp));
    
}

void split() 
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if(map[y][x].ball > 1) 
            {
                map[y][x].mass /= 5;
                map[y][x].speed /= map[y][x].ball;
                map[y][x].ball = 4;

                if (map[y][x].mass == 0)
                {
                    memset(&map[y][x], 0, sizeof(map[y][x]));                    
                }
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int y, x, m, s, d;
        std::cin>>y>>x>>m>>s>>d;
        y--;
        x--;
        map[y][x].ball++;
        map[y][x].speed = s;
        map[y][x].mass = m;
        map[y][x].dir = d;

        if(d % 2 == 0)
        {
            map[y][x].even++;
        }
        else
        {
            map[y][x].odd++;
        }
    }

    while(K--)
    {
        move();
        split();
    }
    
    int ans = get_count();
    std::cout << ans << endl;
}
