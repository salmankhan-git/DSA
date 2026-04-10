#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr [] = {7,1,5,3,6,4};
    int n =sizeof(arr)/sizeof(arr[0]);

    // Q. Best time to buy and sell stocks
    // we have to buy first and then sell the stock, we have to find the maximum profit that we can make by buying and selling the stock.

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
    // We convert prices into daily differences, then apply Kadane:
    // diff = [1-7, 5-1, 3-5, 6-3, 4-6] = [-6, +4, -2, +3, -2]

    int max_current = 0;
    int max_profit1 = 0;
    for(int i=1;i<n;i++){
        int diff = arr[i]-arr[i-1];
        max_current = max(0,max_current+diff); //we are using zero instead of max_current because if the current profit is negative then we will not consider it and start a new subarray from the next element.
        max_profit1 = max(max_profit1,max_current);
    }
    cout<<max_profit1<<endl;
    //time complexity: O(n)
    //space complexity: O(1)


    // Optimal approach(greedy approach)
    // if you are selling on the ith day then you must have bought the stock on the day when the price was minimum before the ith day.

    int min_price = arr[0];
    int max_profit2 = 0;

    for(int i=1;i<n;i++){
        if(arr[i]<min_price){
            min_price = arr[i];
        }
        else if(arr[i]-min_price>max_profit2){
            max_profit2 = arr[i]-min_price;
        }
    }
    cout<<max_profit2<<endl;
    //time complexity: O(n)
    //space complexity: O(1)

return 0;
}