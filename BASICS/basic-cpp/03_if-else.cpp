/*
If-Else Statements
Conditional statements are a fundamental concept in programming that allows you to make decisions based on certain conditions. These statements enable your code to execute different blocks of code depending on whether specific conditions are met or not. In this blog post, we'll delve into the basics of conditional statements, starting with the ubiquitous if-else statement and gradually exploring more complex scenarios.

'if statement' is used to execute a block of code only if a certain condition is met. It allows us to conditionally execute code based on whether the specified condition is true.
'else statement', on the other hand, is an optional companion to the if statement. It specifies what code to execute if the condition in the if statement is not met (i.e. if it is false).
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    // Declare a variable to store the user's age
    int age;

    // Ask the user to enter their age
    cout << "Enter your age: ";
    cin >> age;  // Take input from the user

    // Check if the user is 18 or older
    if (age >= 18) {
        // If true, print that the user is an adult
        cout << "You are an adult." << endl;
    } else {
        // Otherwise, print that the user is not an adult
        cout << "You are not an adult." << endl;
    }

    return 0; // End of program
}

// else-if ladder is used to check multiple conditions sequentially. It allows us to evaluate several conditions one after the other, executing the corresponding block of code for the first condition that evaluates to true. If none of the conditions are true, an optional else block can be executed as a fallback.

#include <iostream>
using namespace std;

int main() {
    // Declare and initialize marks variable
    int marks = 54;

    // Check grade conditions using if-else ladder
    if (marks < 25) {
        cout << "Grade: F" << endl;  // Less than 25 is Grade F
    } else if (marks >= 25 && marks <= 44) {
        cout << "Grade: E" << endl;  // Between 25 and 44 is Grade E
    } else if (marks >= 45 && marks <= 49) {
        cout << "Grade: D" << endl;  // Between 45 and 49 is Grade D
    } else if (marks >= 50 && marks <= 59) {
        cout << "Grade: C" << endl;  // Between 50 and 59 is Grade C
    } else if (marks >= 60 && marks <= 69) {
        cout << "Grade: B" << endl;  // Between 60 and 69 is Grade B
    } else if (marks >= 70) {
        cout << "Grade: A" << endl;  // 70 and above is Grade A
    } else {
        cout << "Invalid marks entered." << endl;  // Handles unexpected cases
    }

    return 0;
}

