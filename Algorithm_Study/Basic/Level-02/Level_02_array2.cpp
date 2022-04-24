#include<iostream>
using namespace std;
int main()
{
  int r,c;
  cin>>r>>c;
  int **mat;
  mat = new int*[r];
  for(int i = 0; i < r; i++)
  mat[i] = new int[c];
  
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      cin>>mat[i][j];
    }
  }
  int k, l;
  cin>>k>>l;
  cout<<mat[k][l];

  for(int i = 0; i<r; i++)
    delete[] mat[i];
  delete mat;
  
}
