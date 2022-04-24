#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



bool solution(vector <string> input){

    bool answer = true;
     char a[10000];
     char b[10000];
    for(int i = 0; i < input.size()-1; i++){
      for(int k = 0; k < input[0].size(); k++){
        a[k] = input[0][k]; 
      }
        for(int j = i+1; j < input.size(); j++){
            //string a= input[i];
            //string b = input[j];
            for(int k = 0; k < input[1][k]; k++){
              b[k] = input[1][k];
            }
            int sum = 0, flag = 0;
            for(int p = 0; p < strlen(b)-strlen(a); p++){
                sum = 0;
                for(int q = 0; q < strlen(a); q++){
                    if(b[p+q] != a[q]){
                        break;
                    }
                    else{
                        sum++;
                    }
                }
                if(sum == strlen(a)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}

int main(){

    vector <string> input;
    int n;
    n = 2;
    //cin>>n;
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string a = "";
    // for(int i = 0; i < n+1; i++){
    //     // char name[1003];
    //     // fgets(name, 1003, stdin);
    //     // input.push_back(name);
    //    getline(cin, a);
    //    input.push_back(a);
    // }

    a = "melon";
    input.push_back(a);
    a = "watermolon";
    input.push_back(a);

    

     for(int i = 0; i < 2; i++){

        cout<<input[i]<<endl;
    }
    bool answer = false;
    answer = solution(input);
    if(answer == false){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>



// int main() {
// char input[1003], q[1003];
// // scanf(" %[^\n]s", input);
 
// // scanf(" %[^\n]s", q);
   
//   fgets(input,1003,stdin);
//   fgets(q,1003,stdin);
// int sum = 0, flag = 0; 
// for(int i = 0 ; i < strlen(input)-strlen(q); i++){
//   sum = 0;
//   for(int j = 0 ; j < strlen(q); j++){
//     if(input[i+j] != q[j]){
//       break;
//     }
//     else{
//       sum++;
//     }
//   }
   
//   if(sum == strlen(q)){
//     flag = 1;
//     break;
//   }
// }
// //  printf("%d %d\n", strlen(q), sum);

//   if(flag == 1) printf("YES\n");
//   else printf("NO\n");
//   return 0;
// }
