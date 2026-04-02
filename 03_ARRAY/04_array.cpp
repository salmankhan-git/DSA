#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    // Q1. Find the largest subarray with sum K (with negative numbers it is the optimal solution)
    // subarray means contiguous elements of an array

    //Brute force approach(linear search) 
    // it is for positive numbers only

    int max_len = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == k){
                max_len = max(max_len, j-i+1);
                break;// we can remove this break for checking zeros after the sum which will increase the lenghth of the subarray with sum k
            } else if(sum > k){
                break;
            }
        }
    }
    cout<<"Largest subarray with sum K is: "<<max_len<<endl;
    //time complexity : O(n^2)
    //space complexity : O(1)


    //Better approach (using hashing)
    //with negative numbers it is the optimal solution

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
            max_len2 = max(max_len2, i - mp[remaining_sum]); // i-mp[remaining_sum] is the length of the subarray with sum k 
        }
        // ** if .find() is not found then it will return mp.end() which is an iterator pointing to the end of the map and if it is found then it will return an iterator pointing to the element in the map

        // if the prefix sum is same then we will not update the index in the hash map because we want to find the longest subarray
        if(mp.find(prefix_sum) == mp.end()){
            mp[prefix_sum] = i;
        }
        
    }
    cout<<"Largest subarray with sum K is: "<<max_len2<<endl;
 
    //time complexity : O(nlogn)
    //space complexity : O(n)

    //Optimal approach(using 2 pointer only if the array is having zero, positive numbers)

    int left = 0, right = 0;
    int max_len3 = 0; 
    long long sum = 0;

    while(right < n){
        while(left <= right && sum>k ){
            sum -= arr[left];
            left++;
        }// this loop is not running always as we are only moving the right pointer always and adding the elements to the sum and if the sum is greater than k then we will move the left pointer and subtract the elements from the sum until the sum is less than or equal to k due to which we are only assuming time complexity to be O(2n) not O(n^2) because we are not running the inner loop for every element of the array
        
        if(sum == k){
            max_len3 = max(max_len3, right - left + 1);
        }
        if(right < n){
            sum += arr[right];
        }
        right++;
    }

    // time complexity : O(2n)
    // space complexity : O(1)


    return 0;
}