#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN*MAXN;

//��ġ�� ��Ÿ���� ����ü
struct PT {
    int r, c;
    PT() {}
    PT(int r, int c) : r(r), c(c) {}     
} man[MAXN], stair[2];

//N: �� �� ���� ����, M: ����� ��,  S(=2): ����� ��
int N, M, S;

//map: �Է����� �־����� ���� ����
int map[MAXN][MAXN];

//match[x]=y: x��° ����� y��° ����� Ÿ���� ������ ����
int match[MAXN];

int answer;

//man_index �� ����� stair_index �� ��� ������ �Ÿ�
int dist(int man_index, int stair_index) {
    int dx = abs(man[man_index].r - stair[stair_index].r);
    int dy = abs(man[man_index].c - stair[stair_index].c);
    return dx + dy;
}

//�� ����� ��� ����� �̿��� �� ��� �������� ��(=��� �Ϸ�� ������)
//�ʿ��� �ð��� ����ϴ� �Լ�
void update() {
    //��� ������� ����� �������µ� �ʿ��� �ּ� �ð�
    int total_min_time = 0;

    //�� ����� ���� �������̹Ƿ� ������ ���ؼ� ����Ѵ�.
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        //���� ���� now_stair �ε� PT Ÿ����.
        PT &now_stair = stair[stair_index];

        //arrival_time[t]: �ð� t�� �� ��ܿ� �����ϴ� ����� ��
        int arrival_time[MAXN * 2] = { 0, };

        //��� ����� arrival_time�� �����
        for (int man_index = 0; man_index < M; man_index++) {
            if (match[man_index] == stair_index) {
                //1�� �ĺ��� ����� �������Ƿ� +1, ����� ������ ���� ++
                arrival_time[dist(man_index, stair_index)+1]++;
            }
        }

        //�������� ������ ����� �������� ����� ��� �۾��� ��ġ�� ���� �ʿ��� �ּ� �ð�
        int now_min_time = 0;

        //current_stair[t]: �ð� t�� �� ����� �������� �ִ� ����� ��
        int current_stair[MAXT] = { 0, };

        //��ܿ� �����ϴ� �ð� ������������ �� ����� ����� ���������� �ùķ��̼�
        for (int time = 1; time <= 20; time++) {

            //time�� ������ ����� �ִٸ�
            while (arrival_time[time] > 0) {
                arrival_time[time]--;

                //�ش� ����� �������� �� �ʿ��� �ð�
                int remain_time = map[now_stair.r][now_stair.c];

                //��ܿ� ������ �������� ��� 3����
                //���ÿ� �������� ���� ���� ���� 1ĭ�� ������ ���� ������.
                for (int walk_time = time; walk_time < MAXT; walk_time++) {
                    if (current_stair[walk_time] < 3) {
                        
                        current_stair[walk_time]++;
                        remain_time--;

                        //����� �� ���������� now_min_time ����
                        if (remain_time == 0) {
                            //���� �ð� ��� �� �̵������� �ּҽð� ����
                            now_min_time = max(now_min_time, walk_time+1);
                            break;
                        }
                    }
                }
            }
        }

        //"��ü ����� �������� �� �ʿ��� �ּ� �ð�"
        // = (�� ����� �������µ� �ʿ��� �ּ� �ð�) �� �ִ�
        total_min_time = max(total_min_time, now_min_time);
    }

    //���� match ������ �� total_min_time �� �������� ����
    answer = min(answer, total_min_time);
}

void dfs(int man_index) {
    //��� ����� ���� �� ����� ����� ����� �� ���ߴٸ�
    if (man_index == M) {
        //�ش� ���¿��� �ʿ��� �ð��� ����ϰ� ���� ����
        update();
        return;
    }

    //man_index��° ����� stair_index ��° ����� �����ϰ�, 
    for (int stair_index = 0; stair_index < 2; stair_index++) {
        match[man_index] = stair_index;
        dfs(man_index + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        
        scanf("%d", &N);
        M = S = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &map[i][j]);

                //���� (i, j)�� ����̸�, �ش� ��ġ�� man�� ����
                if (map[i][j] == 1) man[M++] = PT(i, j);

                //���� (i, j)�� ����̸�, �ش� ��ġ�� stair�� ����
                if (map[i][j] >= 2) stair[S++] = PT(i, j);
            }
        }

        //���� ���Ѵ�� �ʱ�ȭ
        answer = 1e9;

        //���� �켱 Ž�� ����
        dfs(0);
        printf("#%d %d\n", tc, answer);
    }
}