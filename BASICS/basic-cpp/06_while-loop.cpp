/*
A while loop is a control structure in programming that repeatedly executes a block of code as long as a specified condition remains true. A "while" loop will not execute the code at all if the initial condition is false. It relies on the condition being true from the outset for any code execution to occur.
*/

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int factorial = 1;

    while (n > 0) {
        factorial *= n;  //Keep finding factorial with n and decrement n
        // x*=y is equivalent to x = x * y
        // in the above step we Multiplies the current value of factorial by n. like in first iteration it would be 1*5=5, in second iteration it would be 5*4=20 and so on. 
        n--;
    }

    cout << "Factorial of 5 is: " << factorial << endl;  //Print the factorial

    return 0;
}


/*
do while Loop is another type of loop in C++ that guarantees the block of code will execute at least once, regardless of whether the condition is true or false initially. This is because the condition is evaluated after the execution of the loop's body.
*/
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int factorial = 1;

    do {
        factorial *= n;   // multiply factorial by n
        n--;              // decrement n
    } while (n > 0);

    cout << "Factorial of 5 is: " << factorial << endl;

    return 0;
}

// If n were 0, this code would still run once and give a wrong result. but in this case it is guaranteed to run correctly as n starts from 5 and going to 0 at last.
// Use `do-while` only when the loop must run at least once; otherwise, use `while`.
