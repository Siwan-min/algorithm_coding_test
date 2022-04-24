#include <iostream>

#define MAX 510
#define endl "\n"

int N, Answer;
int MAP[MAX][MAX];

// 위 아래 오른쪾 왼쪽

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

using namespace std;

int yPos[4][10] = {
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} 
};

int xPos[4][10] = { 
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, 
	{-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};

int ratio[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5};

void Input() {

    cin >> N;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }
}

int Change_Dir(int Dir) {

    if (Dir == 0) return 3;
    if (Dir == 1) return 2;
    if (Dir == 2) return 0;
    if (Dir == 3) return 1;
}

void Spread_Sand (int y, int x, int dir) {

    int yy = y + dy[dir];
    int xx = x + dx[dir];

    if (MAP[yy][xx] == 0) return;

    int Sand = MAP[yy][xx];
    int Temp = Sand;

    for(int i = 0; i < 9; i++) {
        int ny = y + yPos[dir][i];
        int nx = x + xPos[dir][i];
        int per = ratio[i];
        int plus = (Temp * per) / 100;

        if(ny < 1 || nx < 1 || ny > N || nx > N ) Answer += plus;
        else MAP[ny][nx] += plus;

        Sand -= plus;

    }

    int ny = y + yPos[dir][9];
    int nx = x + xPos[dir][9];

    if(ny < 1 || nx < 1 || ny > N || nx > N ) Answer += Sand;
    else MAP[ny][nx] += Sand;

    MAP[yy][xx] = 0;

}

void Solution() {

    int x = (N + 1) / 2;
    int y = (N + 1) / 2;
    int Dir = 1;
    int Move_Cnt = 1;

    while (1)
    {
        for(int i = 0; i < 2; i++) {
            for (int j = 0; j < Move_Cnt; j++) {
                Spread_Sand(y, x, Dir);
                y += dy[Dir];
                x += dx[Dir];
            }
            Dir = Change_Dir(Dir);
        }

        Move_Cnt++;
        if(Move_Cnt == N) {
            for (int j = 0; j < Move_Cnt; j++) {
                Spread_Sand(y, x, Dir);
                y += dy[Dir];
                x += dx[Dir];
            }
            break;
        }
    }
    cout << Answer << endl;
    
}

void Solve() {

    Input();
    Solution();
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    
    return 0;
}