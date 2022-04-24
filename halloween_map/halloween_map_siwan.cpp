/*
W, H (맵 크기)
G (묘비 개수)
X Y (묘비 위치)
E (귀신 구멍의 수)
X1 Y1 X2 Y2 T (귀신 구멍 정보)

출력:
과거 Never
출구 못빠져 나오면 Impossible

0 1 -1
0 0 1
-1 0 0

0    0   0  0 
0   -3  -3  0 
*/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct p{
    int x;
    int y;
};


int main(){

    return 0;
}

/*
#include <stdio.h>

long long int combination(int n,int r){  
 // pascal's triangle 구현
  long long int arr[100][100]={0};
  for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
      if(i==0||j==0) arr[i][j]=1l;
      else arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
    }
  }
  return arr[n][r];
}

int main() {
  int n,m,y,x;
  scanf("%d %d",&n,&m);
  scanf("%d %d",&y,&x);
  
  if(n<=y || m<=x || (y==0 && x==0)) printf("fail");
  else printf("%d\n%lld", y+x, combination(x+y,x<y ? x: y));
  return 0;
}
*/