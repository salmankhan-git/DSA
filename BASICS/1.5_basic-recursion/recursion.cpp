# include <bits/stdc++.h>
using namespace std;
// recurion is a process in which a function calls itself until a base condition is met.

//printing 1 to n using recursion(backtracking)
void print(int n){
    if(n==0) return; //base condition
    print(n-1); //recursive call
    cout<<n<<" "; //printing the number after the recursive call to print in increasing order
}
//or(backtracking)
void print(int i, int n){
    if(i<1) return; //base condition
    print(i-1,n); //recursive call
    cout<<i<<" "; //printing the number after the recursive call to print in increasing order
}
//or (forward tracking / normal way)
void print(int i, int n){
    if(i>n) return; //base condition
    cout<<i<<" "; //printing the number before the recursive call to print in increasing order
    print(i+1,n); //recursive call
}

//printing n to 1 using recursion
// forward tracking / normal way
void printReverse(int n){
    if(n==0) return; //base condition
    cout<<n<<" "; //printing the number before the recursive call to print in decreasing order
    printReverse(n-1); //recursive call
}
// or (backtracking)
void printReverse(int i, int n){
    if(i>n) return; //base condition
    printReverse(i+1,n); //recursive call
    cout<<i<<" "; //printing the number after the recursive call to print in decreasing order
}
// or (forward tracking / normal way)
void printReverse(int i, int n){
    if(i<1) return; //base condition
    cout<<i<<" "; //printing the number before the recursive call to print in decreasing order
    printReverse(i-1,n); //recursive call
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    // print(n);
    //or
    // print(n,n);
    //or
    // print(1,n);

    // printReverse(n);
    //or
    // printReverse(1,n);
    // or
    // printReverse(n,n);
    return 0;

}