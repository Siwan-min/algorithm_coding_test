//정답소스 1
//출제자 소스임
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
#define INF 1000
#define min(a,b) ((a)<(b)? (a):(b))
int ans;
int A[15][2], B[15][2];
char check[15];
 struct stair{
    int x, y, k;
}stair[2];
 
 
typedef struct p {
    int x, y;
    int d_a,d_b;
}p;
p person[10];
 
void dfs(int l,int last,int a_cnt,int b_cnt)
{   
    int max = 0;
    if (l >= last) {
        if (a_cnt == 0) max = B[b_cnt-1][1];
        else if (b_cnt == 0) max = A[a_cnt-1][1];
        else max = (A[a_cnt - 1][1] > B[b_cnt - 1][1] ? A[a_cnt - 1][1] : B[b_cnt - 1][1]);
        ans = min(ans, max);
    //  printf("%d %d %d %d\n",a_cnt,b_cnt, max, ans);
        return;
    }
    //A[a_cnt][1] = INF;
    //B[a_cnt][1] = INF;
    int idx = 0;
    int dist = INF;
    for (int i = 0; i < last; i++) {
        if ((person[i].d_a <= dist) && !check[i]) {
            dist = person[i].d_a;
            A[a_cnt][0] = person[i].d_a;
            A[a_cnt][1] = person[i].d_a + stair[0].k + 1; //계단입구, 계단끝까지 시간
            idx = i;
        }
    }
        check[idx] = 1;// 해당인덱스 
        if (a_cnt >= 3) {
            if (A[a_cnt - 3][0] == A[a_cnt][0]) A[a_cnt][0] += 1;
            else if (A[a_cnt - 3][0] > A[a_cnt][0]) A[a_cnt][0] = A[a_cnt - 3][0] + 1;
            if (A[a_cnt - 3][1] > A[a_cnt][0]) A[a_cnt][1] = A[a_cnt - 3][1] + stair[0].k , A[a_cnt][0] = A[a_cnt - 3][1];
        }
        //printf("%d %d\n", A[a_cnt][0], A[a_cnt][1]);
        dfs(l + 1, last, a_cnt + 1, b_cnt);
        check[idx] = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
        dist = INF;
        for (int i = 0; i < last; i++) {
            if ((person[i].d_b <= dist) && !check[i]) {
                dist = person[i].d_b;
                B[b_cnt][0] = person[i].d_b;
                B[b_cnt][1] = person[i].d_b + stair[1].k + 1; //계단입구, 계단끝까지 시간
                idx = i;
            }
        }
        check[idx] = 1;
        if(b_cnt>=3){
            if (B[b_cnt - 3][0] == B[b_cnt][0]) B[b_cnt][0] += 1;
            else if (B[b_cnt - 3][0] > B[b_cnt][0]) B[b_cnt][0] = B[b_cnt - 3][0] + 1;
            if (B[b_cnt - 3][1] > B[b_cnt][0]) B[b_cnt][1] = B[b_cnt - 3][1] + stair[1].k, B[b_cnt][0] = B[b_cnt - 3][1];
        }
        dfs(l + 1, last, a_cnt, b_cnt + 1);
        check[idx] = 0;
}
int main()
{
    int t, T,n;
    int cnt, r, value;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d", &n);
         cnt=0,r=0;
         ans = INF;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &value);
                if (value == 1) person[cnt].x = i, person[cnt++].y = j;
                if (value > 1) stair[r].x = i, stair[r].y = j, stair[r++].k =value;
            }
        for (int i = 0; i < cnt; i++) {
            person[i].d_a = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
            person[i].d_b = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
        }
        dfs(0, cnt, 0, 0);
        printf("#%d %d\n", t, ans);
    }
    return 0;
}