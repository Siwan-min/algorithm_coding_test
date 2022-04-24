#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int arr[10][10];

  for(int i = 0 ; i < 5; i++){
    for(int j = 0; j< 5; j++){
      cin>>arr[i][j];
    }
  }
 
  for(int i = 0; i < 5; i++){
     int b[2] = {0, };
        for(int j = 0; j < 5; j++){
          int _max1 = -1, _max2 = -2;
            if(arr[i][j] > b[0] ) {
              _max2 = b[0];
              b[0] = arr[i][j];
              }
             if(_max2 > b[1]) b[1] = _max2;
            
        }
       
      cout<<b[0]<<" "<<b[1]<<endl;
     // memset(b, 0, sizeof(b));
    }
  return 0;
}