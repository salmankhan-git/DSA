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
    
    // reverse number
    
    int reverse = 0;
    while(n>0){
        int lastdigit = n%10; // extract last digit
        reverse = reverse*10 + lastdigit; // append last digit
        n=n/10; // remove last digit
    }
    cout<<reverse<<endl;

    // pallindrome number : a number that is same when reversed

    int num=n;
    int rev=0;
    while(n>0){
        int lastdigit = n%10;
        rev = rev*10 + lastdigit;
        n=n/10;
    }
    if(num==rev){
        cout<<"Pallindrome number"<<endl;
    }
    else{
        cout<<"Not a pallindrome number"<<endl;
    }

    //armstrong number : sum of cubes of each digit is equal to the number itself
    int originalnum = n;
    int sum =0;
    while(n>0){
        int lastdigit = n%10;
        sum = sum + (lastdigit*lastdigit*lastdigit);
        n=n/10;
    }
    if(sum==originalnum){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"Not an Armstrong number"<<endl;
    }

    // all divisors of a number
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    return 0;
}