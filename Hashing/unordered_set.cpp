#include <iostream>
#include <unordered_set>
using namespace std;

/*
set is based on red-black tree
unordered set is based on hashing

In hashtable elements are stored in any particular order
hence op for below prog will be different for different compilers

Time complexity:
insert(), erase(), count(), find(), size(), empty() is O(1) on average

Applications of unordered set:
we need foll operations in efficient time:
- search
- insert
- delete

unordered set only works on keys
if you have key-value pairs then use unordered-map
*/

int main()
{
    unordered_set<int> us;
    us.insert(10);
    us.insert(5);
    us.insert(15);
    us.insert(20);

    for (int x : us)
        cout << x << " ";

    cout << "\n"
         << us.size();

    // useful if there are multiple testcases
    // us.clear();
    // cout << "\n" << us.size();

    /*
    finding an element in unordered_set using find()
    find() returns an iterator to el if el is present
    else if not present it returns s.end()
    */

    if (us.find(15) == us.end())
        cout << "\nNot found";
    else
        cout << "\nFound " << *(us.find(15));

    /*
    count() function return count no of ocuurences
    it is a boolean substitute for find func in unordered set
    i.e return 1 if el is present
    else returns 0 if el is absent

    the max value will always be 1 since it is a set
    */

    if (us.count(15))
        cout << "\nMil gaya";
    else
        cout << "\nNahi mila";

    /*
    erase() function is used to remove a item or range of items
    */
    us.erase(15);
    if (us.count(15))
        cout << "\nMil gaya";
    else
        cout << "\nNahi mila";

    
    us.erase(us.begin(), us.end());

    return 0;
}