#include <bits/stdc++.h>
using namespace std;


// reversing a array using recursion 
int rev(int arr[], int l, int r){
    if (l >= r)
        return ;
    swap( arr[l], arr[r]);
    rev(arr, l + 1, r - 1);
}

// reversing a string using recursion only with one variable
int reve(int i, int n, int arr[]){
    if (i >=  n / 2)
        return ;
    swap( arr[i], arr[n - i - 1]);
    reve(i + 1, n, arr);
}
 //checking palindrome using recursion
bool isPalindrome(string s, int i, int sn) {
        if (i >= sn / 2)
            return true;
        if (s[i] != s[sn - i - 1])
            return false;
        return isPalindrome(s, i + 1, sn);
}


int main() {

    int arr[] = {1, 2, 3, 4, 5};
    string s = "madam";
    int n = std::size(arr);// or int n = sizeof(arr) / sizeof(arr[0]);
    int sn = s.length();
    rev(arr, 0, n-1);
    reve(0, n, arr);
    isPalindrome(s, 0, sn);
    return 0;
}






















