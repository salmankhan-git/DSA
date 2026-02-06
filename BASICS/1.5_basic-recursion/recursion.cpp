# include <bits/stdc++.h>
using namespace std;
// recurion is a process in which a function calls itself until a base condition is met.

//printing 1 to n using recursion
void print(int n){
    if(n==0) return; //base condition
    print(n-1); //recursive call
    cout<<n<<" "; //printing the number after the recursive call to print in increasing order
}
//or
void print(int i, int n){
    if(i>n) return; //base condition
    cout<<i<<" "; //printing the number before the recursive call to print in increasing order
    print(i+1,n); //recursive call
}


int main(){
 
    // print(5);
    //or
    print(1,5);
    return 0;

}