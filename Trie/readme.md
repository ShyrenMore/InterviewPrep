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
- [Implement Trie-2 | INSERT | countWordsEqualTo() | countWordsStartingWith()](trie2.cpp)