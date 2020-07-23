#include <iostream>
#include <cstring>
#define MAX 15
using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
            //동 서 남 북

int Map[MAX][MAX];
bool check[MAX][MAX]; 

int tc, n, k, startPoint;
int tempY, tempX, tmp;
int cnt=1, _max;

bool flag = false; // 산을 깎았는지 표시

void getResult(int y, int x){
  
  for(int i = 0; i<4; i++){
    
    int yy = y + dy[i];
    int xx = x + dx[i];
    
    if(yy<0 || yy > n || xx < 0 || xx > n) continue;
    else if(yy >= 0 && yy < n && xx >= 0 && xx < n && check[yy][xx] == false){
      
      int tmp = 0;
      tmp = Map[yy][xx];
      
      if(Map[yy][xx] >= Map[y][x] && Map[yy][xx]-k < Map[y][x] ){
        if(flag == false) {
          Map[yy][xx] = Map[y][x]-1;
          tempY = y;
          tempX = x;
          flag = true; 
        }
      }
      
      if(Map[yy][xx]<Map[y][x]){
        check[y][x] = true;
        cnt++;
        if(cnt>_max) _max = cnt;
 
        getResult(yy, xx);
       
        if(y == tempY && x == tempX){
          tempY = 0;
          tempX = 0;
          flag = false;
        }
        Map[yy][xx] = tmp;
        check[y][x] = false;
        cnt--;
      }
    }
  }
}


int main(){
  
  cin>>tc;

  for(int t = 1; t<=tc; t++){
    cin>>n>>k;
    
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        cin>>Map[i][j];
        
        if(startPoint<Map[i][j]) startPoint = Map[i][j];
       
      }
    }
    
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        
        if(Map[i][j] == startPoint){
        
          getResult(i, j);

        }
      }
    }
    
    startPoint = 0;
    cout<<"#"<<t<<" "<<_max<<endl;
    _max = 0;
    memset(Map, 0, sizeof(Map));
    memset(check, 0, sizeof(check));
  }
  
  return 0;
}
