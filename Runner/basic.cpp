#include <iostream>
using namespace std;
void parameterizedFunction(string random ){
    cout << "This is a parameterized function" << endl;
    cout << "The name is " << random << endl;
}
int main(){

    string name = "salman";
    parameterizedFunction(name);

    return 0;
}
