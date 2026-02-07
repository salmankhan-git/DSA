#include<bits/stdc++.h>
using namespace std;    
//parameterized recursion is a type of recursion in which we pass parameters to the recursive function to keep track of the state of the recursion.

//printing sum of first n natural numbers using parameterized recursion

int sum(int n, int s){
    if(n<1) {
        cout<<"Sum of given natural numbers is: "<<s<<endl; //base condition
        return ; // returning nothing as we have already printed the sum
    }
    sum(n-1, s+n); //recursive call with updated parameters
}   


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    sum(n,0); //initial call with sum as 0
    return 0;
}