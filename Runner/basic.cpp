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
