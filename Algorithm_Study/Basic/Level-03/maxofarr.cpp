#include <iostream>
using namespace std;

int main() {
  int mat[9][9];
  int max=0, row, column; 
  int n;
  for(int i = 0; i< 9; i++){
    for(int j = 0; j<9; j++){
      cin>>n;
      mat[i][j]=n;
      if(mat[i][j]>max){
        max = mat[i][j];
        row = i+1;
        column = j+1;
      }
    }
  }
  cout<<max<<endl;
  cout<<row<<" "<<column;
  return 0;
}