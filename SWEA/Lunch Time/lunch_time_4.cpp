//정답소스 4
//ㅈㅎㅈㅎ
// #s 2383 점심 식사 시간
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;
 
int n;
typedef struct xy {
    int x,y;
};
typedef struct info {
    int x, y, value;
};
typedef struct info2 {
    int now_time, origin_time;
};
 
int visit[11];//사람의 수는 1이상 10이하의 정수
vector <xy> people;
info stair[2];
int people_size;
int ans;
 
int distance(xy a, xy b) {// 거리를 구하는 함수
    return abs(a.x - b.x) + abs(a.y - b.y);
}
 
int simul() {//계단을 통해 이동하는 시뮬레이션
    //visit를 통해 어떤 계단으로 갈지 정해진 상황
    int in_stair[2][3];//이동하는 계단의 현 상황
    memset(in_stair, 0, sizeof(in_stair));
    priority_queue <int, vector<int>, greater<int> >pq[2];//대기 현황
 
    xy a, b;
    for (int i = 0; i < people_size; i++) {  
        int temp = visit[i];
        a = { people[i].x,people[i].y };
        b = { stair[temp].x,stair[temp].y};
        int x = distance(a, b);
        pq[temp].push(x+1);//- 계단 입구에 도착하면, 1분 후 아래칸으로 내려 갈 수 있다.
    }
    int ret = 0;
    for (int idx = 0; idx < 2; idx++) {
         
        //계단 i를 내려가는 시간
        int TIME = 0;//절대적인 현재 시간
        int out_cnt = 0;
        int total_people = pq[idx].size();
        while (true) {
            //  - 계단을 내려가는 시간은 계단 입구에 도착한 후부터 계단을 완전히 내려갈 때까지의 시간이다.
             
            for (int i = 0; i < 3; i++) {
                if (in_stair[idx][i] != 0) {
                    in_stair[idx][i]--;
                    if (in_stair[idx][i] == 0)out_cnt++;
                }
 
            }
             
            //  - 계단 위에는 동시에 최대 3명까지만 올라가 있을 수 있다.
            for (int i = 0; i < 3; i++) {
                if (pq[idx].empty())break;
                int need_time = pq[idx].top();
                //  - 이미 계단을 3명이 내려가고 있는 경우, 그 중 한 명이 계단을 완전히 내려갈 때까지 계단 입구에서 대기해야 한다.
                //-> no push
                if (in_stair[idx][i] == 0&&need_time<=TIME) {
                    pq[idx].pop();
                    //  - 계단마다 길이 K가 주어지며, 계단에 올라간 후 완전히 내려가는데 K 분이 걸린다.
                    in_stair[idx][i] = stair[idx].value;
                }
            }
 
            if (total_people == out_cnt)break;
            TIME++;// 모든 시뮬레이션이 끝나고 시간이 흐름 
        }
 
        ret = max(ret, TIME);
    }
    return ret;
     
}
 
void dfs(int num, int cnt) {
     
 
    //for (int i = 0; i < people_size; i++) {
    //  cout << visit[i] << " ";
    //}cout << endl;
    ans = min(ans, simul());
    if (cnt == people_size)return;
 
    for (int i = num; i < people_size; i++) {
        if (visit[i])continue;
        visit[i] = true;
        dfs(i, cnt + 1);
        visit[i] = false;
    }
}
 
void Input() {
    cin >> n;
    int idx = 0;
    int x;
    people.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1)people.push_back({ i,j });
            else if (x > 1) {
                stair[idx++] = {i,j,x};
            }
        }
    }
    people_size = people.size();
    ans = INF;
}
 
int main() {
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        Input();
        dfs(0, 0);
        cout << "#" << t << " " << ans << endl;
    }
     
}