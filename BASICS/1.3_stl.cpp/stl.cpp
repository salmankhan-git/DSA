#include<bits/stdc++.h>
using namespace std;

void explainPair(){
        // pair is a container that holds two values of different data types
        pair<int, int> p = {1, 3};
        cout << p.first << " " << p.second << endl;

        // nested pair
        pair<int, pair<int, int> > p1 = {1, {3, 4}};
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
        // v.emplace_back(3);
        //{1, 2, 3}
        // push_back and emplace_back both add elements to the end of the vector, but emplace_back constructs the element in place which can be more efficient for complex data types

        // vector of pairs
        vector< pair<int, int> > vec;
        vec.push_back({1, 2});
        // vec.emplace_back(3, 4);          // in emplace_back, we don't need to use curly braces
        // vec.emplace_back(3, {4,5});     // we have to use curly braces here because 4,5 is a pair
        //{ {1, 2}, {3, 4}, {3, {4,5}} }

        // vector with predefined size
        
        vector<int> v2(5, 100); // vector of size 5 with all values initialized to 100  
        // {100, 100, 100, 100, 100}
        vector<int> v3(5); // vector of size 5 with default values (0 for int)  
        // {0, 0, 0, 0, 0}
        // vector<int> v1 ( {1, 2, 3, 4} ); // vector initialized with values 1, 2, 3, 4
        // {1, 2, 3, 4}
        // vector<int> v4(v1); // vector copied from v1
        // {1, 2, 3, 4}


        //iterator
        vector<int> v1 = {1, 2, 3, 4};
        vector<int>::iterator it = v1.begin();
        it++;
        cout << *(it) << endl; // prints 2

        it = it + 2;
        cout << *(it) << endl; // prints 4

        // iterator to end of vector
        vector<int>::iterator it1 = v1.end(); // points to one position after the last element
        it1--;
        cout << *(it1) << endl; // prints 4


        // vector<int>::iterator it1 = v1.rend(); // reverse iterator to one position before the first element
        it1--;
        cout << *(it1) << endl; // prints 1

        // vector<int>::iterator it1 = v1.rbegin(); // reverse iterator to the last element
        cout << *(it1) << endl; // prints 4

        // accessing elements        
        cout<< v1[0]<< " "<<v1.at(0)<<endl; // both are used to access elements at index 0
        cout<< v1.back()<<endl; // prints the last element of the vector

       //printing vector using iterator
        for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
            cout<<*(it)<<" ";
        }
        // printing vector using auto keyword
        for(auto it = v1.begin(); it != v1.end(); it++){
            cout<<*(it)<<" ";
        }
        // printing vector using range-based for loop or for each loop
        for(auto it : v1){
            cout<<it<<" ";
        }
        //or we can use "&" to avoid copying the elements
        for(auto &it : v1){
            it+=2; // this will increment each element in the vector by 2
            cout<<it<<" ";
        }

        // erase function
        // v1.erase(v1.begin()+1); // erases element at index 1
        // v1.erase(v1.begin()+1, v1.begin()+3); // erases elements from index 1 to 2 [start, end)

        // insert function
        v1.insert(v1.begin(), 5); // inserts 5 at the beginning
        v1.insert(v1.begin()+1, 2, 10); // inserts two 10s at index 1

        // v1: {5, 10, 10, 1, 2, 3, 4}
        vector<int> v2 = {2, 50, 80, 30}; //
        vector<int> v3 = {100, 200};
        
        //insert v2 at the end of v1
        // v1.insert(v1.begin()+2, v2.begin(), v2.end()); // inserts elements of v2 at index 2
        // v1: {5, 10, 2, 50, 80, 30, 10, 1, 2, 3, 4}
        
        // inserting both v2 and v3 at the end of v1 simultaneously
        for(auto& v : {v2, v3}){
            v1.insert(v1.end(), v.begin(), v.end());
            //v1: {5, 10, 2, 50, 80, 30, 10, 1, 2, 3, 4, 2, 50, 80, 30, 100, 200}
        
        }

        //size function
        cout<<v1.size()<<endl; // prints the size of the vector

        //pop back
        // v1.pop_back(); // removes the last element

        //swap function
        // v1.swap(v2); // swaps the contents of v1 and v2

        // clear function
        // v1.clear(); // removes all elements from the vector

        // check if vector is empty
        cout<<v1.empty()<<endl; // returns false (0) if vector is not empty, true (1) otherwise
    
    
    }



int main()
{
    explainPair();
    explainVector();
    return 0;
}