# Intro to trees

-  used to represent hierarchies, eg: any org structure, folder structure, 
- Tree is a non-linear DS (ofc lol) since items are stored in hirarchical manner whereas in linear DS, items are stored in sequential manner 
- **Root**: Topmost Node in hierarchy 
- **Leaf**: Node having no child or nodes having degree 0 
- Tree data structure is recursive in nature i.e the left child of root is also a tree, similarly the right child of root is also a tree, these trees are called **sub-trees** 
- **Descendants** of a node are all the nodes that lie in sub-tree with this particular node as root
- **Degree** of node is no of children of that node
- **Internal nodes** are nodes which do not have degree 0 or are not leaf nodes 
- The root is an internal node, except in the special case of a tree that consists of just one node (and no edges)

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

# Binary Tree

- a tree in which every node has at most two children or degree of a node can be at-most two
- a node of a binary tree consists of data and reference for left and right node 
- why we tree mostly BST and not n-ary tree: segment trees, binary heap use binary tree
- [representation of binary tree](basics.java)

# Tree traversals

Why do we need tree traversals?
- for searching
- for finding size, or counting no of nodes

Popular traversals:
- BFS or level order traversal
- DFS
    - [Inorder](inorder.java) (LNR - left node right)
        - dry run | theory of code
    - [Pre-order](preorder.java) (NLR - node left right)
        - dry run | theory of code
    - [Post-order](postorder.java) (LRN - left right node)

- [Height of Binary tree](binary_tree_height.java)
- [Print Nodes at distance K](printKthNode/)
- [Level order traversal](Level_order_traversal/)
- [Size of a binary tree](binary_tree_size.cpp)
    - [dry run TBA]

- [Maximum value in a binary tree](Maximum_of_a_binary_tree/)

- [Print left view of binary tree](Left_view_of_binary_tree/)

- [Children sum property](Children_sum_property/main.cpp)

- [Width of binary tree](Width/main.cpp)