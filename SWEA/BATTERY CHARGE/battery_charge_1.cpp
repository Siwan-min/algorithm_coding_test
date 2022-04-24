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
    int x, y; //��ǥ
    int d; //����
    int p; //����
    int u; //���� ��� ����
} ap[maxa];

                 //��,��,��,��,��
const int dy[5] = { 0, 0, 1, 0, -1};
const int dx[5] = { 0,-1, 0, 1,  0};

void init() {
    //�� ���� ������ ���� ��ġ ����
    user[0].x = 1, user[0].y = 1;
    user[1].x = 10, user[1].y = 10;

    //��� AP�� ��� ���� ������ �ʱ�ȭ
    for (int i = 0; i < A; ++i) ap[i].u = 0;    
}

void read() {
    //M: �� �̵� �ð�, A: AP�� ����
    scanf("%d%d", &M, &A);

    //�� ���� ������ �̵� ���� ����
    for (int i = 0; i < maxu; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &move[i][j]);

    //A���� AP ���� ����
    for (int i = 0; i < A; ++i)
        scanf("%d%d%d%d", &ap[i].x, &ap[i].y, &ap[i].d, &ap[i].p);
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int abs(int a) {
    return a > 0 ? a : -a;
}

bool check(int a, int b) { //AP�� ���� �ȿ� �ִ��� Ȯ��
    int dist = abs(user[a].x - ap[b].x) + abs(user[a].y - ap[b].y);
    return dist <= ap[b].d;
}

int ret = 0;
void dfs(int user, int d) { //u: ����� ����, d: ������� �ٿ�ε��� �������� ��
    //���� ����
    if (user == maxu) {//U���� ����ڿ� ���� Ȯ���� �� ���
        ret = max(ret, d);
        //���ݱ��� ���� ������ ���� ������ ������ ũ�ٸ� ������ ���� ������Ʈ
        return;
    }

    //��� AP�� ���� Ž��
    for (int i = 0; i < A; ++i) {
        if (!ap[i].u && check(user, i)) {
            ap[i].u = 1;
            dfs(user + 1, d + ap[i].p);
            ap[i].u = 0;
        }
    }
    //���� ����� u�� AP������ ���� �ʴ� ��� ���� ����ڷ� �Ѿ��
    dfs(user+1, d);
}

int count() {
    ret = 0;
    dfs(0, 0);
    return ret;
}

int solve() {
    int ans = 0; //���������� ���� �� �ٿ�ε� ���� ���� �ִ�

    //�ʱ� ��ġ���� ����� A �� B �� �ٿ�ε� ���� �� �ִ� �������� �ִ�
    ans += count();

    //�̵���θ� ���� �̵�
    for (int i = 0; i < M; ++i) { //�� M�ð����� �̵�
        for (int j = 0; j < maxu; ++j) { //�� ����ڸ� ���� ��ġ�� �̵�
            user[j].x += dx[move[j][i]];
            user[j].y += dy[move[j][i]];
        }
        //�ش� �ð��� �������� ����� A�� B�� �ٿ�ε� ���� �� �ִ� �������� �ִ�
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