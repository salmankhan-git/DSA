#include<bits/stdc++.h>
using namespace std;
// hashing is a technique used to store and retrieve data in a way that allows for fast access.
// a hash function is used to convert a key into an index in a hash table where the value is stored.
// a good hash function should distribute the keys uniformly across the hash table to minimize collisions.
//**** note : array max size 
//          inside main()  int - 10^6/1e6     , bool - 10^7/1e7
//          global scope   int - 10^7/1e7     , bool - 10^8/1e8

// array inside main() should be initialized with zero ( int arr[n]={0} )or any default value to avoid garbage values
// which can lead to incorrect results when used as a hash table, 
// whereas global arrays are automatically initialized to zero by the compiler, 
// so they can be used directly as hash tables without explicit initialization. 


int main(){
    // counting the frequency of numbers in an array using hashing
   
    //array input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // making a hash array to store the frequency of numbers
    int hash[100]={0}; // assuming the numbers are between 0 and 99
    
    // counting the frequency of each number in the array using the hash array
    for(int i=0;i<n;i++){
        hash[arr[i]]+= 1; // incrementing the count of the number in the hash array
        // or
        // hash[arr[i]]++;
    }

    // taking the inut of numbers for which we want to find the frequency
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<"The frequency of "<<number<<" is: "<<hash[number]<<endl; // output the frequency of the number
    }
   return 0;
}