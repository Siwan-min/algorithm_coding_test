/*
1. x가 3으로 나누어 떨어지면, 3으로 나눈다
2. x가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.
*/

#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;

int n; 
int arr[MAX];

int main(){

    cin>>n;
    arr[1] = 0; 

    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + 1;
        if(i%2 == 0){
           arr[i] = min(arr[i/2] + 1, arr[i]); 
        } 
        if(i%3 == 0){
           arr[i] = min(arr[i/3] + 1, arr[i]);
        } 
        
    }
    cout<<arr[n]<<endl;
    return 0;
}