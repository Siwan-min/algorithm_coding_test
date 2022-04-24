#include <iostream>
#include <cstring>
 
using namespace std;
 
// Function to reverse string and return reversed string 
string reversingString(string str, int start, int end){
 
    //Iterate loop upto start not equal to end
    while(start < end)
    {
        // XOR for swapping the variable
        str[start] ^= str[end];
        str[end] ^= str[start];
        str[start] ^= str[end];
 
        ++start;
        --end;
    }
    return str;
}
 
 
int main(){
 
    char s[1005] ="";
 
    scanf(" %[^\n]s",s); // the way to get a string including space without getline() 
 
    int len = strlen(s);
 
    if(len > 1005 ) {
        cout<<"error"<<endl;
        }
    else cout<<reversingString(s, 0, len-1);
 
    return 0;
}