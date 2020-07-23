#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const int maxu = 2;
const int maxn = 100;
const int maxa = 8;

int T, M, A;

struct {
    int x, y;
} user[maxu];

int move[maxu][maxn];

struct {
    int x, y; //좌표
    int d; //범위
    int p; //성능
    int u; //현재 사용 여부
} ap[maxa];

                 //현,상,우,하,좌
const int dy[5] = { 0, 0, 1, 0, -1};
const int dx[5] = { 0,-1, 0, 1,  0};

void init() {
    //두 명의 유저의 시작 위치 설정
    user[0].x = 1, user[0].y = 1;
    user[1].x = 10, user[1].y = 10;

    //모든 AP를 사용 안한 것으로 초기화
    for (int i = 0; i < A; ++i) ap[i].u = 0;    
}

void read() {
    //M: 총 이동 시간, A: AP의 개수
    scanf("%d%d", &M, &A);

    //두 명의 유저의 이동 정보 저장
    for (int i = 0; i < maxu; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &move[i][j]);

    //A개의 AP 정보 저장
    for (int i = 0; i < A; ++i)
        scanf("%d%d%d%d", &ap[i].x, &ap[i].y, &ap[i].d, &ap[i].p);
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int abs(int a) {
    return a > 0 ? a : -a;
}

bool check(int a, int b) { //AP가 범위 안에 있는지 확인
    int dist = abs(user[a].x - ap[b].x) + abs(user[a].y - ap[b].y);
    return dist <= ap[b].d;
}

int ret = 0;
void dfs(int user, int d) { //u: 사용자 숫자, d: 현재까지 다운로드한 데이터의 양
    //종료 조건
    if (user == maxu) {//U명의 사용자에 대해 확인을 한 경우
        ret = max(ret, d);
        //지금까지 받은 데이터 양이 기존의 값보다 크다면 기존의 값을 업데이트
        return;
    }

    //모든 AP에 대해 탐색
    for (int i = 0; i < A; ++i) {
        if (!ap[i].u && check(user, i)) {
            ap[i].u = 1;
            dfs(user + 1, d + ap[i].p);
            ap[i].u = 0;
        }
    }
    //현재 사용자 u는 AP접속을 하지 않는 경우 다음 사용자로 넘어간다
    dfs(user+1, d);
}

int count() {
    ret = 0;
    dfs(0, 0);
    return ret;
}

int solve() {
    int ans = 0; //최종적으로 답이 될 다운로드 받은 양의 최댓값

    //초기 위치에서 사용자 A 와 B 가 다운로드 받을 수 있는 데이터의 최댓값
    ans += count();

    //이동경로를 따라 이동
    for (int i = 0; i < M; ++i) { //총 M시간동안 이동
        for (int j = 0; j < maxu; ++j) { //각 사용자를 다음 위치로 이동
            user[j].x += dx[move[j][i]];
            user[j].y += dy[move[j][i]];
        }
        //해당 시간과 지점에서 사용자 A와 B가 다운로드 받을 수 있는 데이터의 최댓값
        ans += count();
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        read();
        init();
        printf("#%d %d\n", t, solve());
    }
    return 0;
}