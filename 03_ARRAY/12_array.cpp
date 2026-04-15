#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {10, 22, 12, 3, 0, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    //Q. find the leader in the array (an element is called leader if there is no element greater than it on the right side)

    // Brute force (linear search)
    for(int i = 0; i < n; i++){
        bool flag = false;
        for (int j = i + 1; j < n; j++){
            if (arr[i] < arr[j]){
                flag = true;
                break;
            }
        }
        if (!flag){
            cout << arr[i] << " ";
        }
    }
    // time complexity: O(n^2)
    // space complexity: O(1)

    // Optimal approach (traverse from the end and keep track of the maximum element seen so far)
    int maxer = INT_MIN;
    vector<int> leaders;
    for(int i = n-1; i>=0; i--){
        if (arr[i] > maxer){
            leaders.push_back(arr[i]);
            maxer = arr[i];
        }
    }
    //print the leader in correct order
    for (int i = leaders.size() - 1; i >= 0; i--){
        cout << leaders[i] << " ";
    }
    // time complexity: O(n)
    // space complexity: O(n) (for vector)
    return 0;
}