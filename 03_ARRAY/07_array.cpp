#include <bits/stdc++.h>
using namespace std;
int main (){
   // Q. Majority Element (element > n/2 times in the array)

   int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
   int n = sizeof(arr)/sizeof(arr[0]);

   // Brute force approach(linear search)
   for(int i=0; i<n; i++){
      int count = 0;
      for(int j=0; j<n; j++){
         if(arr[i] == arr[j]){
            count++;
         }
      }
      if(count > n/2){
         cout << "Majority element is: " << arr[i] << endl;
         break;
      }
   }

   // time complexity: O(n^2)
   // space complexity: O(1)

   // Better approach (using hashmap)
   map<int, int> freq;
   for(int i = 0; i<n; i++){
      freq[arr[i]]++;
   }
   for(auto it : freq){
      if(it.second > n/2){
         cout << "Majority element is: " << it.first << endl;
         break;
      }
   }
   // time complexity: O(nlogn + n)
   // space complexity: O(n)
   return 0; 
}