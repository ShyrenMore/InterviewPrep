#include <iostream>
#include <unordered_map>
using namespace std;

/*
map is based on red-black tree
unordered map is based on hashing

map stores keys in ordered form
in unordered map there is no order of keys

with map serach, insert, delete is O(logn)
with unordred map, it is O(1)

[] is member access operator in maps
syntax: m[key] = value
if key present the [] operator gives reference for the value
else if not present, it inserts the key

Time complexity:
insert(), erase(key), count(), find(), [], at, is O(1) on average
*/

void example1()
{
    unordered_map<string, int> m;

    // defining a key gfg and assigning a value of 20
    m["gfg"] = 20;
    m["ide"] = 30;

    // another of inserting a key-value pair 
    m.insert({"courses", 15});

    for(auto x: m)
        cout << x.first << " " << x.second << "\n";

    /*
    op:
    gfg 20
    courses 15
    ide 30

    Notice the random order in which pairs were inserted 
    */
}

void isPresentExample()
{
    unordered_map<string, int> m;

    m["gfg"] = 20;
    m["ide"] = 30;
    m["courses"] = 15;

    if(m.find("ide") != m.end())
        cout << "\nFound";
    else
        cout << "\nNot found";

    // or 

    if(m.count("ide") > 0)
        cout << "Found";
    else
        cout << "Not found";

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << "\n";

    // m.size() returns no of key value pair
    // m.erase("ide") removes key value pair 
}

int main()
{
    example1();
    isPresentExample();
    return 0;
}