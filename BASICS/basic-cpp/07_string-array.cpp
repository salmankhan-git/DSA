#include<bits/stdc++.h>
using namespace std;
int main()
{
   //string and getline
   // if we want to take input of string with spaces we use getline
   string s1; 
   string s2; 
   cin>> s1>> s2;
   cout<< s1<< " "<< s2<< endl; // by default cin takes input till space

   string str;
   getline(cin, str); // to take input with spaces
   cout<< str<< endl;
    return 0;
}