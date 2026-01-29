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

void explainList(){
    // list is a doubly linked list that allows efficient insertion and deletion of elements from both ends
    list<int> l;
    l.push_back(1);
    //l.emplace_back(2);
    l.push_front(2);
    // l.emplace_front(2);

    // l: {2, 1}

    // iterator
    list<int>::iterator it = l.begin();
    it++;
    cout << *(it) << endl; // prints 1

    // accessing elements
    cout << l.front() << endl; // prints 2
    cout << l.back() << endl;  // prints 1
    // cout << l[0] << endl; // error: list does not support random access
    // cout << l.at(0) << endl; // error: list does not support at() function


    // printing list using iterator
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *(it) << " ";
    }

    // printing list using range-based for loop
    for (auto it : l) {
        cout << it << " ";
    }

    //insert function
    it = l.begin();
    l.insert(it, 3); // inserts 3 at the beginning
    l.insert(it, 2, 4); // inserts two 4s before the first element
    // l: {4, 4, 3, 2, 1}
    list<int> l1 = {5, 6, 7};
    list<int> l2 = {8, 9};
    // inserting l1 and l2 at the end of l
    for (auto& lst : {l1, l2}) {
        l.insert(l.end(), lst.begin(), lst.end());
        // l: {4, 4, 3, 2, 1, 5, 6, 7, 8, 9}
    }


    // erase function
    // l.erase(l.begin()); // erases element at the beginning

    // size function
    cout << l.size() << endl; // prints the size of the list

    // pop front and pop back
    l.pop_front(); // removes the first element
    l.pop_back();  // removes the last element

    // swap function
    list<int> l2 = {3, 4};
    l.swap(l2); // swaps the contents of l and l2

    // clear function
    l.clear(); // removes all elements from the list

    // check if list is empty
    cout << l.empty() << endl; // returns false (0) if list is not empty, true (1) otherwise;
}

void explainDeque(){
    // deque is a double-ended queue that allows insertion and deletion of elements from both ends
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    // d: {2, 1}

    // accessing elements
    cout << d.front() << endl; // prints 2
    cout << d.back() << endl;  // prints 1
    cout << d[0] << endl;      // prints 2
    cout << d.at(0) << endl;   // prints 2

   // rest functions same as vector
   // iterator, printing, insert, erase, size, pop_back, pop_front, swap, clear, empty ,rbegin, rend all are same as vector
}

void explainStack(){
    // stack is a container that follows the Last In First Out (LIFO) principle
    stack<int> s;
    s.push(1); //{1}
    s.push(2); // {1, 2}
    s.push(3); // {1, 2, 3}
    s.emplace(4); // {1, 2, 3, 4}
    // s: {1, 2, 3, 4} (4 is at the top)

    cout << s.top() << endl; // prints 4

    s.pop(); // removes the top element (4)
    cout << s.top() << endl; // prints 3

    cout << s.size() << endl; // prints the size of the stack (3)

    cout << s.empty() << endl; // returns false (0) if stack is not empty, true (1) otherwise

    stack<int> s1, s2;
    s1.swap(s2); // swaps the contents of s1 and s2
}

void explainQueue(){
    // queue is a container that follows the First In First Out (FIFO) principle
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.push(3); // {1, 2, 3}
    q.emplace(4); // {1, 2, 3, 4}
    // q: {1, 2, 3, 4} (1 is at the front)

    cout << q.front() << endl; // prints 1
    cout << q.back() << endl;  // prints 4

    q.pop(); // removes the front element (1)
    cout << q.front() << endl; // prints 2

    cout << q.size() << endl; // prints the size of the queue (3)

    cout << q.empty() << endl; // returns false (0) if queue is not empty, true (1) otherwise

    queue<int> q1, q2;
    q1.swap(q2); // swaps the contents of q1 and q2
}

void explainPriorityQueue(){
    // priority_queue is a container that allows retrieval of the largest (by default) element first
    priority_queue<int> pq; // max-heap
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    // pq: {4, 3, 2, 1} (4 is at the top)

    cout << pq.top() << endl; // prints 4

    pq.pop(); // removes the top element (4)
    cout << pq.top() << endl; // prints 3

    cout << pq.size() << endl; // prints the size of the priority queue (3)

    cout << pq.empty() << endl; // returns false (0) if priority queue is not empty, true (1) otherwise

    // min-heap
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(3);
    minPq.push(1);
    minPq.push(4);
    minPq.push(2);
    // minPq: {1, 2, 3, 4} (1 is at the top)

    cout << minPq.top() << endl; // prints 1
}

void explainSet(){
    // set is a container that stores unique elements in a sorted order
    set<int> st;
    st.insert(3);
    st.insert(1);
    st.insert(4);
    st.insert(2);
    st.insert(2); // duplicate element, will not be added
    // st: {1, 2, 3, 4}

    // iterator
    set<int>::iterator it = st.begin();
    cout << *(it) << endl; // prints 1

    it++;
    cout << *(it) << endl; // prints 2

    //lower_bound and upper_bound
    auto itlow = st.lower_bound(3); // returns iterator to the first element not less than 3
    auto itlow2 = st.lower_bound(0); // returns iterator to the first element not less than 0 (which is 1)
    auto itup1 = st.upper_bound(4);  // returns iterator to the first element greater than 4 (which doesn't exist, so it returns st.end())
    auto itup2 = st.upper_bound(5);  // returns iterator to the first element greater than 5 (which doesn't exist, so it returns st.end())
    cout << *(itlow) << endl; // prints 3
    cout << *(itlow2) << endl; // prints 1
    cout << *(itup1) << endl;  // prints garbage value as itup1 is st.end()
    cout << *(itup2) << endl;  // prints garbage value as itup2 is st.end()

    // count function
    cout << st.count(3) << endl; // returns 1 if element 3 is present, 0 otherwise

    //finding an element
    auto it1 = st.find(3); // returns iterator to the element if found, which is the memory address of the element
    auto it2 = st.find(5); // returns st.end() if element not found
    
    
    // printing set using iterator
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *(it) << " ";
    }

    // printing set using range-based for loop
    for (auto it : st) {
        cout << it << " ";
    }

    // erase function
    st.erase(2); // erases element 2
    // st.erase(st.begin()); // erases the first element
    // st.erase(st.begin(), st.find(4)); // erases elements from beginning to element 4 (excluding 4)


    // size function
    cout << st.size() << endl; // prints the size of the set

    // clear function
    st.clear(); // removes all elements from the set

    // check if set is empty
    cout << st.empty() << endl; // returns false (0) if set is not empty, true (1) otherwise
 
    
}
    
void explainMultiSet(){
    // multiset is a container that stores multiple occurrences of elements in a sorted order
    multiset<int> ms;
    ms.insert(3);
    ms.insert(1);
    ms.insert(4);
    ms.insert(2);
    ms.insert(2); // duplicate element, will be added
    // ms: {1, 2, 2, 3, 4}

    // iterator
    multiset<int>::iterator it = ms.begin();
    cout << *(it) << endl; // prints 1

    it++;
    cout << *(it) << endl; // prints 2

    // count function
    cout << ms.count(2) << endl; // returns the number of occurrences of element 2

    // printing multiset using iterator
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *(it) << " ";
    }

    // printing multiset using range-based for loop
    for (auto it : ms) {
        cout << it << " ";
    }

    // erase function
    ms.erase(2); // erases all occurrences of element 2
    // ms.erase(ms.begin()); // erases the first element
    // ms.erase(ms.begin(), ms.find(4)); // erases elements from beginning to element 4 (excluding 4)
    // ms.erase(ms.find(2)); // erases only one occurrence of element 2
    // ms.erase(ms.find(2), ms.find(4)); // erases elements from first occurrence of 2 to element 4 (excluding 4)
    // ms.erase(ms.begin()+2); // error: multiset does not support random access iterators
    // ms.erase(ms.begin(),ms.end()); // erases all elements

    //lower_bound and upper_bound
    auto itlow = ms.lower_bound(2); // returns iterator to the first element not less than 2
    auto itup = ms.upper_bound(2);  // returns iterator to the first element greater than 2
    cout << *(itlow) << endl; // prints 2
    cout << *(itup) << endl;  // prints 3

}

void explainUnorderedSet(){
    // unordered_set is a container that stores unique elements in no particular order
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(4);
    us.insert(2);
    us.insert(2); // duplicate element, will not be added
    // us: {3, 1, 4, 2} (order may vary)

    // iterator
    unordered_set<int>::iterator it = us.begin();
    cout << *(it) << endl; // prints an element (order may vary)

    it++;
    cout << *(it) << endl; // prints another element (order may vary)

    // count function
    cout << us.count(3) << endl; // returns 1 if element 3 is present, 0 otherwise

    //finding an element
    auto it1 = us.find(3); // returns iterator to the element if found
    auto it2 = us.find(5); // returns us.end() if element not found

    // printing unordered_set using iterator
    for (unordered_set<int>::iterator it = us.begin(); it != us.end(); it++) {
        cout << *(it) << " ";
    }

    // printing unordered_set using range-based for loop
    for (auto it : us) {
        cout << it << " ";
    }

    // erase function
    us.erase(2); // erases element 2

    // size function
    cout << us.size() << endl; // prints the size of the unordered_set

    // clear function
    us.clear(); // removes all elements from the unordered_set

    // check if unordered_set is empty
    cout << us.empty() << endl; // returns false (0) if unordered_set is not empty, true (1) otherwise

    // Note: lower_bound and upper_bound functions are not available for unordered_set

}

void explainUnorderedMultiSet(){
    // unordered_multiset is a container that stores multiple occurrences of elements in no particular order
    unordered_multiset<int> ums;
    ums.insert(3);
    ums.insert(1);
    ums.insert(4);
    ums.insert(2);
    ums.insert(2); // duplicate element, will be added
    // ums: {3, 1, 4, 2, 2} (order may vary)

    // iterator
    unordered_multiset<int>::iterator it = ums.begin();
    cout << *(it) << endl; // prints an element (order may vary)

    it++;
    cout << *(it) << endl; // prints another element (order may vary)

    // count function
    cout << ums.count(2) << endl; // returns the number of occurrences of element 2

    // printing unordered_multiset using iterator
    for (unordered_multiset<int>::iterator it = ums.begin(); it != ums.end(); it++) {
        cout << *(it) << " ";
    }

    // printing unordered_multiset using range-based for loop
    for (auto it : ums) {
        cout << it << " ";
    }

    // erase function
    ums.erase(2); // erases all occurrences of element 2

    // remaining functions are same as unordered_set
    // lower_bound and upper_bound functions are not available for unordered_multiset

}

void explainMap(){
    // map is a container that stores key-value pairs in a sorted order based on unique keys
    map<int, string> mp;
    mp[1] = "one";
    mp[3] = "three";
    mp[2] = "two";
    // mp: {1: "one", 2: "two", 3: "three"}
    //mp.insert({4, "four"});
    // mp.emplace(5, "five");

    map<pair<int, int>, int> mp1;
    mp1[{1, 2}] = 3;
    mp1[{1, 1}] = 4;
    // mp1: { {1, 1}: 4, {1, 2}: 3 }

    map<int, map<int, string>> mp2;
    mp2[1][1] = "one";
    mp2[1][2] = "two";
    // mp2: { 1: {1: "one", 2: "two"} }

    map<int, pair<string, int>> mp3;
    mp3[1] = {"one", 1};
    mp3[2] = {"two", 2};
    // mp3: { 1: {"one", 1}, 2: {"two", 2} }

    // iterator
    map<int, string>::iterator it = mp.begin();
    cout << it->first << " " << it->second << endl; // prints 1 one

    it++;
    cout << it->first << " " << it->second << endl; // prints 2 two

    // accessing elements
    cout << mp[3] << endl; // prints "three"
    cout << mp.at(2) << endl; // prints "two"
    cout << mp[5] << endl; // inserts key 5 with default value "" and prints ""
    
    //finding an element
    auto it1 = mp.find(2); // returns iterator to the key-value pair if found
    auto it2 = mp.find(5); // returns mp.end() if key not found

    // printing map using iterator
    for (map<int, string>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // printing map using range-based for loop
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }

    //lower_bound and upper_bound
    auto itlow = mp.lower_bound(2); // returns iterator to the first key not less than 2
    auto itup = mp.upper_bound(2);  // returns iterator to the first key greater than 2
    cout << itlow->first << " " << itlow->second << endl; // prints 2 two
    cout << itup->first << " " << itup->second << endl;  // prints 3 three


    // erase function
    mp.erase(2); // erases key-value pair with key 2

    // size function
    cout << mp.size() << endl; // prints the size of the map it is 2 now

    // clear function
    mp.clear(); // removes all key-value pairs from the map

    // check if map is empty
    cout << mp.empty() << endl; // returns false (0) if map is not empty, true (1) otherwise
}
 
void explainMultiMap(){
    // multimap is a container that stores multiple key-value pairs with the same key in a sorted order
    multimap<int, string> mmp;
    mmp.insert({1, "one"});
    mmp.insert({2, "two"});
    mmp.insert({1, "uno"});
    // mmp: {1: "one", 1: "uno", 2: "two"}

    // printing
    // cout<< mmp[1]<<endl; // error: multimap does not support [] operator
    // mmp.at(1); // error: multimap does not support at() function

    // finding an element
    auto it1 = mmp.find(1); // returns iterator to the first key-value pair with key 1 but it could be "one" or "uno" based on internal ordering
    auto it2 = mmp.find(3); // returns mmp.end() if key not found

    // iterator
    multimap<int, string>::iterator it = mmp.begin();
    cout << it->first << " " << it->second << endl; // prints 1 one

    it++;
    cout << it->first << " " << it->second << endl; // prints 1 uno

    // count function
    cout << mmp.count(1) << endl; // returns the number of occurrences of key 1

    // printing multimap using iterator
    for (multimap<int, string>::iterator it = mmp.begin(); it != mmp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // printing multimap using range-based for loop
    for (auto it : mmp) {
        cout << it.first << " " << it.second << endl;
    }

    //lower_bound and upper_bound
    auto itlow = mmp.lower_bound(1); // returns iterator to the first key not less than 1
    auto itup = mmp.upper_bound(1);  // returns iterator to the first key greater than 1
    cout << itlow->first << " " << itlow->second << endl; // prints 1 one but it could also print 1 uno based on internal ordering
    cout << itup->first << " " << itup->second << endl;  // prints 2 two

    // erase function
    mmp.erase(1); // erases all key-value pairs with key 1

    // remaining functions are same as map
}

void explainUnorderedMap(){
    // unordered_map is a container that stores key-value pairs in no particular order based on unique keys
    unordered_map<int, string> ump;
    ump[1] = "one";
    ump[3] = "three";
    ump[2] = "two";
    // ump: {1: "one", 2: "two", 3: "three"} (order may vary)

    // rest functions are same as map
    // iterator, accessing elements, finding an element, printing, lower_bound, upper_bound (not available), erase, size, clear, empty

}

void explainUnorderedMultiMap(){
    // unordered_multimap is a container that stores multiple key-value pairs with the same key in no particular order
    unordered_multimap<int, string> ummp;
    ummp.insert({1, "one"});
    ummp.insert({2, "two"});
    ummp.insert({1, "uno"});
    // ummp: {1: "one", 1: "uno", 2: "two"} (order may vary)

    // rest functions are same as multimap
    // iterator, finding an element, count, printing, lower_bound, upper_bound (not available), erase

}

void explainExtra(){
    
    // sort
    
    // for vectors
    // sort(v.begin(), v.end()); // sorts the vector in ascending order
    // sort(v.begin(), v.end(), greater<int>()); // sorts the vector in descending order
    
    // for arrays
    // int arr[n] = {4, 2, 1, 3};
    // sort(arr, arr + n); // sorts the array in ascending order
    // sort(arr, arr + n, greater<int>()); // sorts the array in descending order
    
    // reverse
    // reverse(v.begin(), v.end()); // reverses the vector
    // reverse(arr, arr + n); // reverses the array

    pair<int, int> a[] = { {1, 2}, {2, 1}, {4, 1} };
    // sort it according to second element of pair
    // if second elements are same, then sort according to first element in descending order 
    sort(a, a + 3, comp);


    // prints all permutations of the string in lexicographical order
    string s="12345";
    sort(s.begin(), s.end()); // s = "12345"
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));

    // maximum and minimum
    int a[5] = {1, 2, 3, 4, 5};
    // cout << *max_element(a, a + 5) << endl; // prints the maximum element in the array
    // cout << *min_element(a, a + 5) << endl; // prints the minimum element in the array

}

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second){  
        return true;
    } else if(p1.second == p2.second){
        if(p1.first > p2.first) return true;
    }
    return false;

    //or
    // if(p1.second == p2.second) return p1.first > p2.first;
    // return p1.second < p2.second;
}

int main(){
    explainPair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPriorityQueue();
    explainSet();
    explainMultiSet();
    explainUnorderedSet();
    explainUnorderedMultiSet();
    explainMap();
    explainMultiMap();
    explainUnorderedMap();
    explainUnorderedMultiMap();
    
    return 0;
}