#include<bits/stdc++.h>
using namespace std;
// functions are set of code which perform a specific task
// functions are used to modularise the code
// functions are used to avoid code repetition
// functions are used to make the code more readable and maintainable

// types of functions:
// void functions: functions which do not return any value
// return functions: functions which return a value
// parameterized functions: functions which take parameters
// non-parameterized functions: functions which do not take parameters
 
void nonParameterizedFunction(){
    cout << "This is a non-parameterized function" << endl;
}
void parameterizedFunction(string name ){
    cout << "This is a parameterized function" << endl;
    cout << "The name is " << name << endl;
}
int sum(int a, int b){
    int c = a + b;
    return c;
}
int main(){
    nonParameterizedFunction();

    string name = "salman";
    parameterizedFunction(name);

    int a = 5, b = 10;
    int result = sum(a, b);
    cout << "The sum is " << result << endl;
    cout<<sum(15,25)<<endl; // directly passing values to the function
 
    return 0;
}



// passby value vs passby reference
// passby value: when a copy of the actual parameter is passed to the function
// passby reference: when the address of the actual parameter is passed to the function

void passByValue(int x){
    x = x + 10;
    cout << "Inside passByValue function: " << x << endl;
}

void passByReference(int &x){
    x = x + 10;
    cout << "Inside passByReference function: " << x << endl;
}

int main(){
    int a = 5;
    cout << "Before passByValue function: " << a << endl; // original value
    passByValue(a);// output will be 15 inside function but original value will remain same
    cout << "After passByValue function: " << a << endl; // original value remains unchanged

    int b = 5;
    cout << "Before passByReference function: " << b << endl;// original value
    passByReference(b);// output will be 15 inside function and original value will be changed
    cout << "After passByReference function: " << b << endl;// original value is changed

    return 0;
}

// array always passed by reference
void modifyArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = arr[i] * 2;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr);

    cout << "Array before modification: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    modifyArray(arr, size);

    cout << "Array after modification: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
