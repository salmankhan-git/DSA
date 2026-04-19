#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> arr = {-1, 0, 1, 2, -1, -4};
int n = arr.size();

//Q. (3Sum) Find all unique triplets in the array which gives the sum of zero.
// arr[i] + arr[j] + arr[k] = 0
// i != j != k , mean the indices of the triplet must be different.
// Output: [[-1, -1, 2], [-1, 0, 1]]


//Brute Force Approach

set<vector<int>> s; // to store unique triplets
for(int i=0; i<n-2; i++){
    for(int j=i+1; j<n-1; j++){
        for(int k=j+1; k<n; k++){
            if(arr[i] + arr[j] + arr[k] == 0){
                vector<int> temp = {arr[i], arr[j], arr[k]};// to store the triplet
                sort(temp.begin(), temp.end());// sort the triplet to avoid duplicates
                s.insert(temp);
            }
        }
    }
}

// time complexity: O(n^3 * log(k)) where k is the number of unique triplets found logk for storing the triplet in the set
// space complexity: O(k) for storing the triplets in the set, where k is the number of unique triplets

// Better Approach
for(int i=0;i<n-1;i++){
    unordered_set<int> hashSet; // to store the elements of the array
    for(int j=i+1; j<n; j++){
        int target = -(arr[i] + arr[j]); // we need to find the target in the hashSet
        if(hashSet.find(target) != hashSet.end()){
            vector<int> temp = {arr[i], arr[j], target};
            sort(temp.begin(), temp.end());
            s.insert(temp);
        }
        hashSet.insert(arr[j]);
    }
}
// time complexity: O(n^2 * log(m)) where m is the number of element in the hashSet logm for finding/ inserting the element in the hashSet
// space complexity:O(m) + O(k) for storing the triplets in the set, where k is the number of unique triplets, m is the number of element in the hashSet

// Optimal Approach(Two Pointer Approach+ Sorting)

vector<int> arr1 = {-2, -2 , -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2}; // we are taking a sorted array to apply two pointer approach
int m = arr1.size();
vector<vector<int>> result; // to store the unique triplets we don't need to use set here because we are already avoiding duplicates in the array
for(int i=0; i<m-2; i++){
    if(i>0 && arr1[i] == arr1[i-1]) continue; // to avoid duplicates
    int left = i+1;
    int right = m-1;
    while(left < right){
        int sum = arr1[i] + arr1[left] + arr1[right];
        if(sum == 0){
            result.push_back({arr1[i], arr1[left], arr1[right]});
            left++;
            right--;
            while(left < right && arr1[left] == arr1[left-1]) left++; // to avoid duplicates
            while(left < right && arr1[right] == arr1[right+1]) right--; // to avoid duplicates
        }
        else if(sum < 0){
            left++;
            while(left < right && arr1[left] == arr1[left-1]) left++;
        }
        else{
            right--;
            while(left < right && arr1[right] == arr1[right+1]) right--;
        }
    }
}

//time complexity: O(nlogn) + O(n^2) for sorting the array and finding the triplets using two pointer approach
// space complexity: O(k) for storing the triplets in the result vector, where k is the number of unique triplets found it can be at most O(n^2) in the worst case when all the triplets are unique.

return 0;

}