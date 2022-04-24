/*
문제 파악: 
(1) D = |Xa - Xb| + |Ya - Yb|
(2) BC 위치(x, y), 충전 범위(c), 성능(p)
(3) 범위가 겹치는 부분에서는 선택 가능 
(4) 한 범위에 두 명이 있을 경우 성능(p) 분배

--> 결과 : 충전량 최댓값의 합 구하여라
--------------------------------------------------------

제약 사항: 
(1) 크기 : 10 x 10 
(2) 사용자 : 2명 
(3) 이동시간 : 20 ~ 100 이하
(4) 충전범위 : 1 ~ 4 이하 
(5) BC 개수 : 1 ~ 8 이하
(6) 위치 :
 - 시작점: A(1, 1), B(10, 10)
 - 정지: 0, 상 : 1, 우: 2, 하: 3, 좌: 4
 - 형태: (x, y) 형태 

--------------------------------------------------------

문제 해결 방안:

(1) 구조체 배열을 써서 AP 값이 가장 큰 것을 확인 해줄수 있는 인덱스 값을 넣어줌
(2) 맵이 겹치는 부분을 count로 표시해줌
(3) A, B를 시간별로 움직여준다.
(4) 조건을 확인해서 최적의 값을 구한다
  - A, B 각각 다른 인덱스 값을 갖는 경우
  - 맵 위치의 인덱스가 같고 오직 하나의 베터리를 공유하는 경우
  - 맵 위치의 인덱스는 같지만 갯수가 다른 경우
 (5) 변수에 AP 를 '+' 해줌 (디버깅을 위해 나는 배열에 시간별로 넣었음) 
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>
#define MAX 105
using namespace std;

int map[10][10][9];
int A[MAX], B[MAX]; // 사용자 
int T, M, BC;
const int dy[5] = {0, -1, 0, 1, 0};
const int dx[5] = {0, 0, 1, 0, -1};

struct info{
  int idx;
  int count;
};

info check[10][10];

int temp[10][10];
int Asum[MAX];
int Bsum[MAX];

int getResult(){
    int _sum = 0;
    int Ay = 0, Ax = 0;
    int By = 9, Bx = 9;
      int NAy = Ay;
      int NAx = Ax;
      
      int NBy = By;
      int NBx = Bx;
      
      int Ap = 0, Bp = 0;

     int t=0;
    while (t<=M)
    {
      
         NAy = NAy + dy[A[t]];
         NAx = NAx + dx[A[t]];
        
         NBy = NBy + dy[B[t]];
         NBx = NBx + dx[B[t]];

        Ap = map[NAy][NAx][check[NAy][NAx].idx];
        Bp = map[NBy][NBx][check[NBy][NBx].idx];
        if(Ap == 0 && Bp == 0) { 
          t++; 
          continue;
        }
        for(int i = 0; i<10; i++){
          for(int j = 0; j<10; j++){
            temp[NAy][NAx]=1;
            temp[NBy][NBx]=1;
          }
        }
        if(check[NAy][NAx].idx == check[NBy][NBx].idx && check[NAy][NAx].count == 1 && check[NBy][NBx].count == 1){
          Asum[t] = Ap/2;
          Bsum[t] = Bp/2;
          t++;
          continue;
        }
        int nAmax = 0, nBmax = 0;         
        for(int i = 1; i<=BC; i++){
          if(check[NBy][NBx].idx != i && nAmax < map[NAy][NAx][i]) nAmax = map[NAy][NAx][i];
          if(check[NAy][NAx].idx != i && nBmax < map[NBy][NBx][i]) nBmax = map[NBy][NBx][i];
        }

        if(nAmax > nBmax){
          Bsum[t] = Bp;
          Asum[t] = nAmax;
        }
        else if(nAmax < nBmax){
          Asum[t] = Ap;
          Bsum[t] = nBmax;
        }
        else{
          Asum[t] = Ap;
          Bsum[t] = nBmax;
        }      
        
    //  }
      t++;
    }

    for(int i = 0; i<=M; i++) _sum += Asum[i] + Bsum[i];
  return _sum;
}
int main(){
  
  cin>>T;
  
  for(int tc = 1; tc <= T; tc++){
    cin>>M>>BC;
    A[0] = 0;
    B[0] = 0;
    for(int i = 1; i <= M; i++) cin>>A[i];
    for(int i = 1; i <= M; i++) cin>>B[i];

    for(int idx = 1; idx <= BC; idx++){
      int x, y, c, p;
      cin>>x>>y>>c>>p;

      for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
          int Y = abs(i-y+1);
          int X = abs(j-x+1);
          if(Y+X <= c){
            map[i][j][idx] = p;
            if(map[i][j][check[i][j].idx] < p){
                check[i][j].idx = idx; 
            }
            check[i][j].count++;
          }
        }
      }
    }

  cout<<"#"<<tc<<" "<<getResult()<<endl;
  memset(map, 0, sizeof(map));
  memset(check, 0, sizeof(check));
  memset(Asum, 0, sizeof(Asum));
  memset(Bsum, 0, sizeof(Bsum));
  //_sum = 0;
  }
  
 
  return 0;
}
