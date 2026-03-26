#include<bits/stdc++.h>
using namespace std;




int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Q1. Find the missing number in the array 
    // we have give an array of size n having numbers from 1 to n and one number is missing find that number


    //brute force approach(using linear search)
    for(int i = 1; i <= n; i++) {
        bool found = false;
        for(int j = 0; j < n-1; j++) {
            if(arr[j] == i) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "Missing number is: " << i << endl;
            break; 
        }
    }
    //time complexity: O(n^2)
    //space complexity: O(1)

    //better approach(using hashing)
    
    vector<int> hashe(n+1);
    for(int i = 0; i < n-1; i++) {
        hashe[arr[i]]++;
        //or hashe[arr[i]] += 1;
        //or ++hashe[arr[i]];
    }
    //now we have to find the missing number
    for(int i = 1; i <= n; i++) {
        if(hashe[i] == 0) {
            cout << "Missing number is: " << i << endl;
            break;
        }
    }
    //time complexity: O(2n)
    //space complexity: O(n)

    //optimal approach 1 (using mathematical formula)

    int sum = (n*(n+1))/2; //sum of first n natural numbers
    int arr_sum = 0;
    for(int i = 0; i < n-1; i++) {
        arr_sum += arr[i];
    }
    cout << "Missing number is: " << sum - arr_sum << endl;

    //time complexity: O(n)
    //space complexity: O(1)
    //** this approach may cause integer overflow if n is large

    //optimal approach 2 (using XOR operator)
  
    int xor_sum = 0;
    // instead of calculating the xor of first n natural numbers seprately we can 
    // calculate the xor of first n natural numbers and the xor of all elements in the array in one loop
    
    //now we have to find the missing number
    for(int i = 0; i < n-1; i++) {
        xor_sum ^= arr[i]^(i+1); //xor of first n-1 natural numbers and xor of all elements in the array
    }
    xor_sum ^= n; // it completes the xor of first n natural numbers as the loop is going till n-1 only
    cout << "Missing number is: " << xor_sum << endl;

    //time complexity: O(n)
    //space complexity: O(1)

    //this approach does not cause integer overflow as we are using XOR operator which is a bitwise operator and it does not depend on the size of the numbers.
    // so it is a better approach than the mathematical formula approach.

    
    return 0;
}