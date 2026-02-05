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

    // not optimized
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    // optimized
    vector<int> divisors;
    // time complexity : O(sqrt(n))
    for(int i=1;i*i<=n;i++){  //sqrt(n) is function in stl it will take more time to compute so we can use i*i<=n to reduce time
        if(n%i==0){
            divisors.push_back(i);
            if(i!= (n/i)){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(),divisors.end());
    for(auto div : divisors){
        cout<<div<<" ";
    }
    
  
    
    // prime number : a number that has two factors 1 and itself
    
    //brute force

    int flag=0;
    for(int i=2;i<=n;i++){ //we are starting from 2 because 1 is a factor of every number and we are checking for factors other than 1 and itself
        if(n%i==0){
            flag+=1;
        }
    }
    if(n<=1){
        flag=0;
    }
    else if(flag==1){
        cout<<"Prime number"<<endl;
    }
    else{
        cout<<"Not a prime number"<<endl;
    }

    // optimized approach
     
    int isprime=0;
    for(int i=1;i*i<=n;i++){ // we are starting from 1 because if we start from 2 then we cannot get the factor (itself) as the loop will run only till sqrt(n) and we are checking for factors other than 1 and itself
        if(n%i==0){
            isprime+=1;
            if(i!= (n/i)){
                isprime+=1;
            }
    }
    if (n<=1){
        isprime=0;
    }
    else if(isprime==2){
        cout<<"Prime number"<<endl;
    }
    else{
        cout<<"Not a prime number"<<endl;
    }


    // GCD/HCF : greatest common divisor/highest common factor : largest number that divides two numbers

    int a,b;
    cin>>a>>b;
    // brute force
    //time complexity : O(min(a,b))
    int gcd=1;
    for(int i=min(a,b);i>=1;i--){ // we are starting from min(a,b) because the gcd cannot be greater than the smaller number
        if(a%i==0 && b%i==0){
            gcd=i;
            break; // this will break the for loop once we find the gcd
        }
    }
    cout<<gcd<<endl;

    // optimized approach : Euclidean algorithm
    // **** gcd(a,b) = gcd(a-b,b) if a>b or gcd(a,b) = gcd(a,b-a) if b>a
    // **** gcd(a,0) = a
    // **** gcd(a,b) = gcd(a%b,b)
    // time complexity : O(log(min(a,b)))
    
    
    while(b>0 && a>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    if(a==0){
        cout<<b<<endl;
    }
    else{
        cout<<a<<endl;
    }


    return 0;
}