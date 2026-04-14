#include<bits/stdc++.h>
using namespace std;
int main(){

    int arr[] = {3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Q. find next lexicographically greater permutation (if not possible then print the smallest permutation)

    // Brute force (Using recursion)

    //generate all permutations in sorted order, do the linera search to find the given permutation and print the next one index
    // Time complexity: O(n! * n) (n! for generating all permutations and n for linear search)
    // space complexity: O(n! * n)


    // Better approach (Using STL)
    vector<int> v(arr, arr + n);
    next_permutation(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    //time complexity: O(n) (for next_permutation)
    //space complexity: O(n) (for vector)
    return 0;
}