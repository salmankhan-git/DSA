#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "abcabcb";
    int n = str.length();
    unordered_set<char> s;
    int length = 0;
    int left = 0;
    for(int i=0; i<n; i++){
        if(s.find(str[i]) == s.end()){
            s.insert(str[i]);
            
        }
        else{
            while(s.find(str[i]) != s.end()){
            s.erase(str[left]);
            left++;
            }
            s.insert(str[i]);
        }
        length = max(length,i-left+1);
    }
    cout<< length;
    return 0;

}