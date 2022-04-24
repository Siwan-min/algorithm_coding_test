/*
문제 파악:
(1) 4개의 톱니바퀴가 있고 각각의 톱니바퀴는 8개의 톱니로 되어있다. 
(2) 각각의 톱니는 N극 또는 S극이다.
(3) 총 K번을 회전 시킨다.
    - 시계 방향 ("1") or 반시계 방향 ("-1")
(4) 이웃한 톱니의 극성이 서로 다르면 이웃한 톱니는 원래 회전하는 톱니와 반대 방향으로 회전한다.
    - 톱니의 회전은 연쇄적으로 일어날 수 있다.

결과: K번 회전을 한 후 각 톱니 12시 방향의 극성으로 하여 톱니의 상태를 구하라.
 - 1번 톱니바퀴 12시 방향 N극이면 0점, S극이면 1점
 - 2번 톱니바퀴 12시 방향 N극이면 0점, S극이면 2점
 - 3번 톱니바퀴 12시 방향 N극이면 0점, S극이면 4점
 - 4번 톱니바퀴 12시 방향 N극이면 0점, S극이면 8점

-----------------------------------------------------------------------------
문제 해결 방안: 
(1) 배열에 톱니의 정보를 받는다. >> gear[4][8]
(2) 회전하는 함수를 만든다
    - 방향이 1 이면 시계방향, -1 이면 반시계 방향
(3) K를 받고 K  만큼 반복문 실행
(4) 배열에 회전 정보를 받는다. 
    - 0번쨰부터 받으므로 gear_idx--;
    - c[gear_idx] = dir
    - 첫 번째는 무조건 회전
    - 그 다음부터 왼쪽과 오른쪽을 나누어 탐색, 마주하고 있는 극성이 서로 같으면 break
(4) c[0~3] 회전 함수 실행
(5) gear[i][0] 계산하여 출력 
*/

#include <stdio.h>

int gear[4][8];
int k;

void rotate(int idx, int dir)
{
    if (dir == 1) // 시계 방향 회전
    {
        int temp = gear[idx][7];
        for (int i = 6; i >= 0; i--)
            gear[idx][i + 1] = gear[idx][i];

        gear[idx][0] = temp;
    }
    else //반시계 방향 회전
    {
        int temp = gear[idx][0];
        for (int i = 1; i < 8; i++)
        {
            gear[idx][i - 1] = gear[idx][i];
        }
        gear[idx][7] = temp;
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            scanf("%1d", &gear[i][j]); //배열에 저장

    scanf("%d", &k);
    int gear_idx, dir;
    while (k--)
    {
        int c[4] = {0}; //회전 정보 받는 배열
        scanf("%d %d", &gear_idx, &dir);
        gear_idx--;        //인덱스 0번째부터 받으므로 (-) 해준다.
        c[gear_idx] = dir; //첫 지정 자석은 무조건 회전
        int nextd = dir;
        for (int i = gear_idx + 1; i < 4; i++) // 오른쪽 탐색
        {
            nextd = -nextd; //이웃 톱니바퀴는 방향이 반대로 돌아가므로
            if (gear[i][6] == gear[i - 1][2])
                break;
            c[i] = nextd;
        }
        nextd = dir;
        for (int i = gear_idx - 1; i >= 0; i--) // 왼쪽 탐색
        {
            nextd = -nextd;
            if (gear[i][2] == gear[i + 1][6])
                break;
            c[i] = nextd;
        }
        for (int i = 0; i < 4; i++)
            if (c[i])
                rotate(i, c[i]);
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) //점수 계산
    {
        if (gear[i][0] == 1)
            sum += (1 << i);
    }
    printf("%d", sum);
    return 0;
}
