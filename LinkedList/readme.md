## Problems of arr/ Need of Linked List

- Elements don't have to be in contigous memory locations in LinkedList but in stack they have to
- worst case insertion at end is θ(n) 
- Insertion in the middle (or beginning) is costly
- Deletion from the middle (or beginning) is costly
- Implementation of data struct. like queue and deque is complex with arrays
- Implementation of round robin scheduling is much less complex and cost-friendly with circular LL rather than arrays, since we will need to re-size our list of processes and also perform insertion at the end of list
- basically any problem where insertion at middle/end is performed more no of times, LL is better suited for them

## Questions on LL

- [Linked List implementation](1_LL_basic.cpp)
    - Why do LL have self-referential struct? <br>
        every node needs to have addr of next node, and datatype of next node is same as the current node
- [LL Traversal](2_LL_traversal.cpp)
- [Insert at beginning of Singly LL](insert_at_begin.java)
- [Insert at end of Singly LL](insert_at_end.java)
- [Delete first node in Singly LL](delete_first_node.java)