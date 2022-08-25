# Intro

- well suited DS for implementing dictionaries 

**Efficient for foll operations**
- search, insert, delete
- prefix search: finding out words that begin with specific prefix
- lexicographical ordering of words

# Comparison of trie and hashing 

Parameter | Trie | Hashing
------- | :----------------: | :----------------: |
Search | θ(word_len) in worst case | θ(word_len) on avg
Insert and delete | θ(word_len) in worst case | θ(word_len) on avg
Prefix supported | θ(prefix_len + output_len) | Not supported
lexicographical ordering | θ(output_len) | Not supported

# Structure of Trie

```
Trie has an array of size 26
where 0 : a, 1 : b upto z : 25

and a flag variable
```

# Problems

- [Implement Trie | Insert | Search | Prefix/Startswith](trie.cpp)
    - diagram
- [Implement Trie-2 | INSERT | countWordsEqualTo() | countWordsStartingWith() | Leetcode premium](trie2.cpp)
- [Longest String with All Prefixes | Leetcode premium](Longest_str.cpp)
    - diagram
- [Number of Distinct Substrings in a String | Leetcode premium](count_distinct_substr.cpp)

**Bit Requisites**
- In tries, we store binary nos in 32 bits (int format)
- so 9 will be represented as ``00000..1001`` rather than just ``1001``
- `XOR` of same bits is 0 and different bits is 1
- for checking if `kth bit is set or not` 
    - right shift n by k i.e n>>k i.e bring kth bit to unit place position 
    - do and with 1 i.e ``(n>>k) & 1``
    - if res is 1, then kth bit is set else not set
- `flip kth bit` from right
    - take another 1 and left shift it by k places i.e `1 << k`
    - perform or operation with num i.e `n | (1 << k)`

- [Maximum XOR](max_xor.cpp)
