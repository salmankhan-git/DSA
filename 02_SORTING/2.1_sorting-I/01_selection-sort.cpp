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

int main(){

// array input
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];



//selection sort 
selection_sort(arr,n);


// print sorted array
for(int i=0;i<n;i++) cout<<arr[i]<<" ";

return 0;

}