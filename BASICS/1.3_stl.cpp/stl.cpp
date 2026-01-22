#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Create a vector of integers
    vector<int> vec;

    // Add some elements to the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Iterate through the vector and print its elements
    for(size_t i = 0; i < vec.size(); i++) {
        cout << "Element at index " << i << ": " << vec[i] << endl;
    }

    return 0;
}