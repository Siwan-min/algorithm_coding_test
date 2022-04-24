#include <string.h>
#include <stdio.h>
#define MAX 105
char data[MAX];
int myStack[55];

int len, top;
int main(){
 scanf("%s", data);
 len = strlen(data);
 
 for(int i = 0 ; i <len; i++){
   if(data[i]=='('){
     myStack[top] = i;
     top++;
   }
   else {
     if(top==0){
       printf("NO");
       return 0;
     }
     myStack[top-1]=0;
     top--;
   }
 }
 if(top>0) printf("NO");
 else printf("YES");
  return 0;
}