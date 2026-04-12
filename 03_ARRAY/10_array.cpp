#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {3,1,-2,-5,2,4};
    int n = arr.size();

    // Q1. Rearrange array elements by sign such that positive and negative numbers are placed alternatively.
    // ***there will always half positive and half negative numbers.
    
    
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
    int k=0, l=0;
    for(int i=0;i<n;i++){
        if (arr[i] >= 0){
            rearranged[2*k] = arr[i];
            k++;
        }
        else{
            rearranged[2*l + 1] = arr[i];
            l++;
        }
    }
    //time complexity: O(n)
    //space complexity: O(n)


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


    // Q2. Q1. Rearrange array elements by sign such that positive and negative numbers are placed alternatively.
    // ***there can be more positive or negative numbers than the other.
    
     vector<int> arr1 = {3,1,-2,-5,2,4,6,-7};
    int m = arr1.size();

    // in this case we can not use the better and optimal solution as we already knew it has equal number of positive and negative numbers 
    // we are just inserting the positive and negative number alternately

    // so we can only use the brute force approach to solve this problem.



    // Brute Force Approach(using two vector)
    vector<int> posi;
    vector<int> negi;
    int p=0, q=0;
    for(int i=0;i<m;i++){
        if (arr1[i] >= 0){
            posi.push_back(arr1[i]);
        }
        else{
            negi.push_back(arr1[i]);
        }
    }

    // now placing the number alternately in the original array 
    
    //if there are more positive number then negative number
    if(posi.size() > negi.size()){
        for(int i=0;i<negi.size();i++){
            arr1[2*i] = posi[i];
            arr1[2*i + 1] = neg[i];
        }
        // placing the remaining positive numbers at the end of the array
        int index = 2*negi.size(); // index to place the remaining positive numbers consecutively
        for(int i=negi.size();i<posi.size();i++){
            arr1[index++] = pos[i];
        }
    }
    else{ // if there are more negative number then positive number
        for(int i=0;i<posi.size();i++){
            arr1[2*i] = posi[i];
            arr1[2*i + 1] = negi[i];
        }
        // placing the remaining negative numbers at the end of the array
        int index = 2*posi.size(); // index to place the remaining negative numbers consecutively
        for(int i=posi.size();i<negi.size();i++){
            arr1[index++] = negi[i];
        }
    }

    // time complexity : O(n) + O(min(posi,negi)) + O(leftover) = O(n+n)
    //O (min(posi,negi)) + O(leftover) = O(n)
    //space complexity: O(posi) + O(negi) = O(n)
    
    return 0;
}