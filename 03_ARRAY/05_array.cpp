#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){

    vector<int> arr = {2,4,5,8,9,7,3,1,6};
    int n = arr.size();

    // Q. Two sum problem : find the pair of elements in the array whose sum is equal to a given target sum
    int k = 14;
    //Brute force approach (linear search)
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == k){
                cout<<"Pair found: "<<arr[i]<<" "<<arr[j]<<endl;
                //or we can return the indices of the pair
                // cout<<"Pair found at indices: "<<i<<" "<<j<<endl;
            }
        }
    }
    // time complexity : O(n^2)
    // space complexity : O(1)

    //Better approach (using hashing)
    map<int, int> ans;
    for(int i=0; i<n; i++){
        int remaining_sum = k - arr[i];
        if(ans.find(remaining_sum) != ans.end()){
            cout<<"Pair found: "<<arr[i]<<" "<<remaining_sum<<endl;
            //or we can return the indices of the pair
            // cout<<"Pair found at indices: "<<i<<" "<<ans[remaining_sum]<<endl;
        }
        if(ans.find(remaining_sum) == ans.end()){
            ans[arr[i]] = i; // we will store the element and its index in the hash map
        }
    }
    // time complexity : O(nlogn)
    // space complexity : O(n)


    //Optimal approach (using sorting and two pointers)
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    while(left < right){
        int cur_sum = arr[left] + arr[right];
        if(cur_sum == k ){
            cout<<"Pair found: "<<arr[left]<<" "<<arr[right]<<endl;
        }
        else if(cur_sum < k){
            left++;
        }
        else{
            right--;
        }
    }
    // for index based we can not use it as we sorted the array which changes the original indices of the elements
    // if we want the index first we have to store the original index then do all the operations and then return the original indices of the pair which will take extra time and space due to which if we want index based solution than better is the optimal approach using hashing

    // time complexity : O(nlogn + n)
    // space complexity : O(1)
return 0;
}