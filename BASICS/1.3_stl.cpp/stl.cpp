#include<bits/stdc++.h>
using namespace std;
int main()
{
    void explainPair(){
        // pair is a container that holds two values of different data types
        pair<int, int> p = {1, 3};
        cout << p.first << " " << p.second << endl;

        // nested pair
        pair<int, pair<int, int>> p1 = {1, {3, 4}};
        cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

        // array of pairs
        pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
        cout << arr[1].second << endl;
    }

    void explainVector(){
        // vector is a dynamic array that can grow and shrink in size automatically when elements are added or removed
        vector<int> v;  
        v.push_back(1);
        v.push_back(2);
        v.emplace_back(3);
        //{1, 2, 3}
        // push_back and emplace_back both add elements to the end of the vector, but emplace_back constructs the element in place which can be more efficient for complex data types

        // vector of pairs
        vector< pair<int, int> > vec;
        vec.push_back({1, 2});
        vec.emplace_back(3, 4);          // in emplace_back, we don't need to use curly braces
        vec.emplace_back(3, {4,5});     // we have to use curly braces here because 4,5 is a pair
        //{ {1, 2}, {3, 4}, {3, {4,5}} }

        // vector with predefined size
        
        vector<int> v2(5, 100); // vector of size 5 with all values initialized to 100  
        // {100, 100, 100, 100, 100}
        vector<int> v3(5); // vector of size 5 with default values (0 for int)  
        // {0, 0, 0, 0, 0}
        vector<int> v1 ({1, 2, 3, 4}); // vector initialized with values 1, 2, 3, 4
        // {1, 2, 3, 4}
        vector<int> v4(v1); // vector copied from v1
        // {1, 2, 3, 4}

    }
    return 0;
}