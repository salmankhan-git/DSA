#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr [] = {7,1,5,3,6,4};
    int n =sizeof(arr)/sizeof(arr[0]);

    // Q. Best time to buy and sell stocks

    //Brute Force Approach(linear search)
    int max_profit = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                max_profit = max(max_profit,arr[j]-arr[i]);
            }
        }
    }
    cout<<max_profit<<endl;
    //time complexity: O(n^2)
    //space complexity: O(1)

    //better approach(kaden's algorithm)
    
}