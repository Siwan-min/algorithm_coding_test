#include <stdio.h>

int main(){
  int arr[5][5];

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      scanf("%d",&arr[i][j]);
    }
  }

  int order = 0;
  for(int i=0; i<5; i++){
    for(int j = 0; j<5; j++){
      
      int n;
      scanf("%d", &n);
      order++;
    
      for(int p = 0; p<5; p++){
      
        for(int q = 0; q<5; q++){
          if(arr[p][q]==n) arr[p][q]=-1;
        }
       
      }
     
      int cnt=0;
      for(int i = 0; i<5; i++){
        int Xcnt=0; //한 줄씩 카운트 할거니까
        for(int j = 0; j<5; j++){
          if(arr[i][j]==-1) Xcnt++;
        }
        if(Xcnt==5) cnt++;
      }
      for(int i = 0; i<5; i++){
        int Xcnt=0; //한 줄씩 카운트 할거니까
        for(int j = 0; j<5; j++){
          if(arr[j][i]==-1) Xcnt++;
        }
        if(Xcnt==5) cnt++;
      }
      
      if(arr[0][0]==-1&&arr[1][1]==-1&&arr[2][2]==-1&&arr[3][3]==-1&&arr[4][4]==-1) cnt++;
      
      if(arr[0][4]==-1&&arr[1][3]==-1&&arr[2][2]==-1&&arr[3][1]==-1&&arr[4][0]==-1) cnt++;
      
      if(cnt>=3){
        printf("%d", order);
        return 0;
      }
    }
  }
  
  
  return 0;
}