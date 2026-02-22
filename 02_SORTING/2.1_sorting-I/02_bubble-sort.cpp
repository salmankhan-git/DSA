#include<bits/stdc++.h>
using namespace std;

// bubble sort is based on maximum element adjacent swapping. In each pass, the maximum element is bubbled to the end of the array. The time complexity of bubble sort is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.

void bubble_sort(int arr[], int n){
    for(int i=n-1;i>=1;i--){
        int swapped = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                // swap(arr[j],arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped ++;
            }
        }
        if(swapped == 0) break; // if no swapping is done, then the array is already sorted which is the best case for bubble sort and the time complexity becomes O(n).
            }
        }


// most optimized bubble sort is based on last swapping index. In each pass, the last swapping index is recorded and in the next pass, the inner loop runs only up to that index as all elements after that index are already sorted. The time complexity of most optimized bubble sort is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.

void bubble_sort(int arr[], int n){
 
    int last;

    while(n > 1){
        last = 0; // initialize last to 0 at the beginning of each pass to handle the case when the array is already sorted and no swapping is done which will close the loop in the next iteration.

        for(int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                last = j + 1;
            }
        }
        n = last; // update n to last which is the index of the last swapping, so in the next pass, the inner loop will run only up to that index as all elements after that index are already sorted.

    }
}

int main(){

// array input
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];



//bubble sort
bubble_sort(arr,n);

// print sorted array
for(int i=0;i<n;i++) cout<<arr[i]<<" ";

return 0;

}