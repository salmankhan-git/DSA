#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    // Q1. Find the largest subarray with sum K
    // subarray means contiguous elements of an array

    //Brute force approach(linear search)

    int max_len = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k){
                max_len = max(max_len, j-i+1);
                break;
            } else if(sum > k){
                break;
            }
        }
    }
    cout<<"Largest subarray with sum K is: "<<max_len<<endl;



    return 0;
}