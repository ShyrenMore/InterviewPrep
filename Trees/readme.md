# Intro to trees

-  used to represent hierarchies, eg: any org structure, folder structure, 
- Tree is a non-linear DS (ofc lol) since items are stored in hirarchical manner whereas in linear DS, items are stored in sequential manner 
- **Root**: Topmost Node in hierarchy 
- **Leaf**: Node having no child or nodes having degree 0 
- Tree data structure is recursive in nature i.e the left child of root is also a tree, similarly the right child of root is also a tree, these trees are called **sub-trees** 
- **Descendants** of a node are all the nodes that lie in sub-tree with this particular node as root
- **Degree** of node is no of children of that node
- **Internal nodes** are nodes which do not have degree 0 or are not leaf nodes 

# Application of Tree 
- to represent hierarchical data 
    - org structure 
    - folder structure
    - XML/HTML content (JSON objects): you have HTML tag at the top then it's children are body and head and they have their own children
    - In OOP (Inheritance): we have base class and their children class
- Binary Search Tree
- Binary Heap: used to represent priority queues, priority queues are useful in Djiktra's algo, Prim's algo
- B and B+ trees in DBMS: B and B+ trees are used in DB for indexing, the other alternative to implement indexing is hashing 
- Spanning and shortest path trees in Computer Networks: 
    - Bridges uses spanning trees to forward the packets 
    - Routers uses shortest path trees for routing data 
- Parse tree, expression tree in compilers to parse source codes
- Variations of Tree
    - Trie: used to represent dictionaries, supports operations like prefix search 
    - suffix tree: used to do fast pattern searches in a string 
    - Binary Index Tree: used for range query searches, faster for limited set of operations
    - Segment Tree: used for range query searches, comparatively more powerful than Binary Index Tree 
