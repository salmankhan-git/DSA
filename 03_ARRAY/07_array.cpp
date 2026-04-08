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

   // Optimal approach (Boyer-Moore Voting Algorithm)
   // Moore's Voting Algorithm finds the majority element by canceling out different elements using a counter. 
   // It keeps a candidate and adjusts the count as it scans the array—if a majority element exists, it will remain as the final candidate.

   int count = 0;
   int candidate;
   // First pass to find the candidate 
   for(int i=0; i<n; i++){
      if(count == 0){
         candidate = arr[i];
         count++;
      } else if(arr[i] == candidate){
         count++;
      } else {
         count--;
      }
   }
   // if we have given the array contains a majority element then the candidate will be the majority element but if there is no majority element then the candidate will be some random element so we need to verify it by counting its frequency in the array.
   // Second pass to verify the candidate
   int count1 = 0;
   for(int i =0; i<n ; i++){
      if(arr[i] == candidate){
         count1++;
      }
   }
   if(count1 > n/2){
      cout << "Majority element is: " << candidate << endl;
   } else {
      cout << "No majority element found." << endl;
   }

   //time complexity O(n+n)
   //space complexity O(1)
   return 0; 
}