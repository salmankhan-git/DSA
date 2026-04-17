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
    return 0;
}