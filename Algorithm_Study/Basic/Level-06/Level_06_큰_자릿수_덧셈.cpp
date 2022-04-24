
#include <bits/stdc++.h> 
using namespace std; 
  

void makeEqualAtFront(vector<int>& A, vector<int>& B) 
{ 
    int n = A.size(); 
    int m = B.size(); 
    int diff = abs(n - m); 
  
    if (n < m) { 
        for (int i = 0; i < diff; i++) { 
            A.insert(A.begin(), 0); 
        } 
    } 
    else { 
        for (int i = 0; i < diff; i++) { 
            B.insert(B.begin(), 0); 
        } 
    } 
} 
  
void makeEqualAtback(vector<int>& A, 
                     vector<int>& B) 
{ 
    int n = A.size(); 
    int m = B.size(); 
    int diff = abs(n - m); 
  
    if (n < m) { 
        for (int i = 0; i < diff; i++) { 
            A.push_back(0); 
        } 
    } 
    else { 
        for (int i = 0; i < diff; i++) { 
            B.push_back(0); 
        } 
    } 
} 

void findSum(string s1, string s2) 
{ 
  
    int i; 
  
   
    vector<int> Ints1, Ints2; 
    vector<int> Fracs1, Fracs2; 
 
    for (i = s1.length() - 1; i > -1; i--) { 
  
     
        if (s1[i] == '.') { 
            break; 
        } 
        Fracs1.push_back(s1[i] - '0'); 
    } 
  
    i--; 
    for (; i > -1; i--) { 
        Ints1.push_back(s1[i] - '0'); 
    } 
  

    for (i = s2.length() - 1; i > -1; i--) { 
  
    
        if (s2[i] == '.') { 
            break; 
        } 
        Fracs2.push_back(s2[i] - '0'); 
    } 
  
    i--; 
    for (; i > -1; i--) { 
        Ints2.push_back(s2[i] - '0'); 
    } 
  
    makeEqualAtFront(Fracs1, Fracs2); 
    makeEqualAtback(Ints1, Ints2); 
 
    int n = Fracs1.size(); 
    int m = Fracs2.size(); 
    i = 0; 
    int carry = 0; 
  
    while (i < n && i < m) { 
  
        int sum = Fracs1[i] 
                  + Fracs2[i] 
                  + carry; 
  
        Fracs1[i] = sum % 10; 
        carry = sum / 10; 
        i++; 
    } 
  
    int N = Ints1.size(); 
    int M = Ints2.size(); 
    i = 0; 

    while (i < N && i < M) { 
        int sum = Ints1[i] 
                  + Ints2[i] 
                  + carry; 
        Ints1[i] = sum % 10; 
        carry = sum / 10; 
        i++; 
    } 
    if (carry != 0) 
        Ints1.push_back(carry); 

    for (int i = Ints1.size() - 1; i > -1; i--) { 
        cout << Ints1[i]; 
    } 
    
	bool flag = false;
	for (int i = Fracs1.size() - 1; i > -1; i--) { 
        if(Fracs1[i] != 0 ) flag = true; 
    } 
	
	if(flag == true){
		cout << '.'; 
		for (int i = Fracs1.size() - 1; i > -1; i--) { 
			cout << Fracs1[i]; 
		} 
	}
} 

int main() 
{ 
    string str1; 
    string str2; 

	cin>>str1>>str2;
	
	int a = str1.size();
	int b = str2.size();
	bool flag1 = false;
	for(int i = 0; i < a; i++){
		if(str1[i] == '.') flag1 = true; 
	}
	if(flag1 == false) str1+=".0";

	bool flag2 = false;
	for(int i = 0; i < b; i++){
		if(str2[i] == '.') flag2 = true; 
	}
	if(flag2 == false) str2+=".0";


    findSum(str1, str2); 
  
    return 0; 
} 