#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //Q1. Left rotate an array by 1 positions

        int temp = arr[0];
        for (int i=1; i<n ;i++)
        {
            arr[i-1] = arr[i];
        }
        //or
        // for (int i=0; i<n-1 ;i++){
        //     arr[i] = arr[i+1];
        // }
        arr[n-1] = temp;
        // time complexity = O(n)
        // space complexity = O(1)
    
    
    // Q2. Left rotate an array by D positions

    // brute force approach (using temporary array )
        int d;
        cin>>d;

        //reducing d if it is greater than n
        d = d%n;
       
        // store the first d elements in a temporary array 
        int temp[d];
        for (int i=0; i<d; i++){
            temp[i] = arr[i];
        }

        // shift the remaining n-d elements to the left by d positions
        for (int i=d; i<n; i++){
            arr[i-d] = arr[i];
        }

        // copy the d elements from the temporary array to the end of the original array
        for (int i=0; i<d; i++){
            arr[n-d+i] = temp[i];
        }
        // time complexity = O(d) + O(n-d) + O(d) = O(n+d) = O(n)
        // space complexity = O(d)


    return 0;

}