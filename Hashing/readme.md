# Hashing: 
- used to implement dictionaries (key-value pairs)
- used to implement sets (only keys)

- **Search, insert, del in O(1) time on avg**  <br>
eg: Phone no book

- **All nos in hashtable are unique** <br>
If u insert an existing key, it will overwrite the prev key 

- **Hashing is strict search i.e it cannot find(lookup) closest value in ```O(1)``` time** 

### Not to be used if you are asked 
- closest value // AVL or redblack tree
    - finding a key which is just above or below the given key in logn time 
- sorted order data // AVL or redblack tree
- prefix searching (finding key that match with a prefix) // Trie


## Applications
- Dictionaries
- Database indexing
- Crypto
- Caches eg: browser data, urls become key and data becomes values
- Symbol tables in compilers/interpreters
- routers (mapping of IP/MAC address)
- Getting data from databases (associative arrays)

## Direct address table
Imagine a situation where you have 1000 keys with values from (0 to 999), how would you implement following in O(1) time
- search
- insert
- delete 

eg: 
- insert(10)
- insert(20)
- insert(119)
- search(10) // op: true
- search(20) // op: true
- delete(119)
- search(119) // op: false

```
Initialise a bool array of size 1000 with 0
For insert(10), mark arr[10] = 1
For insert(20), mark arr[20] = 1
For insert(119), mark arr[119] = 1
For search(10), lookup arr[10] => if(arr[10])
For search(20), lookup arr[20] => if(arr[20])
For delete(119), mark arr[119] = 0
For search(119), lookup arr[119] => if(arr[119])
```

## Sample function

- In case of range 0-999

```

delete(i){                  insert(i){
    table[i] = 0                table[i] = 1
}                           }

search(i){
    return table[i];
}

```

- In case keys are in range 1000-1999

```

delete(i){                  insert(i){
    table[i-1000] = 0                table[i-1000] = 1
}                           }

search(i){
    return table[i-1000];
}

```

- In case of range a-z, consider ascii values
Array will be of size 26
```

delete(i){                  insert(i){
    table[i-'a'] = 0                table[i-'a'] = 1
}                           }

search(i){
    return table[i-'a'];
}

```

## Problems with Direct index table cannot handle
- large keys (10^10 like phone nos)
- floating point nos as an index (10.97 as an index)
- keys that are strings (index is gfg)

# Idea of hashing

Take a large universe of keys, eg phone nos, names, emp_ids (eg: E1021) <br>
use hash function that does some black magic for converting large keys into small values that can be used as an index for hashtable

- Hashtable: array that has indexes 0 to m-1
- Hash functions: functions that transform large keys into small values 

## How Hash function do the black magic?

### Some necessary requirements for hash function
- Every time you use the key for the hash function, it should generate same idx 
- should generate values from 0 to m-1, m is size of hash table
- should be fast, O(1) for int and O(len) for string of length 'len'
- Should uniformly distribute the input keys into hash table slots (practically impossible)

### Sample hash functions

```
1) h(large_int_key) = large_int_key % m
eg: phone nos, m is hash table size which depends on no of keys that you are going to insert
hence, hash function will be phone_no % m
but there will be many phone nos which after modulo will result in same hash value (collision)

2) Hash function for strings, weighted sum
str[] = "abcd"
hash_func = (str[0]*x^0 + str[1]*x^1 + str[2]*x^2 + str[3]*x^3) % m 

3) Universal Hashing
Group of hash functions, randomly pick a hash function and use it to hash all the data in the hash table
```


**Collision:** Two distinct large keys when given to a hash function, convert to same small key 

**Typically m is chosen as prime (less common factors) no which are not close to powers of 2 or 10** 
**bad value of m will be power of 2 or 10 for simple hash**
- eg m = 10^3, here we are considering only last 3 digits of a number, we are ignoring the other 7 nos 
- for power of 2, there is a possibility of considering only some bits of binary representation 

# Collision Handling 

- If we know keys in advance, then we can do **Perfect Hashing**
- else if we do not know keys, then we use
    - Chaning
    - Open Addressing
        - Linear Probing
        - Quadratic Probing
        - Double Hashing

## Chaining

- Hashtable will be an array of of Linked List Headers
- Whenever a collision happens, insert the item at the end of LL 
- eg
```
hash func = h(key) = key % 7
keys to be inserted: 50, 21, 58, 17, 15, 49, 56, 22, 23, 25
```

- Vertical representation of array (hashtable) after inserting keys 

```
idx | LL
0   | 21 -> 49 -> 56
1   | 50 -> 15 -> 22
2   | 58 -> 23
3   | 17
4   | 25
5   |
6   |
```

### Performance of Chaning
- m: no of slots Hash table
- n: no of keys to be inserted 
- **Load factor = n/m**
- Most library func in C++/Java provide an option to specify load factor 
- Small hash table results in big load factor, more likely to have more collisions  
- viceversa big hash table will result in low load factor thereby having less no of collisions 
- Hence, there will be a trade-off b/w space and no of collisions 

**Expected chain length**: 
- Worst case will be all keys go to same index, O(no of keys) will be chain length
- We don't know average case scenario, so we make an assumption keys will be uniformly distributed 
- hence chain length in this case will be load factor 

**Expected time to search/insert/delete** = ``O(1+load factor)``

**Data strcuture to store chain**
- Linked List: Search/Del/insert will be O(len), not cache friendly, not space optimised
- Dynamic arrays: Search/Del/insert will be O(len), cache friendly
- Self balancing BST (AVL tree, red black tree): Search/Del/insert will be O(log(len))

### Implementation of Chaning using LL

```
struct MyHash
{
    int hashTableSize;
    // list is a doubly linked list
    list <int> *table;

    MyHash(int sz)
    {
        hashTableSize = sz;
        table = new list<int> [sz];
    }

    void insertKey(int key)
    {
        int idx = key % hashTableSize;
        table[idx].push_back(key);
    }

    bool search(int key)
    {
        int idx = key % hashTableSize;
        // traverse the specific linked list

        for(auto x : table[i])
            if (x == key)
                return true;
        return false;
    }

    void removeKey(int key)
    {
        int idx = key % hashTableSize;
        table[idx].remove(key);
    }
};
```

## Open Addressing

- use single array without any chains 
- one requirement for open addr
```
No of slots (m) >= No of keys to be inserted (n)
```
- more cache friendly than Chaining 

- eg
```
hash func = h(key) = key % 7
keys to be inserted: 50, 51, 49, 16, 56, 15, 19
```

- Vertical representation of array (hashtable) after inserting keys using **Linear Probing** i.e in case of collision search for the next empty slot present linearly 

```
idx | value
0   | 49
1   | 50 
2   | 51 
3   | 16
4   | 56
5   | 15
6   | 19
```

- If a key maps to last slot and last slot is occupied, search in a circular manner  
- **for searching** a key, find hash_func again, 
if found, great, 
    else stop till
      - go to next slot till key found 
      - stop if empty slot found 
      - if after traversing entire table, key still not found  

- **for deletion**, find hash func value viz idx, start searching, when u delete the slot, mark it as deleted so search function can work properly 
- search function will now continue searching if slot is marked deleted, and stops when either element is found or empty slot is encountered 

### Problem of clustering in Open Addressing due to linear probing 

- Since chaining is not allowed, keys having same hash func value will keep on piling one after the other thus making search, insert and delete operations costly 
- To handle this, we 

```
h(key) = key % m
hash(key, i) =  (h(key) + i) % m
```

```
Quadratic probing results in Secondary clusters
h(key) = key % m
hash(key, i) =  (h(key) + i*i) % m

```

### Double hashing 

```
Double Hashing
h(key) = key % m
hash(key, i) =  (h1(key) + i*h2(key)) % m
i = ith collision
```

- In double hashing we use two hash functions 
    - one is simple hash
    - the other is to find next slot 

- If h2(key) is relatively prime to m, then it always find a free slot 
- No clustering 
- Distributes keys uniformly than linear and quadraric probing 
- h2(key) should never return 0 for any value
- **Algorithm**

```
void doubleHashingInsert(int key)
{
    if(TableFull)
        return error
    
    probe = h1(key)
    offset = h2(key)

    // whenver there is coll, add offset to idx
    while(table[probe] is occupied)
        probe = (probe + offset) % m

    table[probe] = key;
}
```

Chaining | Open Addressing |
------------- | :----------------: |
Hash Table never fills |  Table may become full and resizing becomes mandatory
Less sensitive to Hash functions |  Extra care required for clustering
Not cache friendly | Cache friendly
Extra space for links | Extra space might be needed to achieve same performance as chaining

# Problems based on Hashing concept 

- [unordered_set](unordered_set.cpp)
- [unordered_map](unordered_map.cpp)
- [Count distinct elements](count_distinct_els.cpp)
- [Frequency of arr elements](freq.cpp)
- [Count Distinct els of Intersection of two arrays](intersection_hashing.cpp)
- [Count Distinct els of union of two arrays](union_hashing.cpp)
- [Pair with given sum in an unsorted array (Two Sum problem)](pair_sum.cpp)
- [Check if subarray has zero sum](subarray_zero_sum.cpp)
    - **hashing + prefix sum go brr**
- [Check if subarray has given sum](subarray_given_sum.cpp)
    - generalised problem of zero sum subarray

- [Length of Longest subarray with given sum](longest_subarray_given_sum.cpp)
    - **need to see video definitely** 

- [Length of Longest subarray with equal no of 0s and 1s](longest_subarray_equal0s1s.cpp)
    - **most asked interview question**

- [Longest common span with same sum in two binary arrays](longest_span_with_sameSum_in_binary_arr.cpp)
- [Longest *consecutive* subsequence](longest_CONSECUTIVE_subsequence.cpp)
- [Count Distinct Elements in Every Window](distinct_el_in_window.cpp)
- [More than n/k Occurences](n_k_occurences.cpp)
- [First Unique Char in a string](first_unique_char.cpp)