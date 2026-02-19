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

// functional recursion is a type of recursion in which we return the result of the recursive call to the caller function. In functional recursion, we do not use any global variables to keep track of the state of the recursion. Instead, we return the result of the recursive call to the caller function and use it to compute the final result.

int sum_func(int n){
    if(n==0) return 0; //base condition
    return n + sum_func(n-1); //recursive call returning the result to the caller function
}


// calcularion of factorial using parameterized recursion
int factorial(int n, int f){
    if(n<1){
        cout<<"Factorial of given number is: "<<f<<endl; //base condition
        return ; // returning nothing as we have already printed the factorial
    }
     factorial(n-1, f*n); // we are not using 
}

// calculation of factorial using functional recursion
int factorial_func(int n){
    if(n==0) return 1; //base condition
    return n * factorial_func(n-1); //recursive call returning the result to the caller function
}


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    
    // sum(n,0); //initial call with sum as 0
    
    // cout<<"Sum of given natural numbers is: "<<sum_func(n)<<endl; //calling functional recursion
    
    // factorial(n,1); //initial call with factorial as 1
    
 
    // cout<<"Factorial of given number is: "<<factorial_func(n)<<endl; //calling functional recursion
    
    return 0;
}