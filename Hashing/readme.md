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