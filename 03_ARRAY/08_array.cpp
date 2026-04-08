#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = arr.size();
    
    // Q. Maximum subarray sum 

    // Brute force approach (O(n^3) linear with 3 loop)
    
    int max_sum = INT_MIN;
    for(int i= 0; i<n ; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum += arr[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum << endl;
    // time complexity: O(n^3)
    // space complexity: O(1)

    // Better approach (O(n^2) linear with 2 loop)
    int max_sum1 = INT_MIN;
    for(int i= 0; i<n ; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            max_sum1 = max(max_sum1, sum);
        }
    }
    cout << max_sum1 << endl;
    // time complexity: O(n^2)
    // space complexity: O(1)

    // Optimal approach (kadane's algorithm)

    int max_sum2 = INT_MIN;
    int sum = 0;
    for(int i= 0; i<n ; i++){
        sum += arr[i];
        if(sum > max_sum2){
            max_sum2 = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    //if they want to give empty array when the max_sum2 is negative
    if(max_sum2 < 0){
        max_sum2 = 0;
    }
    cout << max_sum2 << endl;
    // time complexity: O(n)
    // space complexity: O(1)


    // if they want the maximum subarray sum index
    int max_sum3 = INT_MIN;
    int sum = 0;
    int ans_start = -1;
    int ans_end = -1;
    int start = 0;
    for(int i= 0; i<n ; i++){
        if(sum == 0) {
            start = i;
        }
        sum += arr[i];
        if(sum > max_sum2){
            max_sum2 = sum;
            ans_start = start;
            ans_end = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    if(max_sum2 < 0){
        max_sum2 = 0;
        ans_start = -1;
        ans_end = -1;
    }
    cout << "Maximum subarray sum is: " << max_sum2 << endl;
    cout << "Starting index is: " << ans_start << endl;
    cout << "Ending index is: " << ans_end << endl;

return 0;
}