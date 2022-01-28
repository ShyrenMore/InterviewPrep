/**
 * ip:
 * 10 -> 15 -> 5 -> 20
 *        ^          |
 *        |----------|
 * op: 10 -> 15 -> 5 -> 20
 * 
 * ip: 10 -> 15 -> 5
 * op: 10 -> 15 -> 5
 * 
 * Approach: 
 * 1) detect loop using Floyds algo
 * 2) Move slow ptr to beginning of LL and keep fastptr  to meeting point (meeting point is point where slowptr & fastptr point to same node)
 * 3) Now move both slowptr and fastptr by 1 node(at same speed)
 * The point where they meet now is the first node of the loop
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
public class detectandremove {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(15);
        head.next.next = new Node(5);
        head.next.next.next = new Node(20);
        head.next.next.next.next = head.next;

        detectAndRemoveLoop(head);
        printList(head);
    }
    
    public static void detectAndRemoveLoop(Node head) {
        Node slowptr = head, fastptr = head;

        // loop detection
        while (fastptr != null && fastptr.next != null) {
            slowptr = slowptr.next;
            fastptr = fastptr.next.next;

            if (slowptr == fastptr)
                break;
        }

        // no loop
        if (slowptr != fastptr)
            return;

        // loop removal
        slowptr = head;
        // NOTE: we are comparing next's nodes 
        // since we want to get hold of lastnode 
        while (slowptr.next != fastptr.next) {
            slowptr = slowptr.next;
            fastptr = fastptr.next;
        }

        fastptr.next = null;
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
