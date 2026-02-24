#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high, vector<int>& temp) {
    
    // vector<int> temp; // create a temporary vector to store the merged array
    // we are not craeting this inside the merge function because we will be calling the merge function multiple times and we don't want to create a new temp vector every time we call the merge function, so we will create the temp vector in the main function and pass it as a reference to the merge function.
    
    int left = low, right = mid + 1; // initialize two pointers to the beginning of the left and right halves of the array
    int index = low; // initialize a pointer to the beginning of the temporary vector

    while (left <= mid && right <= high) { // while there are elements in both halves of the array
        if (arr[left] <= arr[right]) { // if the current element in the left half is smaller than or equal to  the current element in the right half and it is stable as we are using <= operator, if we use < operator then it will not be stable as it will change the order of the elements in the left half if there are duplicate elements in the left half.
           
            temp[index++] = arr[left++]; // add the current element in the left half to the temporary vector and move the pointer in the left half to the next element and move the pointer in the temporary vector to the next element
            
        } else { // if the current element in the right half is smaller than the current element in the left half
           
            temp[index++] = arr[right++]; // add the current element in the right half to the temporary vector
        }
    }

    while (left <= mid) { // if there are remaining elements in the left half of the array
        
        temp[index++] = arr[left++]; // add them to the temporary vector and move both pointers to the next element
        //temp[index++] means temp[index] = arr[left]; // add the current element in the left half to the temporary vector
        //index++; // move the pointer in the temporary vector to the next element
    }

    while (right <= high) { // if there are remaining elements in the right half of the array
     
        temp[index++] = arr[right++]; // add them to the temporary vector
    }

    for (int k = low; k <= high; k++) { // copy the sorted elements from the temporary vector back to the original array
        arr[k] = temp[k]; //
    }
}
    
void merge_sort(vector<int>& arr, int low, int high, vector<int>& temp) {
    if (low >= high) return; // base case: if the array has one or zero elements, it is already sorted

    int mid = low + (high - low) / 2; // find the middle index of the array

    merge_sort(arr, low, mid, temp);// recursively sort the left half of the array
    merge_sort(arr, mid + 1, high, temp);// recursively sort the right half of the array
    merge(arr, low, mid, high, temp);// merge the two sorted halves of the array
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)   
     cin >> arr[i];


     // for optimization we can declare the temp vector inside the main function and pass it as a reference to the merge function, so that we don't have to create a new temp vector every time we call the merge function.
     vector<int> temp(n);
     merge_sort(arr,0,n-1,temp);
    
    // print sorted array
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}