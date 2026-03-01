#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(i<= high -1 &&arr[i] <= pivot ) i++;
        while(j >= low+1 && arr[j] > pivot) j--;

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){ //if their is a single element then only low = high
        int ption = partition(arr, low, high);
        quickSort(arr, low, ption-1);
        quickSort(arr, ption+1, high);
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
