/*
에러를 찾차
*/
#include <iostream>
using namespace std;
bool check = false;
int result[100];
int n;
/*
라이브러리 선언 ok
using namespace std; ok
bool check = false ; 확인 ok;
배열 선언 ok;
변수 ok; 
*/
bool isPossible(int x, int length){
  for(int i = 0; i< length; i++){
    if(result[x-i] != result[x-i-length]) 
    return true;
  }
  return false;
}
/*

*/

void getResult(int x){
  if(check == true) return; // checking condition good
  if(x >= n){ // ok 
    for(int i = 0; i<n; i++) cout<<result[i]; // output ok
    check = true; // good
    return ; // good
  }
  for(int i = 1; i<=3; i++){ // 숫자 세 개니까 1부터 3까지 
    result[x] = i; //배열에다가 1부터 하나씩 넣는다
    bool flag = false; 
    for(int j = 1; j<= (x+1)/2; j++){
      if(!isPossible(x,j)){ //가능 여부 확인
        flag=true;
        break;
      }
    }
    if(flag==false)
    getResult(x+1);
  }
}
/*
void good

*/
int main() {

  cin>>n;
  getResult(0);
  return 0;
}
/*
main fuction 
n was inserted
call getResult funciont 

*/