#include <stdio.h>

int main() {

  int arr[8][8];
  int rookY[2], rookX[2], rookCnt = 0;
  for(int i = 0; i<8; i++){
    for(int j=0; j<8; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] == 2){
        rookY[rookCnt] = i;
        rookX[rookCnt] = j;
        
        rookCnt++;
      }
    }
  }
  bool flag = false; //잡을 수 없다면 false, 잡을 수 있다면 true
  
  for(int k=0; k<2; k++){
   int ry, rx;
    ry = rookY[k];
    rx = rookX[k];
    for(int i = rx+1; i<8; i++){
      if(arr[ry][i]==1) flag = true;
      else if(arr[ry][i] == 3)break;
    }
  
    for(int i = ry-1; i>=0; i--){
      if(arr[i][rx] == 1) flag = true;
      else if(arr[i][rx]==3) break;
    }
  
    for(int i = rx-1; i>=0; i--){
      if(arr[ry][i] == 1) flag = true;
      else if(arr[ry][i]==3)break;
    }
  
    for(int i=ry+1; i<8; i++){
      if(arr[i][rx] ==1) flag = true;
      else if(arr[i][rx] ==3) break;
    }
  }
  
  if(flag == true) printf("1");
  
  else
  printf("0");
  //(1) 룩 1에게 킹을 잡을 수 있는지 물어보기. --> Yes or NO
  //(2) 룩 1에게 킹을 잡을 수 있는지 물어보기. --> Yes or NO
  //(3) 둘중 하나라도 킹을 잡을 수 있다면 킹은 잡힐 수 있음. 그게 아니면 안잡힘
  return 0;
}