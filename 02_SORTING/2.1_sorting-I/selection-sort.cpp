#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0;i<n-2;i++){
        int min_index = i;
        for(int j=i;j<n-1;j++){
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

return 0;

}