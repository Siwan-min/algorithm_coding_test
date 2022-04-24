#include <iostream>
using namespace std;
int arr[7][7];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(){
  
  for(int i = 0; i < 7; i++)
    for(int j = 0; j<7; j++)
        arr[i][j] = 10;

  for(int i = 1; i <= 5; i++)
    for(int j = 1; j<=5; j++)
      cin>>arr[i][j];

    for(int i = 1; i <=5; i++){
        for(int j = 1; j<=5; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(arr[i][j] < arr[ny][nx]) cnt++;
            }
            if(cnt == 4) cout<<"* ";
            else cout<< arr[i][j]<<" ";
        }cout<<endl;
    }
  
  return 0;
}