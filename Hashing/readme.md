# Hashing: 
- used to implement dictionaries (key-value pairs)
- used to implement sets (only keys)

### Search, insert, del in O(1) time on avg

eg: Phone no book

### All nos in hashtable are unique
If u insert an existing key, it will overwrite the prev key 

### Not to be used if you are asked 
- closest value // AVL or redblack tree
- sorted order data // AVL or redblack tree
- prefix searching (finding key that match with a prefix) // Trie

### Hashing is strict search 

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

- In case of range 1000-1999

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
- large keys
- floating point nos as an index
- keys that are strings

# Idea of hashing

Take a large universe of keys, eg phone nos, names, emp_ids (E1021)
use hash function that does some black magic for converting large keys into small values that can be used as an index for hashtable

- Hashtable: array that has indexes 0 to m-1
- Hash functions: 

## How Hash function do the black magic?

### Some necessary requirements for hashtable
- Every time you use the key for the hash function, it should generate same idx 
- generate values from 0 to m-1, m is size of hash table
- should be fast, O(1) for int and O(len) for string of length 'len'
- Should uniformly distribute the input keys (practically impossible)

### Sample hash functions

1) h(large_int_key) = large_int_key % m
2) For strings, weighted sum
```
str[] = "abcd"
(str[0]*x^0 + str[1]*x^1 + str[2]*x^2 + str[3]*x^3)%m 
```
3) Universal Hashing
Group of hash functions, randomly pick a hash function and use it to hash all the data in the hash table


### Collision: Two distinct large keys when given to a hash function, convert to same small key

### Typically m is chosen as prime no which are not close to powers of 2 or 10
### bad value of m will be power of 2 or 10 for simple hash