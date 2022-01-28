/**
 * 
 * Method 1: 
 * 
 * Idea is to reverse the LL after head
 * we call reverse function for head.next till tail 
 * that will reverse the link in that part, let's call that part sub-linked list 
 *  
 * that reverse function will return last node of that sub-linked list as its head
 * so main challenge would be creating a link b/w head and tail of sub-linked list when we only have access of sub-linked list head 
 * 
 * So basically we are recursively reversing the last n-1 nodes
 * 
 * Method 2:
 * 
 * Traverse LL from left to right 
 * then reverse the first x nodes 
 * when we are at curr node, we will mark it's prev node as prev, and then we point curr.next to prev
 * for next time, curr will be our prev
 */

class Node {
    int data;
    Node next;

    Node(int x)
    {
        data = x;
        next = null;
    }
}

public class reverseSLL_recursive {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        printList(head);
        // head = reverseList(head);
        head = reverseListtwo(head, null);
        printList(head);
    }

    public static Node reverseList(Node head) {

        if (head == null)
            return null;

        if (head.next == null)
            return head;

        Node subLLhead = reverseList(head.next);
        Node subLLtail = head.next;
        subLLtail.next = head;
        head.next = null;
        return subLLhead;
    }
    
    public static Node reverseListtwo(Node curr, Node prev) {

        if (curr == null)
            return prev;

        Node next = curr.next;
        curr.next = prev;
        return reverseListtwo(next, curr);
    }
    
    public static void printList(Node head) {
        Node traverse = head;
        while (traverse != null) {
            System.out.print(traverse.data + "->");
            traverse = traverse.next;
        }
        System.out.print("null\n");
    }
}
