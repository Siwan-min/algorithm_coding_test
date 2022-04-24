//숫자 만들기

/*
1~M 까지의 숫자를 더하여 N을 만드는 경우의 수는?

입력의 예
5   3
N   M

출력의 예
13


*/


// N         1 2 3 ... M
/*
1. how to define Table
2. hot to set recurrence formula

T(1) = 1 ~ M 까지의 숫자를 이용해서 숫자 i를 만드는 경우의 수
the number of case
T(i) = T(i-1) + T(i-2) + ....+T(i-M)
*/
#include <cstdio>
using namespace std;
const int MAX = 100;

int Table[MAX];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  
  /*
  
  M=4
  Table[1] = 1
  Table[2] = 2
  Table[3] = 4 (Table[2](2로 끝나는 경우) + Table[1] +1 (3으로 끝나느 경우) 
  Table[4] = Table[3] + Table[2] + Table[1] + 1
  
  Table[5] = Table[1]+ .... + Table[4]
  
  1~M
  */
  
  Table[1] = 1;
  int sum = 0;
  
  for(int i=2; i<=m; i++){
    sum += Table[i-1];
    Table[i] = sum+1;
  }
  
  for(int i = m+1; i<=n; i++){
    for(int j = i-m; j<=i-1; j++){
      Table[i] += Table[j];
    }
  }
  
  printf("%d\n", Table[n]);
  
  return 0;
}