/*
문제파악:
활주로를 얼마나 건설할 수 있는지 알아보는 문제
활주로의 수: 가로 + 세로 갯수
높이가 모두 같다면 활주로 건설이 가능하다 
높이가 모두 같지 않을 경우 경사로를 이용하여 건설 할 수 있다.
경사로는 높이가 1, 길이가 X 이다.
경사로를 겹쳐서 지을수는 없다. 
---------------------------------------------------------------------------------------
문제 해결 방안:
높이 차이가 2 이상나면 건설이 불가능하다.
높이 차이가 1이지만 x 개 이상 연속으로 있을 경우 가능하다
높이가 낮아졌다가 높아지는 경우를 고려한다. 
---------------------------------------------------------------------------------------
쉬울거 같지만 은근 어려웠던 문제

*/

#include <iostream>
using namespace std;

int map[21][21];
int N, X;

int main(){
  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++){
    cin >> N >> X;
    for(int i = 0; i < N; i++){
      for (int j = 0; j < N; j++)
        cin >> map[i][j];
    }
    
    int result = 0;
    
    for(int i = 0; i < N; i++){
      int last = map[i][0], cnt = 1; bool flag = true;
      for (int j = 1; j < N; j++){
        if (map[i][j] - last > 1 || map[i][j] - last < -1) {
          flag = false; 
          break;
        }
      if(map[i][j] > last){
          if(cnt < X){
            flag = false;
            break;
          }
          else {
            last = map[i][j];
            cnt = 1;
          }
      }
      else if (map[i][j] == last) cnt++;
      else { //낮아졌다 높다지는 경우 
        last = map[i][j];
        int x = j;
        for (int k = 1; k < X; k++){
          if(k==N || map[i][x + k] != last){
            flag = false;
            break;
          }
        }
        if(!flag) break;
        j += X - 1;
        last = map[i][j]; cnt = 0;
      }
    }
    if (flag) result++;
  }
  
  for (int j = 0; j<N; j++){
    int last = map[0][j], cnt = 1; bool flag= true;
    for (int i = 1; i < N; i++){
      if(map[i][j] - last > 1 || map[i][j] - last < -1){
        flag = false;
        break;
      }
      if(map[i][j] > last){
        if(cnt < X){
          flag = false;
          break;
        }
        else{
          last = map[i][j];
          cnt = 1;
        }
      }
      else if (map[i][j] == last) cnt++;
      else{
        last = map[i][j];
        int x = i;
        for (int k = 1; k < X; k++){
          if(k==N || map[x + k][j] != last){
            flag = false;
            break;
          }
        }
        if(!flag) break;
        i += X - 1;
        last = map[i][j]; cnt = 0;
      }
    }
    if(flag) result++;
  }
  cout << "#" << tc <<" "<<result <<endl;
}
return 0;
}