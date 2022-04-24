#include <iostream>
using namespace std;

int main(){
  int i, temp;
  int arr[9],min[9];
  for(i=0; i<9; i++){
    cin>>arr[i];
    min[i]=arr[i];
  }
  for(int k=0; k<9; k++){
  for(i=0; i<9; i++){
    if(arr[k]<arr[i]){
      temp=arr[k];
      arr[k]=arr[i];
      arr[i]=temp;
    }
    
  }
  }
  for(int j=0; j<9; j++){
    if(arr[1]==min[j]){
      cout<<arr[1]<<"\n"<<j+1;
    }
  }
}
