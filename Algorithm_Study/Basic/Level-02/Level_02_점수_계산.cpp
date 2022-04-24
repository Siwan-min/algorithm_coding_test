#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[n], score[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  score[0]=arr[0];
  int total=0;
    for(int j=0; j<n; j++){
      if(arr[j]==arr[j+1]){
        score[j+1]=arr[j+1]+score[j];
      }
      else{
        score[j+1]=arr[j+1];
      }
      total = total + score[j];
    } cout<<total;
  return 0;
}
