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

    //Q3. To check if an array is sorted or not

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            cout << "not sorted array" << endl;
            break;
        }
    }
    cout << "sorted array" << endl;


    //Q4. To remove duplicates in-place from sorted array

    //brute force approach
    
    //by using set which will store only unique elements
    //time complexity: O(nlogn) for inserting elements in set + O(n) for copying elements back to array, overall time complexity: O(nlogn)
    //space complexity: O(n) for set

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    //now we have unique elements in set s, we will copy those elements back to array arr
    int index = 0;
    for (auto it : s)
    {
        arr[index++] = it;
    }
 
    //optimal approach
    //since the array is sorted, we can use two pointers to remove duplicates in-place
    //time complexity: O(n) as we traverse the array once and space complexity: O(1) as we are not using any extra space

    int index = 1; //index to store the position of next unique element as the first element is always unique

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1]) // if current element is not equal to previous element, then it is a unique element and we will store it at index position and increment index 
        {
             arr[index++] = arr[i];
        }
    }

    //another way of writing this same logic can be
    int i=0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i]) // if current element is not equal to the last unique element, then it is a unique element and we will store it next to the last unique element and increment i
        {
             arr[++i] = arr[j]; // we will increment i first and then store the unique element at index i
             // if we write arr[i++] = arr[j], then we will store the unique element at index i and then increment i, which will remove the unique element which is at i and replace it with the next unique element which is at j, so we will end up with 
        }
    }

     return 0;
}