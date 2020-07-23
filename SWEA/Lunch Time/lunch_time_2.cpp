//정답소스 2
//3기/서울/15반/김용준

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
 
using namespace std;
int T, N, ans, personCnt, map[10][10], sel[10], stair[2][3]; // row,col,K
struct node { int x, y; };
vector<node> vc_person;
 
int getDist(int PR, int PC, int SR, int SC) {
    return abs(PR - SR) + abs(PC - SC) + 1;
}
 
void powerSet(int cnt) {
    if (cnt == personCnt) {
        vector<int> S[2]; // 계단 앞까지 도착하는데 걸리는 시간
        for (int idx = 0; idx < personCnt; idx++) {
            if (!sel[idx]) S[0].push_back(getDist(vc_person[idx].x, vc_person[idx].y, stair[0][0], stair[0][1]));
            else S[1].push_back(getDist(vc_person[idx].x, vc_person[idx].y, stair[1][0], stair[1][1]));
        }
 
        sort(S[0].begin(), S[0].end());
        sort(S[1].begin(), S[1].end());
        int size1 = S[0].size(); int size2 = S[1].size();
 
        // 1번 계단
        int time1 = 0;
        if (size1) {
            if (size1 <= 3) time1 = S[0][size1 - 1] + stair[0][2];
            else time1 = MAX(S[0][size1 - 4] + 2 * stair[0][2], S[0][size1 - 1] + stair[0][2]);
        }
 
        // 2번 계단
        int time2 = 0;
        if (size2) {
            if (size2 <= 3) time2 = S[1][size2 - 1] + stair[1][2];
            else time2 = MAX(S[1][size2 - 4] + 2 * stair[1][2], S[1][size2 - 1] + stair[1][2]);
        }
 
        ans = MIN(ans, MAX(time1, time2));
        return;
    }
 
    sel[cnt] = 1;
    powerSet(cnt + 1);
    sel[cnt] = 0;
    powerSet(cnt + 1);
}
 
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // set data
        cin >> N; ans = 1000;
        for (auto v : vc_person) vc_person.pop_back();
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                stair[i][j] = -1;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                cin >> map[x][y];
                if (map[x][y] == 1) vc_person.push_back({ x,y });
                if (map[x][y] > 1) {
                    if (stair[0][0] == -1) { stair[0][0] = x; stair[0][1] = y; stair[0][2] = map[x][y]; }
                    else { stair[1][0] = x; stair[1][1] = y; stair[1][2] = map[x][y]; }
                }
            }
        }
        personCnt = vc_person.size();
 
        // 부분집합 
        powerSet(0);
 
        // print
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}