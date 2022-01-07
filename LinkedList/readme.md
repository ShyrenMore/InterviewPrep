## Problems of arr/ Need of Linked List

- Elements don't have to be in contigous memory locations in LinkedList but in stack they have to
- worst case insertion at end is θ(n) 
- Insertion in the middle (or beginning) is costly
- Deletion from the middle (or beginning) is costly
- Implementation of data struct. like queue and deque is complex with arrays
- Implementation of round robin scheduling is much less complex and cost-friendly with circular LL rather than arrays, since we will need to re-size our list of processes and also perform insertion at the end of list
- basically any problem where insertion at middle/end is performed more no of times, LL is better suited for them

## Questions on Singly LL

- [Linked List implementation](Singly_Linked_List/LL_basic)
    - Why do LL have self-referential struct? <br>
        every node needs to have addr of next node, and datatype of next node is same as the current node
- [LL Traversal](Singly_Linked_List/LL_traversal)
- [Insert at beginning of Singly LL](Singly_Linked_List/insert_at_begin.java)
- [Insert at end (tail) of Singly LL](Singly_Linked_List/insert_at_end.java)
- [Delete first node(head) in Singly LL](Singly_Linked_List/delete_first_node.java)
- [Delete last node(tail) in Singly LL](Singly_Linked_List/delete_last_node.java)
- [Insert at given position in Singly LL](Singly_Linked_List/insert_node.java)
- [Search in a LL(iterative & recursive)](Singly_Linked_List/SearchNode.java)
    - we can't do binary search in logn time on LL, since we can't find middle node in O(1) time

## Doubly LL

- in doubly LL, we have ref to prev and next node 
- in struct/class node, a new attr will be added

```
class Node{
    int data;
    Node prev;
    Node next;

    Node(int d){
        data = d;

        // optional lines
        prev = null;
        next = null;
    }
}
```

- [Doubly Linked List implementation](Doubly_Linked_List/LL_basic.java)

### Advantages of Doubly LL over Singly LL:
- can be traversed in both directions
- delete a node in O(1) time with given ref/ptr to it
- insert/delete *before* a given node
- insert/delete from both ends in O(1) time by maintaining tail

### Disadvantages of Doubly LL over Singly LL:
- Extra space for prev
- Code becomes more complex

### Problems on DLL

- [Insert at head of DLL](Doubly_Linked_List/InsertAtHead.java)
- [Insert at tail of DLL](Doubly_Linked_List/InsertAtTail.java)
- [Reverse a DLL](Doubly_Linked_List/Reverse.java)
    - find dry run img [here](imgs/)
- [Delete head of DLL](Doubly_Linked_List/DeleteHead.java)
- [Delete tail of DLL](Doubly_Linked_List/DeleteTail.java)