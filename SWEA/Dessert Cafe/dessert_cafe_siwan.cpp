/*
���� �ľ�: 
(1) �ʿ��� ����Ʈ ������ ��Ÿ���� ������ ������� 
(2) ������ ������ �簢���� �׸��鼭 �̵���. 
(3) ������ �翬�� ��� ���� ����. 
(4) �� �������θ� ȸ�� (�ð� ����) 
(5) ���� ������ ����Ʈ�� ���� ����. 
���: ��Ģ�� ���� �̵��� �� ����Ʈ�� �ִ�� � ���� �� �ִ��� ���Ͽ���.  
--------------------------------------------------------------
���� �ذ� ���: 
(1) �ʿ� ������ �޴´�
(2) ���� ����
	- ���� ��ġ�� �ʱ� ��ġ�� ���� �ϴܿ� ���� ���  
(3) visited �迭�� �Ἥ �湮 �ߴ��� ���ߴ����� Ȯ�� 
	-�湮�ߴ� �ڸ��� continue ó�� 
(4) dessert �迭�� �����  map[i][j]�� ���� ���� dessert �迭 �ε��� true ó���Ѵ�.
   - �̹� true �����̸� continue ó�� 
(5) (3), (4) ������
	- ny, nx �� ���� �ȿ� �ְ� visited[ny][nx], dessert[map[ny][nx]]�� false ������ ��� 
	dessert, visited�� true ó���ϰ� dfs(y��ġ, x��ġ, cnt+1) ��� ȣ���� �ϴ� ������� ��ó ����. 
(6) cnt�� max ���� ���Ѵ�. 

>> 
���� 0 �϶��� 0, 1 �� ����
���� 1 �϶��� 1, 2 �� ����
���� 2 �϶��� 2, 3 �� ���� 
���� 3 �϶��� 3 �� ����  
---------------------------------------------------------------------- 
 
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 110
using namespace std;

int T, n, result;
int map[30][30];
bool visited[30][30];
bool desert[MAX];
int startY, startX; //������ 
int dy[4] = {1, 1, -1, -1}; //(��,��), (��,��) , (��, ��), (��, ��) 
int dx[4] = {1, -1, -1, 1};

void dfs(int y, int x, int p, int cnt){
    
    if( y == startY+1 && x == startX-1){ //��������  
       if(result < cnt)
       result = cnt;
       return;
    }
    for(int i = 0; i < 4; i++){
      
        if (i < p || i > p + 1 || (cnt == 1 && i == 1)) continue;
		 //ù��° ������ ��츦 �����ؾ���  
		//���� ���� 
        int ny = y + dy[i];
        int nx = x + dx[i];
       
       if(ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && !desert[map[ny][nx]]){
          visited[ny][nx] = true;
          desert[map[ny][nx]] = true;
  
          dfs(ny, nx, i, cnt+1);
          
          visited[ny][nx] = false;
          desert[map[ny][nx]] = false;
       }
    }
    return; 
}
int main(){

    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        cin>>n;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>map[i][j];
            }
        }
        result = -1;
        for(int i = 0; i<n-2; i++){
            for(int j = 1; j<n-1; j++){
                startY = i, startX = j;
                visited[i][j] = true;
                desert[map[i][j]] = true;
                dfs( i, j, 0, 1);
                desert[map[i][j]] = false;
                visited[i][j] = false;
            }
        }
        cout<<"#"<<tc<<" "<<result<<endl;
    }
    return 0;
}
