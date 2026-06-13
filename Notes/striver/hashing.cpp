#include<iostream>
#include<string>
#include<map>
using namespace std;
//important points for declaring hash table:
//1. size of hash table should be greater than the maximum value of the element in the
//in int main function max size of integer hash table can be 10^6 ,globally 10^7
//for bool hash table it can be 10^7 in int main function and 10^8 globally
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompuute hash table
    int hash[13]={0}; //hash table of size 13
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    //query
    int q;
    cout<<"enter q";
    cin>>q;
    while(q--){
        int x;
        cout<<"enter x";
        cin>>x;
        cout<<"count of "<<x<<" is "<<hash[x]<<endl;
    }

    //string hashing
    string s;
    cout<<"enter string";
    cin>>s;
    int hash2[26]={0}; //hash table for lowercase letters
    for(int i=0;i<s.size();i++){
        hash2[s[i]-'a']++; //the index is autocasted to integer and it is the difference of ascii values of s[i] and 'a'
    }
    cout<<"enter character to query";
    char ch;
    cin>>ch;
    cout<<"count of "<<ch<<" is "<<hash2[ch-'a']<<endl;

    //using map for hashing
    //map stores all the keys in sorted order and it is implemented using balanced binary search tree, so the time complexity of all operations (insert, find, erase) is O(log n)
    map<int,int> mpp; //map of int to int
    for(int i=0;i<n;i++){
        mpp[arr[i]]++; //the key is arr[i] and the value is the count of arr[i]
    }
    int x2;
    cout<<"enter x to query in map";
    cin>>x2;
    cout<<"count of "<<x2<<" is "<<mpp[x2]<<endl; //if x is not present in the map then it will be added to the map with value 0 and then it will return 0    
    return 0;
}
/*
========================================
Difference Between map and unordered_map
========================================

Both store key-value pairs in C++.

----------------------------------------
1. map (Ordered Map)
----------------------------------------

- Stores keys in SORTED order.
- Internally implemented using:
      Red-Black Tree (Self-balancing BST)

Example:
    map<int, string> mp;

    mp[3] = "C";
    mp[1] = "A";
    mp[2] = "B";

Output order:
    1 -> A
    2 -> B
    3 -> C

Time Complexities:
    Insert  : O(log n)
    Delete  : O(log n)
    Search  : O(log n)

Why?
Because operations are performed on a balanced tree.

Advantages:
- Elements remain sorted
- Supports:
      lower_bound()
      upper_bound()
- Predictable performance

Disadvantages:
- Slower than unordered_map on average

----------------------------------------
2. unordered_map
----------------------------------------

- Stores keys in RANDOM order.
- Internally implemented using:
      Hash Table

Example:
    unordered_map<int, string> ump;

    ump[3] = "C";
    ump[1] = "A";
    ump[2] = "B";

Possible output:
    2 -> B
    3 -> C
    1 -> A

Time Complexities:

Average Case:
    Insert  : O(1)
    Delete  : O(1)
    Search  : O(1)

Worst Case:
    Insert  : O(n)
    Delete  : O(n)
    Search  : O(n)

Why worst case O(n)?
Because of HASH COLLISIONS.
Many keys may go into the same bucket.

Advantages:
- Very fast lookup
- Best for competitive programming hashing problems

Disadvantages:
- Order is not maintained
- Worst case can become O(n)

----------------------------------------
Key Differences
----------------------------------------

map:
    - Ordered
    - Uses Red-Black Tree
    - O(log n)
    - Traversal is sorted

unordered_map:
    - Unordered
    - Uses Hash Table
    - O(1) average
    - Traversal order is random

----------------------------------------
When to Use What?
----------------------------------------

Use map when:
    - You need sorted data
    - You need lower_bound / upper_bound
    - Order matters

Use unordered_map when:
    - You need fastest lookup
    - Order does not matter
    - Solving hashing problems

----------------------------------------
Important Interview Point
----------------------------------------

unordered_map is faster on average,
but map gives guaranteed O(log n) complexity.

In competitive programming,
sometimes map is preferred to avoid
worst-case hash collision attacks.

----------------------------------------
Memory Trick
----------------------------------------

map            -> Tree -> Ordered
unordered_map  -> Hash Table -> Fast Lookup

*/