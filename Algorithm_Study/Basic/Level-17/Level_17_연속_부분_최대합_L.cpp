/*
동적 계획법
연속 부분 최대합
A[i]를 오른 쪽 끝으로 갖는 구간의 최대 합을 반환하는 함수 maxAt(i)
A[i]에서 끝나는 최대 합 부분 구간은 항상 A[i] 하나만으로 구성되어 있거나, 
A[i-1]를 오른쪽 끝으로 갖는 최대 합 부분 구간의 오른쪽에 A[i]를 붙인 형태로 구성되어 있음을
증명할 수 있다.

점화식 >> maxAt(i) = max(0, maxAt(i-1)) + A[i]

*/

#include <stdio.h>
#include <vector>
using namespace std;

vector <int> A;

int n;
int fastersMaxSum(const vector<int>& A){
  int N = A.size(), ret = -987987987, psum = 0;
  
  for(int i = 0; i < N; ++i){
    psum = max(psum, 0) + A[i];
    ret = max(psum, ret);

  }
  
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int v;
    scanf("%d", &v);
    A.push_back(v);
  }
  
  int result = fastersMaxSum(A);
  printf("%d", result);
  
  return 0;
}