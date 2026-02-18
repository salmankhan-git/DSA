#include <bits/stdc++.h>
using namespace std;

// map is a data structure that stores key-value pairs. 
// ** time complexity of map is O(log n) for insertion, deletion and search operations. where n is the number of elements in the map.
//***  whereas unordered_map has O(1) averageand best time complexity for insertion, deletion and search operations and in worst case it is O(n).
// map hashes the key and stores the value in the corresponding bucket.
// < number, frequency >

//counting the frequency of elements in an array using map hashing.

int main(){
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mp; // map to store the frequency of elements in the array.
    // for string, we can use map<string, int> mp;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
        // for string, we can use mp[s[i]]++;
    }


    // iterate in the map
    // for(auto it : mp){
    //     cout << it.first << " " << it.second << endl; // print the number and its frequency.
    // }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << mp[x] << endl; // print the frequency of x in the array.
    }
    return 0;

}


//** in map we can have any data type as key and value( pairs), but in unordered_map we can have any data type as key but value must be of same type and key cannot be pairs.
// map<int, pair<int, int>> mp; // valid
// unordered_map<int, pair<int, int>> mp; // invalid

// ** in map we can have multiple keys with same value but in unordered_map we cannot have multiple keys with same value.
 
