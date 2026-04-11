#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {3,1,-2,-5,2,4};
    int n = arr.size();

    // Q. Rearrange array elements by sign such that positive and negative numbers are placed alternatively.
    // there will always half positive and half negative numbers.
    
    
    // Brute Force Approach(using extra space (two arrays))
    int pos[n/2];
    int neg[n/2];
    int p=0, q=0;
    for(int i=0;i<n;i++){
        if (arr[i] >= 0){
            pos[p++] = arr[i];
        }
        else{
            neg[q++] = arr[i];
        }
    }
    // now modify the original array by placing the positive and negative numbers alternatively.
    for(int i=0;i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    //time complexity: O(n + n/2)
    //space complexity: O(n/2 + n/2) = O(n)

    //Better Approach (using extra space)
    // we can use a single array to store the rearranged elements.
    vector<int> rearranged(n);
    int k=0;
    

    // Optimal Approach (two pointers)
    // we can use two pointers to rearrange the array in place without using extra space.

    int i=0, j=1; // i for positive numbers and j for negative numbers
    while(i<n && j<n){
        if (arr[i] >= 0){
            i += 2; // move to the next positive number
        }
        else if (arr[j] < 0){
            j += 2; // move to the next negative number
        }
        else{
            swap(arr[i], arr[j]); // swap the positive and negative numbers
            i += 2;
            j += 2;
        }
    }
    // time complexity: O(n)
    // space complexity: O(1)
    return 0;
}