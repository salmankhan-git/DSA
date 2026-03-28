#include <bits/stdc++.h>
#include <vector>
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

    
    // Q2. Find the maximum consecutive ones in the array

    int arr1[]={1,1,0,1,1,1,0,1,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int count = 0;
    int max_count=0;
    
    for(int i = 0; i<n; i++) {
        if(arr1[i]==1){
            count++;
            // to handle the case when the array ends with 1s we 
            // put the contition to update the max_count in each iteration when we encounter a 1
            max_count = max(max_count, count);

        }
        else{
            count=0;
        }
    }
    cout << "Maximum consecutive ones are: " << max_count << endl;


    // Q3. Find the number that apperars once and the others appear twice in the array

    int arr2[]={2,3,5,4,5,3,4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    //brute force approach(using linear search)
    for (int i = 0; i < n2; i++)
    {
        int counte =0;
        for (int j = 0; j < n2; j++){
            if(arr2[i]==arr2[j]){
                counte++;
            }
        }
        if(counte==1){
            cout << "The number that appears once is: " << arr2[i] << endl;
            break;
        }

        //time complexity: O(n^2)
        //space complexity: O(1)

        //better approach(using hashing)
        
        //for knowing the size of the hasher we have to find the maximum element in the array as the size of the hasher should be greater than the maximum element in the array
        int max_num = *max_element(arr2, arr2+n2);
        vector<int>hasher(max_num+1, 0);
        for(int i=0; i<n2; i++){
            hasher[arr2[i]]++;
        }
        for(int i=0; i<n2; i++){  // we can also loop the hash array as the size of the hasher is greater than the size of the array but we will choose array as it is smaller than the hasher array soo it will reduce time complexity a bit.
            if(hasher[arr2[i]]==1){
                cout << "The number that appears once is :"<<arr2[i] << endl;
                break;
            }
        }

    return 0;
}