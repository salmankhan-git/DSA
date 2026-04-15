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


    // Optimal approach
    // 1. Traverse from the end and find the first pair of adjacent elements such that arr[i] < arr[i + 1]. Let us call this index i. If no such index exists, then this is the last permutation and just return the reverse of the array.
    // 2. Traverse from the end again and find the first index j such that arr[i] < arr[j]. Since we are traversing from the end, we are guaranteed to find such an index.
    // 3. Swap arr[i] and arr[j].
    // 4. Reverse the subarray arr[i + 1...n - 1] .

    //step 1 find the first pair of adjacent elements such that arr[i] < arr[i + 1]
    int i = -1;
    for (int k = n - 2; k >= 0; k--){
        if (arr[k] < arr[k + 1]){
            i = k;
            break;
        }
    }
    // If no such index is found, this is the last permutation
    if (i == -1) {
        reverse(arr, arr + n);
    }
    
    
    else {
        // Step 2: Find the largest index j such that arr[i] < arr[j]
        int j ;
        for (int k = n - 1; k > i; k--) {
            if (arr[i] < arr[k]) {
                j = k;
                break;
            }
        }

        // Step 3: Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);

        // Step 4: Reverse the subarray from i + 1 to n - 1
        reverse(arr + i + 1, arr + n);
    }

    // Print the next permutation
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }

    //time complexity: O(n for finding i) + O(n for finding j) + O(1 for swapping) + O(n for reversing) = O(3n)
    //space complexity: O(1)
    return 0;
}