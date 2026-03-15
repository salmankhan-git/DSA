#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //Q1. Left rotate an array by d positions
    // resultant array after left rotation by d positions
    // 1. d = 2, arr[] = {1, 2, 3, 4, 5} => {3, 4, 5, 1, 2}
    // 2. d = 3, arr[] = {1, 2, 3, 4, 5} => {4, 5, 1, 2, 3}
    // 3. d = 4, arr[] = {1, 2, 3, 4, 5} => {5, 1, 2, 3, 4}

    return 0;
}