#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){ //we will be running the loop until i is less than j because if i is greater than or equal to j then we have already partitioned the array
 
        while(i<= high -1 &&arr[i] <= pivot ) i++;
        while(j >= low+1 && arr[j] > pivot) j--;

        if(i < j) swap(arr[i], arr[j]); //if i is less than j then only swap otherwise we will be swapping the elements which are in correct position
    }
    swap(arr[low], arr[j]);//after the loop we will be swapping the pivot element with the element at j because j is the last element which is less than or equal to pivot and all the elements after j are greater than pivot
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){ //if their is a single element then only low = high
        int index = partition(arr, low, high);
        quickSort(arr, low, index-1);
        quickSort(arr, index+1, high);
    }
}


int main(){

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
     cin >> arr[i];

    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";

    return 0;
}
