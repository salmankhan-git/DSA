#include<bits/stdc++.h>
using namespace std;

// insertion sort is based on inserting each element at its correct position in the sorted array. In each pass, an element is selected and inserted at its correct position in the sorted portion of the array. The time complexity of insertion sort is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.
void insertion_sort(int arr[], int n){
    for(int i=1;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){  // if the current element is smaller than the previous element, then swap them and move the current element one position to the left until it is in its correct position in the sorted portion of the array.
         int temp = arr[j-1];
         arr[j-1] = arr[j];
         arr[j] = temp;
         j--;
        }
        // in sorted array this while loop will not run  because the condition arr[j-1]>arr[j] will be false and the time complexity will be O(n) in the best case .

    }
}

// optimized insertion sort (shifting version) as shifting is more efficient than swapping. In this version, instead of swapping the elements, we store the current element in a temporary variable and shift the elements to the right until we find the correct position for the current element in the sorted portion of the array. 

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i]; // store the current element in a temporary variable
        int j = i - 1; // initialize j before the current element

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]; // shift the elements to the right
            j--;
        }

        arr[j + 1] = key; // the last element which is shifted in the while loop will be the correct position for the current element in the sorted portion of the array, so we assign the key to that position.
        // eg : [2,2 ,3,4,5] and key = 1, in the while loop, 5 will be shifted to the right, then 4 will be shifted to the right, then 3 will be shifted to the right, then 2 will be shifted to the right and finally the key will be assigned to the position of the last shifted element which is the correct position for the key in the sorted portion of the array.
        // ** we are using j+1 = key because after the while loop, j will be decremented one extra time and it will be at the just previous position where the last shift occurred(j=0 after decrement it will be j= -1 therefore we use arr[j+1] ), so we need to assign the key to j+1 which is the correct position for the key in the sorted portion of the array.
    }
}

int main(){

// array input
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];



//insertion sort 
insertion_sort(arr,n);


// print sorted array
for(int i=0;i<n;i++) cout<<arr[i]<<" ";

return 0;

}