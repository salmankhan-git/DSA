#include<bits/stdc++.h>
using namespace std;
// multple recursion is a type of recursion where a function calls itself more than once in its body.
// example of multiple recursion is the fibonacci series where each term is the sum of the two preceding terms.
int fib(int n){
    if(n<=1) return n;
    // return fib(n-1)+fib(n-2);
    // or
    int last=fib(n-1);
    int secondLast=fib(n-2);
    return last+secondLast;
}
// the time complexity of this approach is approx O(2^n) because each term is calculated multiple times.
// the space complexity is O(n) because of the recursive call stack.

int main(){
    int n;
    cin>>n;
    cout<<"The "<<n<<"th term of the fibonacci series is: "<<fib(n)<<endl;
   return 0;
}