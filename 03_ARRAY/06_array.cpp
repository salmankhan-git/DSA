#include<bits/stdc++.h>
using namespace std;



void merge(int arr[], int low, int mid, int high, vector<int>& temp) {
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
void merge_sort(int arr[], int low, int high, vector<int>& temp) {
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

    // in this algo the main logic is we are having 
    // all zeroes (0, low-1)  left most part of the array
    // all ones (low, mid-1)
    // all unsorted (mid, high) **this is the part of the array which we are going to sort
    // all twos (high+1, n-1) right most part of the array

    // if arr[x]=0 then we will swap arr[x] with arr[low] and increment low and mid
    // if arr[x]=1 then we will just increment mid
    // if arr[x]=2 then we will swap arr[x] with arr[high] and decrement high

        int low = 0, mid = 0, high = n - 1;// we are taking low as 0 because it is the staring index and mid and high as 0 and n-1 because we are going to sort the whole array
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }

        //time complexity : O(n)
        //space complexity : O(1)
return 0;
}