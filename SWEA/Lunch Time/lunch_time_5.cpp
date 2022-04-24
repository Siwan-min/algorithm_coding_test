//정답소스 5
//안산학생
#include<iostream>
#include<memory.h>
#include<vector>
#include<math.h>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
const int MAX = 11;
int arr[MAX][MAX];
int n;
 
int ans = 987987987;
 
//사람 배열
struct Man {
    int y;
    int x;
    int st1;
    int st2;
    int useSt;
};
Man man[11];
int manCnt = 0;
 
//계단 배열
struct St {
    int y;
    int x;
    int stTime;
};
St st[2];
int stCnt = 0;
 
bool cmp1(Man m1, Man m2) {
    return m1.st1 < m2.st1;
}
bool cmp2(Man m1, Man m2) {
    return m1.st2 < m2.st2;
}
int st1() {
    vector<Man> v;
    queue <int> q;
    for (int i = 0; i < manCnt; i++) {
        if (man[i].useSt == 1) {
            v.push_back(man[i]);
        }
    }
 
    if (v.empty()) return 0;
    int timer = 0;
    int cnt = 0;
    int arr[3] = { 0, };
    int use[3] = { 0, };
    while (true) {
        //시간 같은 것 찾기
        for (int i = 0; i < v.size(); i++) {
            if (v[i].st1 == timer) q.push(i);
        }
        //계단 이용 다 한 사람 내보내기
        for (int i = 0; i < 3; i++) {
            if (arr[i] <= timer && use[i] != 0) {
                use[i] = 0;
                cnt++;
            }
        }
        //내보낸 사람과 사이즈가 같으면 return;
        if (cnt == v.size()) return timer;
        //빈방이고 대기하는 사람이 있으면 계단 내려보내기
        for (int i = 0; i < 3; i++) {
            if (arr[i] <= timer && use[i] == 0 && !q.empty()) {
                use[i] = 1;
                arr[i] = timer + st[0].stTime;
                q.pop();
            }
        }
        timer++;
    }
}
int st2() {
    vector<Man> v;
    queue <int> q;
    for (int i = 0; i < manCnt; i++) {
        if (man[i].useSt == 2) {
            v.push_back(man[i]);
        }
    }
 
    if (v.empty()) return 0;
    int timer = 0;
    int cnt = 0;
    int arr[3] = { 0, };
    int use[3] = { 0, };
    while (true) {
        //시간 같은 것 찾기
        for (int i = 0; i < v.size(); i++) {
            if (v[i].st2 == timer) q.push(i);
        }
        //계단 이용 다 한 사람 내보내기
        for (int i = 0; i < 3; i++) {
            if (arr[i] <= timer && use[i] != 0) {
                use[i] = 0;
                cnt++;
            }
        }
        //내보낸 사람과 사이즈가 같으면 return;
        if (cnt == v.size()) return timer;
        //빈방이고 대기하는 사람이 있으면 계단 내려보내기
        for (int i = 0; i < 3; i++) {
            if (arr[i] <= timer && use[i] == 0 && !q.empty()) {
                use[i] = 1;
                arr[i] = timer + st[1].stTime;
                q.pop();
            }
        }
        timer++;
    }
}
void dfs(int cnt) {
    if (cnt == manCnt) {
 
        int temp1 = st1();
        int temp2 = st2();
        int m;
        if (temp1 > temp2) m = temp1;
        else if (temp1 < temp2) m = temp2;
        else m = temp1;
 
        if (m < ans) ans = m;
 
        return;
    }
 
    man[cnt].useSt = 1;
    dfs(cnt + 1);
    man[cnt].useSt = 2;
    dfs(cnt + 1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
 
    int p;
    cin >> p;
    for (int t = 1; t <= p; t++) {
 
        cin >> n;
        manCnt = 0;
        stCnt = 0;
        ans = 987987987;
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 1) {
                    man[manCnt].y = i;
                    man[manCnt].x = j;
                    manCnt++;
                }
                else if (arr[i][j] > 1) {
                    st[stCnt].y = i;
                    st[stCnt].x = j;
                    st[stCnt].stTime = arr[i][j];
                    stCnt++;
                }
            }
        }
 
        //계단까지의 이동거리 계산
        for (int i = 0; i < manCnt; i++) {
            man[i].st1 = abs(man[i].y - st[0].y) + abs(man[i].x - st[0].x) + 1;
            man[i].st2 = abs(man[i].y - st[1].y) + abs(man[i].x - st[1].x) + 1;
        }
 
        //완전탐색 실시
        dfs(0);
 
        if (ans == 987987987) cout << "#" << t << " " << -1 << endl;
        else cout << "#" << t << " " << ans << endl;
    }
    return 0;
}