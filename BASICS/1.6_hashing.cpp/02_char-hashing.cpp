#include<bits/stdc++.h>
using namespace std;
int main(){

    // in character hashing we can count the frequency of characters in a string using a hash array by the help of the ASCII values of the characters.
    string s;
    cin>>s;
    // if we have small letters only then we can use a simple array of size 26 to store the frequency of each character
    // *****if we have not give any range than we will use hash of 256 size to store the frequency of each character
    int charac[26]={0};
    //**int charac[256]={0} /

    for(int i=0;i<s.size();i++){
        charac[s[i]-'a']++; // incrementing the count of the character in the hash array
        //or
        // charac[s[i]-'a']+=1;

        //*** for 256 we use charac [s[i]]++;
    }

    // taking the input of characters for which we want to find the frequency
    int q;
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        cout<<"The frequency of "<<x<<" is: "<<charac[x-'a']<<endl; // output the frequency of the character
        //*** for 256 we use charac[x]
    }
}