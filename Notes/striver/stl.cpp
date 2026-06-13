#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>           // for set and multiset
#include <unordered_set> // for unordered_set
#include <map>           // for map and multimap
#include <unordered_map> // for unordered_map

using namespace std;
void explainpair(){
    pair<int , int> p={1,3};
    cout<<p.first<< " "<<p.second<<endl;
    pair<int, pair<int,int> > p2={1,{2,3}};
    cout<<p2.first<<" "<<p2.second.second<<endl;
    pair<int,int> arr[]={{1,2},{3,4},{5,6}};//array of type pair
    cout<<arr[1].second<<endl;
}
void explainVector() {
    // 1. Basics & Dynamics
    vector<int> v_basic; 
    v_basic.push_back(1);
    v_basic.emplace_back(2); // Often FASTER than push_back
    
    cout << "First element: " << v_basic[0] << endl;

    // 2. Vector of Pairs
    vector<pair<int, int>> vec_pair;
    vec_pair.push_back({1, 2});
    vec_pair.emplace_back(3, 4); // No curly braces needed with emplace
    cout << "Pair first element: " << vec_pair[0].first << endl;

    // 3. Different Initialization Methods
    vector<int> v1(5);          // {0, 0, 0, 0, 0}
    vector<int> v9(5, 10);      // {10, 10, 10, 10, 10}
    vector<int> v10(v9);         // Copy of v9

    // 4. Iterators (The "Pointers" of STL)
    vector<int> v = {10, 20, 30, 40, 50};
    
    // Standard Iterator
    vector<int>::iterator it = v.begin(); 
    cout << "Start: " << *it << endl; // 10
    it++;
    cout << "After it++: " << *it << endl; // 20
    it += 2;
    cout << "After it+=2: " << *it << endl; // 40

    // The end() iterator points PAST the last element
    vector<int>::iterator it_end = v.end(); 
    it_end--; // Move back to the last element
    cout << "Last element via end(): " << *it_end << endl; // 50

    // 5. Reverse Iterators
    // Note: Use 'reverse_iterator' type or simply 'auto'
    
    
    vector<int>::reverse_iterator rit = v.rbegin(); 
    cout << "Reverse start (last element): " << *rit << endl; // 50
    
    rit++; // In a reverse iterator, ++ moves TOWARDS the beginning
    cout << "Reverse next: " << *rit << endl; // 40

    // rend() points BEFORE the first element
    vector<int>::reverse_iterator rit_end = v.rend(); 
    rit_end--; 
    cout << "Reverse end (first element): " << *rit_end << endl; // 10

    //for loop with auto
    cout<<"Using auto in for loop: ";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl;

    for(auto it: v){
        cout<<it<<" ";
    }

    //deletion in vector
    //syntax: v.erase(position) or v.erase(start_iterator, end_iterator)
    v.erase(v.begin()+1); // Erase the second element (20)
    cout<<"After erasing second element: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    v.erase(v.begin(), v.begin()+2); // Erase first two elements (10 and 30)
    cout<<"After erasing first two elements: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;


    //insert in vector
    //syntax: v.insert(position, value) or v.insert(position, count, value)
    v.insert(v.begin(), 100); // Insert 100 at the beginning
    cout<<"After inserting 100 at the beginning: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    v.insert(v.begin()+1, 3, 200); // Insert three 200s starting from the second position
    cout<<"After inserting three 200s: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    //insert a vector into another vector
    vector<int> v2 = {300, 400, 500};
    v.insert(v.end(), v2.begin(), v2.end()); // Insert all elements of v2 at the end of v
    cout<<"After inserting v2 at the end: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    //size and capacity
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    //pop_back
    v.pop_back(); // Remove the last element (500)
    cout<<"After popping back: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    //swap
    vector<int> v3 = {600, 700, 800};
    v.swap(v3); // Swap contents of v and v3
    cout<<"After swapping with v3: ";
    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Contents of v3 after swap: ";
    for(auto it: v3){
        cout<<it<<" ";
    }
    //clear and empty: 
    v.clear(); // Remove all elements from v
    cout<<"After clearing v, is it empty? "<<(v.empty() ? "Yes" : "No")<<endl;

}
void explainList() {//a doubly linked list implementation in STL
    // 1. Initialization
    list<int> ls;
    ls.push_back(2);    // {2}
    ls.emplace_back(4); // {2, 4}

    // 2. The "Superpower" of List: Fast Front Operations
    // Vector takes O(N) to push_front, List takes O(1)
    ls.push_front(5);    // {5, 2, 4}
    ls.emplace_front(1); // {1, 5, 2, 4}

    // 3. Iteration (Same as vector)
    cout << "List elements: ";
    for (auto it : ls) {
        cout << it << " ";
    }
    cout << endl;

    // 4. Important Differences from Vector:
    // NO Random Access: You cannot do ls[2]. 
    // You MUST use an iterator to move through the list.
    auto it = ls.begin();
    advance(it, 2); // Moves iterator to the 3rd element
    cout << "Third element: " << *it << endl;

    // 5. Other Functions
    // reverse(), sort(), and merge() are built-in for list
    ls.reverse(); // {4, 2, 5, 1}
    ls.sort();    // {1, 2, 4, 5}
    
    ls.pop_front(); // Removes 1
    ls.pop_back();  // Removes 5
}
void explainDeque() {
    // 1. Initialization
    deque<int> dq;
    
    // 2. The "Double-Ended" Power
    dq.push_back(10);     // {10}
    dq.emplace_back(20);  // {10, 20}
    dq.push_front(30);    // {30, 10, 20}
    dq.emplace_front(40); // {40, 30, 10, 20}

    // 3. Random Access (Unlike List, Deque can do this!)
    cout << "Element at index 2: " << dq[2] << endl; // Prints 10

    // 4. Removal
    dq.pop_back();  // {40, 30, 10}
    dq.pop_front(); // {30, 10}

    // 5. Accessing Ends
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;

    // 6. Iteration (Same as Vector)
    cout << "Deque contents: ";
    for (auto it : dq) {
        cout << it << " ";
    }
    cout << endl;

    // 7. Other functions
    // size(), clear(), empty(), begin(), end(), rbegin(), rend()
    // All work exactly like they do in a vector.
}
void explainStack() {
    // 1. Initialization
    stack<int> st;

    // 2. Pushing elements (Only goes to the top)
    st.push(1);    // {1}
    st.push(2);    // {2, 1}
    st.push(3);    // {3, 2, 1}
    st.emplace(4); // {4, 3, 2, 1}

    // 3. Accessing the top element
    // Note: stack[0] or stack.begin() will throw an ERROR. 
    // You can ONLY see the top.
    cout << "Top element: " << st.top() << endl; // Prints 4

    // 4. Removing elements (Only from the top)
    st.pop(); // Removes 4 -> {3, 2, 1}
    cout << "New top: " << st.top() << endl; // Prints 3

    // 5. Size and Empty check
    cout << "Stack size: " << st.size() << endl;   // 3
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;

    // 6. Swapping stacks
    stack<int> st1, st2;
    st1.push(10);
    st2.push(20);
    st1.swap(st2); // st1 now has 20, st2 has 10
}
// --- QUEUE EXPLANATION ---
void explainQueue() {
    cout << "--- Queue Section (FIFO) ---" << endl;
    queue<int> q;

    q.push(10); // {10}
    q.push(20); // {10, 20}
    q.push(30); // {10, 20, 30}

    q.back() += 5; // Changes 30 to 35: {10, 20, 35}
    
    cout << "Front element: " << q.front() << endl; // 10
    cout << "Back element: " << q.back() << endl;   // 35

    q.pop(); // Removes 10: {20, 35}
    cout << "New front: " << q.front() << endl; // 20
    cout << endl;
}
void explainPriorityQueue() {
    // 1. Max-Heap (Default)
    // The largest element stays at the top.
    priority_queue<int> pq;

    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << "Max-Heap Top: " << pq.top() << endl; // Prints 10

    pq.pop(); // Removes 10 -> {8, 5, 2}
    cout << "New Max-Heap Top: " << pq.top() << endl; // Prints 8

    // 2. Min-Heap
    // The smallest element stays at the top.
    // Syntax: priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> min_pq;

    min_pq.push(5);     // {5}
    min_pq.push(2);     // {2, 5}
    min_pq.push(8);     // {2, 5, 8}
    min_pq.emplace(10); // {2, 5, 8, 10}

    cout << "Min-Heap Top: " << min_pq.top() << endl; // Prints 2
}
void explainSet() {  //time complexity of all operations is O(log N) because it is implemented 
    //as a balanced binary search tree (like Red-Black Tree)
    // 1. Initialization
    // By default, it sorts in Ascending order
    set<int> st;

    // 2. Inserting Elements
    st.insert(1);  // {1}
    st.insert(2);  // {1, 2}
    st.insert(2);  // {1, 2} - Note: 2 is not added again (Unique only!)
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4} - Automatically sorted!

    // 3. Finding Elements
    // find() returns an iterator to the element if found, else st.end()
    auto it = st.find(3); 
    
    // 4. Erasing Elements
    st.erase(2); // Deletes the number 2: {1, 3, 4} - O(log N)
    
    // You can also erase via iterator
    auto it_del = st.find(3);
    if(it_del != st.end()) st.erase(it_del); // {1, 4}

    // 5. Counting Elements
    // Since elements are unique, count() only returns 1 (exists) or 0 (doesn't)
    if (st.count(1)) cout << "1 exists!" << endl;

    // 6. Bounds (Very important for competitive programming)
    // lower_bound: points to element >= val
    // upper_bound: points to element > val
    auto lb = st.lower_bound(1);
    auto ub = st.upper_bound(4);

    // 7. Iteration
    cout << "Set contents: ";
    for (auto val : st) {
        cout << val << " ";
    }
    cout << endl;
}
void explainMultiSet() {
    // 1. Initialization
    multiset<int> ms;

    // 2. Inserting Elements (Duplicates are welcome!)
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}
    ms.insert(2); // {1, 1, 1, 2}

    // 3. Counting
    // Unlike set (which returns 0 or 1), multiset returns the actual frequency
    cout << "Count of 1s: " << ms.count(1) << endl; // Prints 3

    // 4. Erasing Elements (CAUTION HERE!)
    // If you pass the VALUE, it deletes ALL occurrences of that value
    ms.erase(1); // All 1s are gone! -> {2}

    // To delete only a SINGLE occurrence, you must pass an ITERATOR
    ms.insert(3);
    ms.insert(3);
    ms.insert(3); // {2, 3, 3, 3}
    
    ms.erase(ms.find(3)); // Only deletes the FIRST '3' it finds -> {2, 3, 3}

    // 5. Clearing a Range
    // Deletes everything from the first '3' to the end
    // ms.erase(ms.find(3), ms.end()); 

    // 6. Bounds
    auto lb = ms.lower_bound(3); // Points to the first '3'
    auto ub = ms.upper_bound(3); // Points to the element after the last '3'
}
void explainUnorderedSet() {
    cout << "--- Unordered Set Section (Unique & Fastest) ---" << endl;
    unordered_set<int> us;
    //does not maintain any order, it is implemented using hash tables, so the order of elements is based on their hash values.
    // Most operations (insert, find, erase) are O(1) average
    //worst case can degrade to O(N) if many elements hash to the same bucket (hash collision), but good hash functions minimize this.
    us.insert(10);
    us.insert(5);
    us.insert(20);
    
    // Order is randomized (based on hash table)
    cout << "Uset (random order): ";
    for (auto i : us) cout << i << " ";
    cout << endl << endl;
}
void explainMap() {
    //map stores unique keys in sorted order (by default in ascending order) and maps them to values. It is implemented as a balanced binary search tree (like Red-Black Tree), so all operations (insert, find, erase) have a time complexity of O(log N).
    // 1. Initialization: map<KeyType, ValueType>
    map<int, string> mpp;

    // 2. Inserting Elements
    mpp[1] = "Raj";          // Method 1: Array-style (most common)
    mpp.emplace(3, "Suman"); // Method 2: emplace
    mpp.insert({2, "Rohan"});// Method 3: insert a pair

    // 3. Map of Complex Keys (e.g., Pair as a Key)
    map<pair<int, int>, int> mpp2;
    mpp2[{2,3}] = 10; // Maps the pair (2,3) to the integer 10

    // 4. Accessing Elements
    cout << "Value at key 1: " << mpp[1] << endl;
    cout << "Value at key 5 (not exists): " << mpp[5] << endl; 
    // Note: Accessing a non-existent key with [] creates it with a default value (0 or "").

    // 5. Iteration
    // Each element is a 'pair'. it->first is the Key, it->second is the Value.
    cout << "Map contents (Sorted by Key):" << endl;
    for (auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 6. Find and Erase
    auto it = mpp.find(3); // Returns iterator to pair {3, "Suman"}
    if (it != mpp.end()) {
        cout << "Found: " << it->second << endl;
    }

    mpp.erase(1); // Erases the pair where key is 1
}
void explainMultimap() {
    // 1. Initialization
    multimap<int, string> mm;

    // 2. Inserting (Must use insert or emplace)
    mm.insert({1, "Raj"});
    mm.insert({1, "Rahul"}); // Both are stored!
    mm.emplace(2, "Suman");

    // 3. Finding and Counting
    cout << "Count of key 1: " << mm.count(1) << endl; // Prints 2

    // 4. Accessing elements
    // Since there are multiple, find() returns an iterator to the first instance
    auto it = mm.find(1);
    
    // To see all values for key 1, we use equal_range
    auto range = mm.equal_range(1);
    cout << "Values for key 1: ";
    for (auto i = range.first; i != range.second; i++) {
        cout << i->second << " ";
    }
    cout << endl;

    // 5. Erasing
    // mm.erase(1); // Deletes ALL entries with key 1
}
void explainUnorderedMap() {
    // 1. Initialization
    unordered_map<int, string> umpp;

    // 2. Performance: O(1) Average
    umpp[1] = "Apple";
    umpp[2] = "Banana";
    umpp[10] = "Cherry";

    // 3. The "Unordered" Part
    // If you print this, keys will appear in random order
    cout << "Unordered Map contents:" << endl;
    for (auto it : umpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 4. Same functions as map
    // find(), count(), size(), empty(), erase()
    // Note: No lower_bound or upper_bound here!
}
int main(){
    explainpair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPriorityQueue();
    explainSet();
    explainMultiSet();
    explainUnorderedSet();
    explainMap();
    explainMultimap();
    explainUnorderedMap();
    return 0;
}