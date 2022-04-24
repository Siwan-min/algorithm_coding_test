/*
-------------------------------------------------------------------------------------------------------------
(1) 사과 먹으면 늘어난다.
(2) 벽 또는 자기자신의 몸과 부딪히면 게임 끝.
(3) 보드의 상하좌우 끝에 벽이 있다. 뱀 길이 : 1, 위치 (0, 0)
(4) 뱀은 처음 오른쪽을 향한다
- 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
- 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
- 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸 길이는 변하지 않는다. 

결과: 사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라. 

------------------------------------------------------------------------------------------------------------
입력
첫줄 : 보드 크기 N (2 <= N <=100) 
사과의 개수 K (0 <= k <= 100)
사과의 위치 ( 행, 열)
뱀의 방향 변환 횟수 L
뱀의 방향 전환 정보 (정수 X, 문자 C ( L 왼쪽 90도 회전, D 오른쪽 90도 회전 ))

-------------------------------------------------------------------------------------------------------------
문제 해결 방안: 

중요한 점: 꼬리가 길어지는게 아니라 멀이가 길어진다고 생각해라!!!!

1. 정수형 배열에 맵의 정보를 받는다.
2. 구조체 큐에 시간과 방향을 받는다.
    (1) 방향과 시간 정보 받을 구조체 int, char
    (2) 뱀의 자리 정보를 받을 구조체 int, int
3. 완전탐색
 (1) sec ++ 하면서 큐 프론트 값이 가진 시간과 현재 시간이 같을 때 방향 전환 실시 
 (2) 아닐경우 계속 직진한다.
     - 벽에 부딪히면 게임 종료 ( sec 출력)
     - 자기 자신과 부딪혀도 게임 종료
 (3) 사과가 아닐경우 큐 pop() , 꼬리부분 false 처리;
 (4) 사과일 경우 true 처리
 (5) 방향처리 
     - dir 이 'L' 이면 idx-- 
     - dir 이 'R' 이면 idx++

*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int N, K, L;
bool visited[MAX][MAX];
bool apple[MAX][MAX];

struct p
{
    int t;
    char dir;
};

struct s
{
    int y;
    int x;
};

queue<p> DirInfo;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int k = 0; k < K; k++)
    {
        int y, x;
        cin >> y >> x;

        apple[y - 1][x - 1] = true; // 사과 위치 true 처리
    }

    cin >> L;
    for (int l = 0; l < L; l++) //시간, 방향에 대한 정보를 담는다.
    {
        int X;
        char C;
        cin >> X >> C;
        DirInfo.push({X, C});
    }

    int sec = 0;
    int idx = 0; //초기 오른쪽
    queue<s> snake;
    snake.push({0, 0});   //초기 위치
    visited[0][0] = true; //방문 처리

    while (1)
    {
        sec++;                                            //시간 ++
        s before = snake.back();                          //큐의 가장 뒤에 있는게 머리! 직전 임
        s cur = {before.y + dy[idx], before.x + dx[idx]}; // 전 + 방향 값은 다음에 갈 자리
        //뱀의 머리가 몸에 부딪히거나, 범위를 벗어날 경우
        if (visited[cur.y][cur.x] || (cur.y < 0 || cur.y >= N || cur.x < 0 || cur.x >= N))
        {
            cout << sec << "\n";
            break;
        }
        visited[cur.y][cur.x] = true;
        snake.push(cur);
        //사과가 있는 위치면 꼬리 그대로
        if (apple[cur.y][cur.x])
            apple[cur.y][cur.x] = false;
        //사과 없으면 꼬리가 있던 칸을 지운다
        else
        {
            s tail = snake.front();
            visited[tail.y][tail.x] = false;
            snake.pop();
        }
        //마지막에 방향 전환
        if (DirInfo.size() && DirInfo.front().t == sec)
        {
            if (DirInfo.front().dir == 'L')
            {
                idx--;
                if (idx == -1)
                    idx = 3;
            }
            else
            {
                idx++;
                if (idx == 4)
                    idx = 0;
            }
            DirInfo.pop(); //꼬리
        }
    }
    return 0;
}