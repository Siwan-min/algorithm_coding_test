#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char s[1005];
  fgets(s, 1005,stdin);
  
 int slen = strlen(s);
  for(int i = 0; i<slen; i++ ){
    if(s[i] >= 'A' && s[i] <= 'Z'){
      s[i]+=32;
    }
    else if(s[i]>='a' && s[i]<='z'){
      s[i]-=32;
    }
    else s[i] = s[i];
    cout<<s[i];
  }

  return 0;
}