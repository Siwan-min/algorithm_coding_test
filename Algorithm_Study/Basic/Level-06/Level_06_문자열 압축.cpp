#include <iostream>
#include <cstring>

using namespace std;

int main(){
  
  char arr[1005];
  cin>>arr;
  int arrLen = strlen(arr);
  int sum = 1;
  
  for(int i = 0; i < arrLen; i++){
    if(arr[i] == arr[i+1]){
      sum++;
    }
    else{
      if(sum==1){
        cout<<arr[i];
      }
      else{
        cout<<sum<<arr[i];
      }
      sum = 1;
    }
  }
  
  return 0;
}