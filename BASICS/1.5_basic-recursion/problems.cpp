#include <bits/stdc++.h>
using namespace std;


// reversing a array using recursion 
int rev(int l, int r){
    if (l >= r)
        return ;
    swap( arr[l], arr[r]);
    rev(l + 1, r - 1);
}

// reversing a string using recursion only with one variable
int reve(int i){
    if (i >= n/ 2)
        return ;
    swap( arr[i], arr[n - i - 1]);
    reve(i + 1);
}



int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    rev(0, n-1);
    reve(0);
    return 0;
}






















