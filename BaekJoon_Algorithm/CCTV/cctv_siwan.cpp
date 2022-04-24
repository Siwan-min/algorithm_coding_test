/*
문제 파악:
(1) 최대 8 x 8 의 2차원 공간이 있음
(2) 빈 공간(0), 감시카메라(1~5), 벽(6)이 입력으로 들어옴
(3) 감시카메라 최대 개수는 8개
(4) 카메라는 고정 위치, 90도 회전 가능
(5) 벽은 투과 할 수 없음.
(6) 감시카메라를 적적히 잘 회전 시켜 감시 하지 못하는 공간이 가장 적게 되도록 함

결과 출력: 감시하지 못하는 공간의 개수를 출력
---------------------------------------------------------------------------------------
문제 해결 방안:
특별한 방법 없음
모든 경우의 수를 다 해본다.
시간 초과를 생각해본다. 
4^8 * 64 = 약 400만 

(1) 카메라 방향
 - 1번 카메라의 경우 : 4 방향 
 - 2번 카메라의 경우 : 2 방향
 - 3번 카메라의 경우 : 4 방향
 - 4번 카메라의 경우 : 4 방향
 - 5번 카메라의 경우 : 1 방향 
(2) (type, y, x)구조체 배열을 생성
    - 구조체 배열에 카메라 타입, y좌표, x 좌표를 만듬
    - 맵의 정보를 받으면서 cctv의 정보를 구조체 배열에 저장
(3) cctv 타입 별로 회전 경우의 수가 다르므로 회전 하는 경우의 rot_size를 타입 별로 지정 할 수 있는 배열을 만듬
    - 필요한 만큼만 돌린다. 
(4) 감시하지 못하는 공간의 최소 개수를 받을 ret 변수를 생성
    -최솟값을 받아야 하므로 ret 변수를 무한대로 지정
(5) 맵을 업데이트 하는 함수를 만듬
    -방향별로 구분을 해준다.
(6) dfs(cctv_index) 함수를 실행
    - 기저 조건: cctv_index가 cctv_size(cctv 갯수)와 같아지면 count
    - cctv 타입 별로 회전만큼만 돌리는 반복문을 만듬.
    - 맵을 백업 할 함수를 만들고 실행 전 맵을 저장해둔다
(7) 7번 과정이 끝나면 맵 백업 
(8) 기저조건 카운트 및 결과 출력
    
*/
#include <iostream>
//using namespace std;

int n, m, ret;
int map[8][8];
int cctv_size;

const int rot_size[] = {4, 2, 4, 4, 1};

struct CCTV
{
    int type, y, x;
};

CCTV cctv[8];
void map_cpy(int desc[8][8], int src[8][8])
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            desc[i][j] = src[i][j];
        }
    }
}

void update(int dir, CCTV cctv)
{
    dir = (dir % 4);
    if (dir == 0)
    { //동
        for (int x = cctv.x + 1; x < m; ++x)
        {
            if (map[cctv.y][x] == 6)
                break;
            map[cctv.y][x] = -1;
        }
    }
    else if (dir == 1)
    { //북
        for (int y = cctv.y - 1; y >= 0; --y)
        {
            if (map[y][cctv.x] == 6)
                break;
            map[y][cctv.x] = -1;
        }
    }
    else if (dir == 2)
    { //서
        for (int x = cctv.x - 1; x >= 0; --x)
        {
            if (map[cctv.y][x] == 6)
                break;
            map[cctv.y][x] = -1;
        }
    }
    else if (dir == 3)
    { // 남
        for (int y = cctv.y + 1; y < n; ++y)
        {
            if (map[y][cctv.x] == 6)
                break;
            map[y][cctv.x] = -1;
        }
    }
}

void dfs(int cctv_index)
{
    if (cctv_index == cctv_size)
    { // 기저조건
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == 0)
                    cnt++;
            }
        }
        if (cnt < ret)
            ret = cnt;
        return;
    }
    int backup[8][8];
    int type = cctv[cctv_index].type;

    for (int dir = 0; dir < rot_size[type]; ++dir)
    {
        map_cpy(backup, map);
        if (type == 0)
        {
            update(dir, cctv[cctv_index]);
        }
        else if (type == 1)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type == 2)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
        }
        else if (type == 3)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
        }
        else if (type = 4)
        {
            update(dir, cctv[cctv_index]);
            update(dir + 1, cctv[cctv_index]);
            update(dir + 2, cctv[cctv_index]);
            update(dir + 3, cctv[cctv_index]);
        }
        dfs(cctv_index + 1);
        map_cpy(map, backup);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];

            if (map[i][j] != 0 && map[i][j] != 6)
            {
                cctv[cctv_size].type = map[i][j] - 1;
                cctv[cctv_size].y = i;
                cctv[cctv_size].x = j;

                cctv_size++;
            }
        }
    }
    ret = 987987987;
    dfs(0);
    std::cout << ret << "\n";
    return 0;
}
// #include <iostream>
// #define size 8
// using namespace std;

// int n, m, result;
// int map[8][8];
// int cctv_size;
// const int rot_size[] = {4, 2, 4, 4, 1}; //카메라 탑입마다 가지는 방향 경우의 수

// struct CCTV
// {
//     int type, y, x;
// };

// CCTV cctv[8];

// void map_copy(int desc[8][8], int src[8][8])
// { // 맵 백업
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < m; ++j)
//         {
//             desc[i][j] = src[i][j];
//         }
//     }
// }

// void update(int dir, CCTV cctv)
// {
//     dir = (dir % 4);

//     if (dir == 0)
//     {
//         for (int x = cctv.x + 1; x < m; ++x)
//         {
//             if (map[cctv.y][x] == 6)
//                 break;
//             map[cctv.y][x] = -1; //갱신이 되었다
//         }
//     }
//     else if (dir == 1)
//     {
//         for (int y = cctv.y - 1; y >= 0; --y)
//         {
//             if (map[y][cctv.x] == 6)
//                 break;
//             map[y][cctv.x] = -1;
//         }
//     }

//     else if (dir == 2)
//     {
//         for (int x = cctv.x - 1; x >= 0; --x)
//         {
//             if (map[cctv.y][x] == 6)
//                 break;
//             map[cctv.y][x] = -1; //갱신이 되었다
//         }
//     }
//     else if (dir == 3)
//     {
//         for (int y = cctv.y + 1; y < n; ++y)
//         {
//             if (map[y][cctv.x] == 6)
//                 break;
//             map[y][cctv.x] = -1;
//         }
//     }
// }

// void dfs(int cctv_index)
// {
//     if (cctv_index == cctv_size)
//     { //기저 조건 : 모든 cctv를 검사하면 결과 출력
//         //count;
//         int candi = 0;
//         for (int y = 0; y < n; ++y)
//         {
//             for (int x = 0; x < m; ++x)
//             {
//                 if (map[y][x] == 0)
//                 {
//                     candi++;
//                 }
//             }
//         }

//         if (candi < result)
//             result = candi;
//         return;
//     }
//     int backup[8][8];
//     int type = cctv[cctv_index].type;

//     for (int dir = 0; dir < rot_size[type]; ++dir)
//     {                          //사이즈 만큼 반복
//         map_copy(backup, map); //맵을 백업하기 위해 미리 복사해둠
//         //map backup;
//         //map update
//         if (type == 0)
//         {
//             update(dir, cctv[cctv_index]);
//         }
//         else if (type == 1)
//         {
//             update(dir, cctv[cctv_index]);
//             update(dir + 2, cctv[cctv_index]);
//         }
//         else if (type == 2)
//         {
//             update(dir, cctv[cctv_index]);
//             update(dir + 1, cctv[cctv_index]);
//         }
//         else if (type == 3)
//         {
//             update(dir, cctv[cctv_index]);
//             update(dir + 1, cctv[cctv_index]);
//             update(dir + 2, cctv[cctv_index]);
//         }
//         else if (type == 4)
//         {
//             update(dir, cctv[cctv_index]);
//             update(dir + 1, cctv[cctv_index]);
//             update(dir + 2, cctv[cctv_index]);
//             update(dir + 3, cctv[cctv_index]);
//         }
//         dfs(cctv_index + 1);
//         map_copy(map, backup);
//     }
// }

// int main()
// {

//     cin >> n >> m;

//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < m; ++j)
//         {
//             cin >> map[i][j];

//             if (map[i][j] != 0 && map[i][j] != 6)
//             { //CCTV 정보를 받음
//                 cctv[cctv_size].type = map[i][j] - 1;
//                 cctv[cctv_size].y = i;
//                 cctv[cctv_size].x = j;

//                 ++cctv_size;
//             }
//         }
//     }

//     result = 100;
//     dfs(0);
//     cout << result << endl;

//     return 0;
// }

/*
6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5
result: 15
*/

