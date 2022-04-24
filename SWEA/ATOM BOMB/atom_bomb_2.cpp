/*
 ��� ���

 1) 1�ʸ��� ���ڵ��� ���� ������ ������ �̵��Ѵ�.
 2) �̵��� ������ ��ġ�ϰ� �ִ� ���ڵ��� ������ �����Ѵ�.
 3) �ش� ��ġ�� ���ڵ��� ������ 2�� �̻��̸�
    �浹�� �ϴ� ���̹Ƿ� ���ڸ� �����ϰ�, �������� �����Ѵ�.
 4) �浹 ������ ���ڰ� �ϳ��� �������� �ʴٸ�
    �ش� �׽�Ʈ ���̽��� �����Ѵ�.
*/

#include <stdio.h>
using namespace std;

int atom[1000][4]; // ���� ����(0:x, 1:y, 2:����, 3:������)
int visit[4005][4005];
bool collision[4005][4005];
int nRest;

// ������ ���� �����ϴ� ������ �ڸ��� �ű��.
//�浹�� ���ڴ� ������ ���̻� ������� �����Ƿ� �׳� �����Ѵ�.
void RemoveAtom(int n, int* pnSize) 
{
    int nLastIndex = nRest - 1;
    // int nLastIndex = (*pnSize) - 1;
    atom[n][0] = atom[nLastIndex][0];
    atom[n][1] = atom[nLastIndex][1];
    atom[n][2] = atom[nLastIndex][2];
    atom[n][3] = atom[nLastIndex][3];
    //(*pnSize)--; // ���� ���� 1�� ����
    nRest--;
}

int solution(int N)
{
    nRest = N;
    int ans = 0;

    // �ð����� 2 ��� �ø��� ���� ��ǥ�赵 2 ��� �ø�
    for (int j = 0; j < nRest; ++j)
    {
        atom[j][0] = atom[j][0] * 2;
        atom[j][1] = atom[j][1] * 2;
        visit[atom[j][0]][atom[j][1]]++;
    }

    //nMaxLoop: -1000 ���� 1000 ���� 2000 ���� ���ڹ����� �� ��� �ø��� 0�� ���� �� ������
    int nMaxLoop = 4001; // �־��� ���� 0 ���� 4000 ���� ���ڰ� �����̴� ����̴�.
    for (int i = 0; i < nMaxLoop; ++i)
    {
        // ���� �̵�
        for (int j = 0; j < nRest; ++j)
        {
            int & x = atom[j][0]; //reference ������ ����
            int & y = atom[j][1];
            int d = atom[j][2];
            visit[x][y]--;
            if (d == 0) y++; // up
            else if (d == 1) y--; // down
            else if (d == 2) x--; // left
            else if (d == 3) x++; // right

            if (atom[j][0] < 0 || atom[j][0] > 4000 ||
            atom[j][1] < 0 || atom[j][1] > 4000) { // ���ڰ� ���� ����� ���
                RemoveAtom(j, &nRest); // ����� ���� ����
                j--; // ������ ���ڸ� �����⿡ �ٽ� �� �� for ������ ���ƾ��Ѵ�
            }
            else {
                visit[x][y]++;
                if (visit[x][y] >= 2) collision[x][y] = true;
            }
        }
        // ���� �浹 üũ
        for (int j = 0; j < nRest; ++j)
        {
            int x = atom[j][0]; int y = atom[j][1];
            if (collision[x][y] == true) {
                if (visit[x][y] == 1) collision[x][y] = false;
                visit[x][y]--;
                ans += atom[j][3];
                //�浹�Ǿ����Ƿ� �ش� ���� ����
                RemoveAtom(j, &nRest);
                j--;
            }
        }

        if (nRest == 0) break; //���� ���ڰ� ������ ����
    }
    return ans;
}

int main() 
{
    int T, test_case, N;
    
    scanf("%d\n", &T);

    for (test_case = 1; test_case <= T; test_case++)
    {
        N = 0;
        scanf("%d\n", &N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d %d %d %d", &atom[i][0], &atom[i][1],
                &atom[i][2], &atom[i][3]);
            atom[i][0] += 1000;
            // ��ǥ�� ���� �ƴ� ������ ������ֱ� ���� 1000 �� �����ش�
            atom[i][1] += 1000;
        }

        int nRes = solution(N);
        printf("#%d %d\n", test_case, nRes);
    }
}