#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Q1. finding largest element in an array

    // brute force approach
    sort(arr, arr + n); //time complexity: O(nlogn)
    cout << arr[n - 1] << endl;
     
    //optimal approach
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << largest << endl; //time complexity: O(n)


    //Q2. finding second largest element in an array

    //brute force approach
    sort(arr, arr + n); //time complexity: O(nlogn+n) = O(nlogn)
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != arr[n - 1]) {
            cout << arr[i] << endl;
            break;
        }
    }

    //better approach
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    int second_largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    cout << second_largest << endl; //time complexity: O(n+n) = O(n)

    //optimal approach
    int largest = arr[0], second_largest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] < largest) {
            second_largest = arr[i];
        }
    }
    cout << second_largest << endl; //time complexity: O(n)

    return 0;
}