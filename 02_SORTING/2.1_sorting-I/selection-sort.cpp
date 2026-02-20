#include<bits/stdc++.h>
using namespace std;

// selection sort is based on minimum element selection. In each pass, the minimum element is selected and swapped with the first element of the unsorted array. The time complexity of selection sort is O(n^2) in all cases, as it always requires two nested loops to complete the sorting process.
void selection_sort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int min_index = i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min_index]) min_index = j;
        }
        // swap(arr[i],arr[min_index]);
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


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

int main(){

// array input
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];



//selection sort 
selection_sort(arr,n);

return 0;

}