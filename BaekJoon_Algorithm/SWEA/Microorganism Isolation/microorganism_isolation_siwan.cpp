/*

1�ð� ���� ������ �̻����� �����δ�. 
��: 1, ��: 2, ��: 3, ��: 4
�ε����� �̻��� ��: n/2 (n�� Ȧ���� ��� (n-1)/2�� ���)

������ �̵���Ű�� ���� ����� �ʴ�. 
�� �������� ���� �ٽ������� �ذ��ؾ� �� ����: 
(1) ���ð����� ���� �����ؼ� �̵� �� ���, �� (1, 1)�� �ִ� ���� (2, 1) �� �̵��ϰ�
 (2, 1)�� �ִ� ���� (1, 1)�� �̵� �� ��� ���� ��ġ�� �ʵ��� �ؾ��Ѵ�. 
(2) ���� ���� ���� ��� ������ ��� ���� ���ΰ�. 

������ ���� ����: 
����(1) Queue�� ���� �ʿ� �ִ� �����͵��� ��� push �ϰ� pop �ϸ鼭 Next ������ �ް� Storge�� push �Ѵ�.
Queue�� empty ���°� �Ǿ��� ��� Storge�� �ִ� �����͸� ��� �ʿ� �ٽ� �־��ش�.
�̷��� �ϸ� ����(1)�� �ذ� �� �� �ִ�.

����(2) ���� �� ������ ���� ��� ���� ū ���� temp�迭�� dir ���� ������ �д�.
�׷��� Storge�� �ִ� ���� �ʿ� ���� �� �̹� � ���� �ȿ� ���ִٸ�, temp�迭�� �ִ� ���� ���Ͽ� 
������ ���� �ʿ� �־��ش�. 
�̷��� �ϸ� ����(2)�� �ذ� �� �� �ִ�.

*/

#include <iostream>
#include <queue>
#include <cstring>

#define MAX 105

using namespace std;

int T, n, m, k;

struct info{
 
  int num;
  int dir;
  
};

const int dy[5] = {0, -1, 1, 0, 0};
const int dx[5] = {0, 0, 0, -1, 1};
                    //��, ��, ��, ��

struct p{
  
  int y;
  int x;
  int num;
  int dir;
  
};

info arr[MAX][MAX];
info temp[MAX][MAX];

queue <p> Queue; 
queue <p> Storge;

bool flag = false;

int getResult(){
  
  int cnt = 0;
  
  while(cnt<m){
    
    if(Queue.empty()){
      cnt++;
      memset(temp, 0, sizeof(temp));
      while(!Storge.empty()){
        
        p front = Storge.front();
        
        int insertY = front.y;
        int insertX = front.x;
        int insertN = front.num;
        int insertD = front.dir;
        Storge.pop();
        
        if(temp[insertY][insertX].num == 0){
          temp[insertY][insertX].num = insertN;
          temp[insertY][insertX].dir = insertD;
        }
        else{
          if(temp[insertY][insertX].num < insertN){
           temp[insertY][insertX].num = insertN;
           temp[insertY][insertX].dir = insertD;
          }
        }
      
        arr[insertY][insertX].num += insertN;
       
        if(arr[insertY][insertX].dir != 0) arr[insertY][insertX].dir = temp[insertY][insertX].dir;
        else arr[insertY][insertX].dir = insertD;
      }

      for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
       
        if(arr[i][j].num != 0) Queue.push({i, j, arr[i][j].num, arr[i][j].dir});
        }
      }
    }
    
    else{
      
      p front = Queue.front();
      
      int curY = front.y;
      int curX = front.x;
      int curN = front.num;
      int curD = front.dir;

      Queue.pop();
      
      int yy = curY + dy[curD]; 
      int xx = curX + dx[curD];
      int nn = 0;
      int dd = 0;
      
      if(yy == 0 || xx == 0 || yy == n-1 || xx == n-1 ){

        if( curN%2 == 0) nn = curN/2;
        
        else nn = (curN-1)/2;

        if(curD == 1) dd = 2;
        else if(curD == 2) dd = 1;
        else if(curD == 3) dd = 4;
        else if(curD == 4) dd = 3;
        
        Storge.push({yy, xx, nn, dd});
        
        arr[curY][curX].num = 0;
        arr[curY][curX].dir = 0;
        
      }
      
      else if( yy >= 1 && yy < n-1 && xx >= 1 && xx < n-1){
          nn = curN;
          dd = curD;
          arr[curY][curX].num = 0;
          arr[curY][curX].dir = 0;
          Storge.push({yy, xx, nn, dd});
      }
    }
    
  }
  
  int result = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(arr[i][j].num) result +=arr[i][j].num;
    }
  }
  return result;
}

int main(){
  
  cin>>T;
  
  for(int tc = 1; tc<=T; tc++){
    cin>>n>>m>>k;
    
    for(int i = 0; i<k; i++){
      int y, x, NumberOfMicro, dir;
      cin>>y>>x>>NumberOfMicro>>dir;
      Queue.push({y,x, NumberOfMicro, dir});
      arr[y][x].num = NumberOfMicro;
      arr[y][x].dir = dir;
    }
    
    cout<<"#"<<tc<<" "<<getResult()<<endl;  
    
    memset(arr, 0, sizeof(arr));
    
    while(!Queue.empty()){
      Queue.pop();
    }
    
  }
  
  return 0;
}


/*
1      
7 2 9   
1 1 7 1 
2 1 7 1
5 1 5 4
3 2 8 4 
4 3 14 1
3 4 3 3 
1 5 8 2 
3 5 100 1
5 5 1 1
*/