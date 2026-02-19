/* 
Switch Case Statements

If-else statements are like the Swiss Army knife of decision-making. They offer flexibility and can handle a wide range of conditions and branching logic. You can use them when you need to evaluate complex conditions or when conditions aren't based on simple equality checks. If-else statements are often the preferred choice for scenarios where the conditions are not easily enumerable or where you need to execute different blocks of code based on various conditions.

On the other hand, switch statements shine when you have a single variable to compare against multiple distinct values. They are concise, making the code cleaner and more structured. So, if-else statements and switch statements can complement each other, with if-else statements handling complex conditions and switch statements simplifying cases with multiple exact matches.*/


#include <iostream>
using namespace std;

int main() {
    int day;

    // Prompt user to enter a number between 1 and 7
    cout << "Enter a number (1-7): ";
    cin >> day;

    // Switch statement to determine the day
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break; // Exit switch after matching case
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default:
            // Executed if input is not between 1 and 7
            cout << "Invalid" << endl;
    }

    return 0; // End program
}

//A switch statement necessitates that its expression results in a constant value. This can include constants and arithmetic operations.
//For instance, you can use integer literals, character literals, or enumerated types as case labels. However, variables that can change at runtime cannot be used as case labels since they do not yield constant values.