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
    //time complexity : O(n^2)
    //space complexity : O(1)

    //Better approach (using hashing)
    // we will use prefix sum and hash map to store the prefix sum and its index
    // prefix sum : sum of elements from index 0 to i 

    // prefix sum = x
    // x = (x-k) + k
    // then we can find the subarray with sum k by checking if (x - k) exists in the hash map
    // if it exists then we can find the length of the subarray by taking the difference of the current index and the index of (x-k) in the hash map
    
    map<long long, int> mp; // to store prefix sum and its index
    long long prefix_sum = 0;
    int max_len2 = 0;
    for(int i=0; i<n; i++){
        prefix_sum += arr[i];
        if(prefix_sum == k){
            max_len2 = max(max_len2, i+1);
        }
        // check if (prefix_sum - k) = remaining_sum exists in the hash map 
        long long  remaining_sum = prefix_sum - k;
        if(mp.find(remaining_sum) != mp.end()){
            max_len2 = max(max_len2, i - mp[remaining_sum]);
        }
        // if the prefix sum is same then we will not update the index in the hash map because we want to find the longest subarray
        if(mp.find(prefix_sum) == mp.end()){
            mp[prefix_sum] = i;
        }
        
    }
    
    return 0;
}