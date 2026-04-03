#include<bits/stdc++.h>
using namespace std;



void merge(vector<int>& arr, int low, int mid, int high, vector<int>& temp) {
    int left = low, right = mid + 1; 
    int index = low; 
    while (left <= mid && right <= high) { 
        if (arr[left] <= arr[right]) { 
            temp[index++] = arr[left++]; 
        } else { 
            temp[index++] = arr[right++]; 
        }
    }
    while (left <= mid) { 
        temp[index++] = arr[left++];

    while (right <= high) { 
        temp[index++] = arr[right++];
    }
    for (int k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
  }
}
void merge_sort(vector<int>& arr, int low, int high, vector<int>& temp) {
    if (low >= high) return; 
    int mid = low + (high - low) / 2; 
    merge_sort(arr, low, mid, temp);
    merge_sort(arr, mid + 1, high, temp);
    merge(arr, low, mid, high, temp);
}


int main(){
    int arr[]= {0,1,2,0,1,2,1,2,0,0,0,1};
    int n= sizeof(arr)/sizeof(arr[0]);

    // Question: Sort an array of 0s, 1s and 2s 

    // Brute Force Approach: Sort the array using any sorting algorithm
    // using merge sort
    vector<int> temp(n);
    merge_sort (arr,0,n-1,temp);

    // time complexity : O(nlogn)
    // space complexity : O(n) 

    //better approach: Count the number of 0s, 1s and 2s in the array and then fill the array with the counted number of 0s, 1s and 2s
   
    int ct0 = 0, ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) ct0++;
        else if (arr[i] == 1) ct1++;
        else ct2++;
    }
    for(int i = 0; i < ct0; i++) arr[i] = 0;
    for(int i = ct0; i < ct0 + ct1; i++) arr[i] = 1;
    for(int i = ct0 + ct1; i < n; i++) arr[i] = 2;
    // time complexity : O(2n)
    // space complexity : O(1)

    // optimal approach: Dutch National Flag Algorithm


return 0;
}