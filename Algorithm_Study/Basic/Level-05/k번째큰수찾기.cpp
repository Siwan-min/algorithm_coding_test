#include <iostream>
#include <algorithm>
using namespace std;
int main() {

  int arr[100005];
  int n, k;
  
  cin>>n>>k;
  
  for(int i = 0; i<n; i++) cin>>arr[i];
  
  sort(arr, arr+n, greater<int>()); //내림차순 정렬
    cout<<arr[k-1];
  
  return 0;
}
/*
sort(v.begin(), v.end(), greater<자료형>()) //내림차순 
sort(v.begin(), v.end(), less<자료형>()) //오름차순 
*/