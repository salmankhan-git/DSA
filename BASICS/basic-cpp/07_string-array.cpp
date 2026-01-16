#include<bits/stdc++.h>
using namespace std;
int main()
{
   //string and getline
   
   string str1 = "Hello";
   string str2 = "World";
    cout<< str1[0] + " " + str2[0]<< endl;

   // if we want to take input of string with spaces we use getline
   string s1; 
   string s2; 
   cin>> s1>> s2;
   cout<< s1<< " "<< s2<< endl; // by default cin takes input till space

   string str;
   getline(cin, str); // to take input with spaces
   cout<< str<< endl;
  
   // array
    int arr[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++)
    {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

 // 2d array
    int arr2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<< arr2d[i][j]<< " ";
        }
        cout<< endl;
    }
 
 
 
   return 0;
}