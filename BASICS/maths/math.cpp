#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // find the digits in a  given number
    int n;
    cin>>n;
    int count=0;
    while(n>0){
    
        // n%10;  // extract last digit

        n=n/10; // remove last digit
        count++;

    }
    cout<<count<<endl;

    // or by log10 function

    int m = log10(n) + 1;
    cout<<m<<endl;
    

    return 0;
}