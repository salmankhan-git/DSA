#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n = arr.size();

    //Q. Find the length of the longest consecutive sequence in the array.
    // longest consecutive sequence is 1, 2, 3, 4 or 100, 101, 102. So the answer is 4.

    //Brute Force approach(linear search)
    int longest = 1;
    for(int i=0; i<n; i++){
        int count = 1;
        int num = arr[i];
        while(find(arr.begin(), arr.end(), num+1) != arr.end()){
            count++;
            num++;
        }
        longest = max(longest, count);
    }
    cout << longest << endl;

    //**  while loop complexity : O(n) (iterations in worst case as arr = [1, 2, 3, 4, ..., n]) × O(n) (find)=O(n^2)
    //**  combined with outer loop → overall still O(n²) (not O(n³), because not every i hits worst case fully)
    // time complexity : O(n^2)
    // space complexity : O(1)

    //Better approach (using sorting)
    // sort(arr.begin(), arr.end());
    longest = 1;
    int current = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]+1){
            current++;
        }
        else{// if it's not consecutive, update longest and reset current
            longest = max(longest, current);
            current = 1;
        }
    }
    longest = max(longest, current); // to handle the case when the longest sequence ends at the last element
    cout << longest << endl;
    // time complexity : O(nlogn) (sorting) + O(n) (traversal) 
    // space complexity : O(1)

    //Optimal approach (using hash set)
    unordered_set<int> s(arr.begin(), arr.end());
    longest = 1;
    for(int num : s){
        if(s.find(num-1) == s.end()){ // if num-1 is not in the set, then num is the start of a sequence
            int current = 1;
            while(s.find(num+current) != s.end()){
                current++;
            }
            longest = max(longest, current);
        }
    }
    cout << longest << endl;
    // time complexity : O(n) (building the set) + O(n) (traversal) + O(k) (while loop, where k is the length of the longest sequence) → O(n+ 2n)
    // space complexity : O(n) (for the hash set)

    return 0;
}