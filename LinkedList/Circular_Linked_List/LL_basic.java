class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

// create a circular LL
/**
 * 10 -> 5 -> 20 -> 15
 * |                 |
 *  ------------------ 
 * 
 */

public class LL_basic {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(5);
        head.next.next = new Node(20);
        head.next.next.next = new Node(15);
        head.next.next.next.next = head;

        // creating a single node CLL
        Node head2 = new Node(10);
        head2.next = head2;
    }
}
