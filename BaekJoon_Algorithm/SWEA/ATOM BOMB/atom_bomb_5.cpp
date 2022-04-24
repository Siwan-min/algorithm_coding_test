/*
 정답 코드
 조만기
 m/ 43976
 t/ 1116
 l/ 3082
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
int N;
int ans;
 
typedef struct {
    int x, y, dir, energy;
}Dir;
 
typedef struct {
    int count, cellnumber;
}map;
 
map board[2001][2001];
 
const Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };    //상 하 좌 우
vector<Dir> v;
queue<int> q;
 
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(board, 0, sizeof(board));
        v.clear();
        ans = 0;
 
        cin >> N;
        for (int i = 0; i < N; i++) {
            int X, Y, D, K;
            cin >> X >> Y >> D >> K;
            board[1000 - Y][1000 + X].count++;
            board[1000 - Y][1000 + X].cellnumber = i;
            v.push_back({ 1000 - Y, 1000 + X, D, K});
        }
 
        while (N) {
            int maxX = -1, maxY = -1, minX = 9999, minY = 9999;
            int mi[4]; // 최상단, 하단, 좌측, 우측에 있는 요소를 넣기 위한 배열.
            for (int i = 0; i < v.size(); i++) {
                if (v[i].x == -1) continue;
 
                int x = v[i].x + moveDir[v[i].dir].x;
                int y = v[i].y + moveDir[v[i].dir].y;
 
                if (x < 0 || y < 0 || x > 2000 || y > 2000) {
                    N--;
                    board[v[i].x][v[i].y].count = 0;
                    v[i].x = -1;
                    continue;
                }
 
                //만약 원자가 이동할 곳에 아직 실행되지 않은 다른 원자가 있다면 충돌.
                if (board[x][y].count && board[x][y].cellnumber > i) {
                    bool flag = false;
                    if (v[i].dir == 0 && v[board[x][y].cellnumber].dir == 1) flag = true;
                    if (v[i].dir == 1 && v[board[x][y].cellnumber].dir == 0) flag = true;
                    if (v[i].dir == 2 && v[board[x][y].cellnumber].dir == 3) flag = true;
                    if (v[i].dir == 3 && v[board[x][y].cellnumber].dir == 2) flag = true;
                    if (flag) {
                        ans = ans + v[i].energy + v[board[x][y].cellnumber].energy;
                        N -= 2;
                        board[v[i].x][v[i].y].count--;
                        board[x][y].count--;
                        v[board[x][y].cellnumber].x = -1;
                        v[i].x = -1;
                        continue;   //충돌 후 바로 다음 원자의 이동으로 넘어간다.
                    }
                }
                //앞의 조건에서 걸리지 않았다면 일단 모두 이동시킴.
                board[v[i].x][v[i].y].count--;
                v[i].x = x;
                v[i].y = y;             
                board[x][y].count++;
                board[x][y].cellnumber = i; //보드에 있는 원자번호 세팅.
 
                //이동 후 가장 최상단, 하단, 좌측, 우측에 있는 원자 탐색.
                if (v[i].x < minX) { minX = v[i].x; mi[0] = i; }
                if (v[i].x > maxX) { maxX = v[i].x; mi[1] = i; }
                if (v[i].y < minY) { minY = v[i].y; mi[2] = i; }
                if (v[i].y > maxY) { maxY = v[i].y; mi[3] = i; }
            }
 
            for (int i = 0; i < v.size(); i++) {
                if (v[i].x == -1) continue;
                if (board[v[i].x][v[i].y].count > 1)     //만약 한 점에 모여있는 원자 갯수가 2 이상일 때
                    q.push(i);                  //그 원자의 인덱스를 큐에 푸시해줌.
            }
 
            while (!q.empty()) {    //위에서 푸시한 인덱스 모두 처리.
                ans += v[q.front()].energy;
                board[v[q.front()].x][v[q.front()].y].count = 0;
                v[q.front()].x = -1;
                N--;
                q.pop();
            }
 
            for (int i = 0; i < 4; i++) { //가장 최상단에 있는데 상단으로 움직인다면.
                if (v[mi[i]].x == -1) continue;
                if (v[mi[i]].dir == i) {
                    board[v[mi[i]].x][v[mi[i]].y].count = 0;
                    v[mi[i]].x = -1;
                    N--;
                }
            }
        }
 
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}